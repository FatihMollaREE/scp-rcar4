/*
*
* License
*
*/

#include <rcar4_irq.h>
#include <cmsis_gcc.h>

#include <stdbool.h>
#include <fwk_arch.h>
#include <fwk_interrupt.h>
#include <fwk_macros.h>
#include <fwk_mm.h>
#include <fwk_mmio.h>
#include <fwk_status.h>

#include <arch_gic.h>
#include <gic.h>

/* FATIH: tmp defines? */
#define C_INT_ID (INT_ID(c_interrupt))
#ifndef RCAR4_SCMI_LIB
#    define RCAR4_MFIS_MIN U(256)
#    define RCAR4_MFIS_NO U(8)
#    define RCAR4_MFIS_MAX (RCAR4_MFIS_MIN + RCAR4_MFIS_NO)
#    define IS_SUPPORT_INT(n) (n) // fatih tmp akzeptiere ich hier alle interrupts einfach
#    define EFECTIVE_NO(n) (n - RCAR4_MFIS_MIN)
#else
#    define IS_SUPPORT_INT(n) ((n >= SMCMH_IRQ_START) && (n < SMCMH_IRQ_END))
#    define EFECTIVE_NO(n) (n & 0xff)
#endif /* RCAR4_SCMI_LIB */
#define CHECK_BIT(d, b) ((d >> b) & 1)
#define IID_LEN (10)


/* Prototypes: */
void gic_cpuif_enable(void);

// fatih : weiß nicht ob das so passt
__STATIC_FORCEINLINE void __enable_fault_irq(void)
{
    __asm__ volatile (
        "MRS R0, CPSR\n"        // CPSR-Register in R0 speichern
        "BIC R0, R0, #0xC0\n"   // IRQ (I-Bit) und FIQ (F-Bit) löschen (Interrupts aktivieren)
        "MSR CPSR_c, R0\n"      // Zurückschreiben ins CPSR-Register
        ::: "r0", "memory"
    );
}

/**
  \brief   Disable FIQ
  \details Disables FIQ interrupts by setting special-purpose register FAULTMASK.
           Can only be executed in Privileged modes.
 */
__STATIC_FORCEINLINE void __disable_fault_irq(void)
{// fatih : weiß nicht ob das so passt
    __asm__ volatile (
        "MRS R0, CPSR\n"        // CPSR-Register in R0 speichern
        "ORR R0, R0, #0xC0\n"   // IRQ (I-Bit) und FIQ (F-Bit) setzen (Interrupts deaktivieren)
        "MSR CPSR_c, R0\n"      // Zurückschreiben ins CPSR-Register
        ::: "r0", "memory"
    );
}

/*
 * For interrupts with parameters, their entry in the vector table points to a
 * global handler that calls a registered function in the callback table with a
 * corresponding parameter. Entries in the vector table for interrupts without
 * parameters point directly to the handler functions.
 */
struct callback {
    union {
        void (*func)(uintptr_t param);
        void (*funcn)(void);
    };
    uintptr_t param;
};

struct r_node {
    int valid;
    struct r_node *left;
    struct r_node *right;
    struct callback *entry;
};

struct r_tree {
    struct r_node *root;
    int _allocated;
};

static unsigned int c_interrupt;
static struct r_tree *radix;


struct r_tree *init_entry(struct r_tree *rt)
{
    if (NULL == rt) {
        rt = fwk_mm_calloc(1, sizeof(struct r_tree));
        if (NULL == rt) {
            return NULL;
        }
        rt->_allocated = 1;
    } else {
        rt->_allocated = 0;
    }
    rt->root = NULL;

    return rt;
}

static void *_lookup(
    struct r_node *cur,
    struct r_node *cand,
    uint32_t iid,
    int bitno)
{
    if (NULL == cur) {
        return NULL != cand ? cand->entry : NULL;
    }

    if (cur->valid) {
        cand = cur;
    }

    if (CHECK_BIT(iid, bitno)) {
        return _lookup(cur->right, cand, iid, bitno + 1);
    } else {
        return _lookup(cur->left, cand, iid, bitno + 1);
    }
}

static void *lookup_entry(struct r_tree *rt, uint32_t iid)
{
    return _lookup(rt->root, NULL, iid, 0);
}

void irq_global(uint32_t iid)
{
    struct callback *entry;

    c_interrupt = iid;

    entry = (struct callback *)lookup_entry(radix, iid);
    if (entry != NULL) {
        if (entry->func) {
            /* Available callback Function */
            if (entry->param) {
                entry->func(entry->param);
            } else {
                entry->funcn();
            }
        }
    } else {
        /* No interrupt entry */
    }
    c_interrupt = 0;
}

// gic.h ersetzt diese
#if 0
static void gicd_set_ipriorityr(
    uintptr_t base,
    unsigned int id,
    unsigned int pri)
{
    uint8_t val = (uint8_t)(pri & GIC_PRI_MASK);

    fwk_mmio_write_8(base + GICD_IPRIORITYR + id, val);
}
static void gicd_write_isenabler(
    uintptr_t base,
    unsigned int id,
    unsigned int val)
    {
        unsigned int n = id >> ISENABLER_SHIFT;
        
        fwk_mmio_write_32(base + GICD_ISENABLER + (n << 2), val);
    }
    
    static void gicd_set_isenabler(uintptr_t base, unsigned int id)
    {
        unsigned int bit_num = id & ((1U << ISENABLER_SHIFT) - 1U);
        
        gicd_write_isenabler(base, id, (1U << bit_num));
        }
        
        static void gicd_ctlr_enable(){
            
        unsigned int val;
        val = 0x53;
        fwk_mmio_write_32(RCAR4_GICD_BASE, val);
        }
    
    static void gicc_write_ctlr(uintptr_t base, unsigned int val)
    {
        // Fatih: check GICC_CTLR nach Korrektheit
        fwk_mmio_write_32(base + GICC_CTLR, val);
    }

    void gic_cpuif_enable(void)
{
    unsigned int val;

    /*
     * Enable the Group 0 interrupts, FIQEn and disable Group 0/1
     * bypass.
     */
    //val = CTLR_ENABLE_G0_BIT | FIQ_EN_BIT | FIQ_BYP_DIS_GRP0;
    //val |= IRQ_BYP_DIS_GRP0 | FIQ_BYP_DIS_GRP1 | IRQ_BYP_DIS_GRP1;

    val = 0x53; // erscheint mir so erstmal als sinnvoll
    /* Program the idle priority in the PMR */
    //gicc_write_pmr(RCAR4_GICC_BASE, GIC_PRI_MASK); // so wie ich das sehe, gibt es beim cr-52 kein gicc (*vllt ist der intc der ersatz?*) also muss man auch nicht die priority mask beschreiben
    gicc_write_ctlr(RCAR4_GICC_BASE, val);
}

static unsigned int gicd_read_isenabler(uintptr_t base, unsigned int id)
{
    unsigned int n = id >> ISENABLER_SHIFT;

    return fwk_mmio_read_32(base + GICD_ISENABLER + (n << 2));
}

static unsigned int gicd_get_isenabler(uintptr_t base, unsigned int id)
{
    unsigned int bit_num = id & ((1U << ISENABLER_SHIFT) - 1U);

    return ((gicd_read_isenabler(base, id) >> bit_num) & 1U);
}

static void gicd_write_icenabler(
    uintptr_t base,
    unsigned int id,
    unsigned int val)
{
    unsigned int n = id >> ICENABLER_SHIFT;

    fwk_mmio_write_32(base + GICD_ICENABLER + (n << 2), val);
}

static void gicd_set_icenabler(uintptr_t base, unsigned int id)
{
    unsigned int bit_num = id & ((1U << ICENABLER_SHIFT) - 1U);

    gicd_write_icenabler(base, id, (1U << bit_num));
}

static unsigned int gicd_read_ispendr(uintptr_t base, unsigned int id)
{
    unsigned int n = id >> ISPENDR_SHIFT;

    return fwk_mmio_read_32(base + GICD_ISPENDR + (n << 2));
}

static void gicd_write_ispendr(
    uintptr_t base,
    unsigned int id,
    unsigned int val)
{
    unsigned int n = id >> ISPENDR_SHIFT;

    fwk_mmio_write_32(base + GICD_ISPENDR + (n << 2), val);
}

static void gicd_write_icpendr(
    uintptr_t base,
    unsigned int id,
    unsigned int val)
{
    //unsigned int n = id >> ICPENDR_SHIFT;
// fatih dummy
    //fwk_mmio_write_32(base + GICD_ICPENDR + (n << 2), val);
}

#endif

void gic_init(void)
{
    Interrupt_Config();
    /*
    gicd_set_ipriorityr(
        RCAR4_GICD_BASE,
        (unsigned int)VIRTUAL_TIMER_IRQ,
        GIC_HIGHEST_SEC_PRIORITY);
        gicd_set_isenabler(RCAR4_GICD_BASE, (unsigned int)VIRTUAL_TIMER_IRQ);
        gicd_set_ipriorityr(
            RCAR4_GICD_BASE,
            (unsigned int)NS_PHYSICAL_TIMER_IRQ,
            GIC_HIGHEST_SEC_PRIORITY);
            gicd_set_isenabler(RCAR4_GICD_BASE, (unsigned int)NS_PHYSICAL_TIMER_IRQ);
            //gic_cpuif_enable();
    gicd_ctlr_enable();
    */
}

/*
static void gicc_write_pmr(uintptr_t base, unsigned int val)
{
    // Fatih: check GICC_PMR nach Korrektheit
    fwk_mmio_write_32(base + GICC_PMR, val); 
}
*/



static int is_pending(unsigned int interrupt, bool *pending)
{
    //unsigned int bit;

    if (!IS_SUPPORT_INT(interrupt))
        return FWK_E_PARAM;

    //bit = interrupt % 32;
   /* fatih tmp dummy
    *pending =
        ((gicd_read_ispendr(RCAR4_GICD_BASE, interrupt) & (1 << bit)) ? true :
                                                                       false);
    */
    return FWK_SUCCESS;
}

static int set_pending(unsigned int interrupt)
{
    //unsigned int bit;

    if (!IS_SUPPORT_INT(interrupt))
        return FWK_E_PARAM;

    //bit = interrupt % 32;
    /* fatih tmp dummy
    gicd_write_ispendr(RCAR4_GICD_BASE, interrupt, 1U << bit);
*/
    return FWK_SUCCESS;
}

static int _add(
    struct r_node **cur,
    uint32_t iid,
    void *entry,
    int bitsize,
    int bitno)
{
    struct r_node *new;

    if (NULL == *cur) {
        new = fwk_mm_calloc(1, sizeof(struct r_node));
        if (NULL == new) {
            return -1;
        }
        memset(new, 0, sizeof(struct r_node));
        *cur = new;
    }

    if (bitsize == bitno) {
        if ((*cur)->valid) {
            return -1;
        }
        (*cur)->valid = 1;
        (*cur)->entry = entry;
        return 0;
    } else {
        if (CHECK_BIT(iid, bitno)) {
            return _add(&(*cur)->right, iid, entry, bitsize, bitno + 1);
        } else {
            return _add(&(*cur)->left, iid, entry, bitsize, bitno + 1);
        }
    }
}

static int add_entry(struct r_tree *rt, uint32_t iid, void *entry, int len)
{
    return _add(&rt->root, iid, entry, len, 0);
}

/*------------------------------------------------------------------*/
static int global_enable(void)
{
    __enable_fault_irq(); /* FIQ */
    return FWK_SUCCESS;
}

static int global_disable(void)
{
    __disable_fault_irq(); /* FIQ */
    return FWK_SUCCESS;
}

static int is_enabled(unsigned int interrupt, bool *enabled)
{
    if (!IS_SUPPORT_INT(interrupt))
        return FWK_E_PARAM;
    //fatih dummy
    //*enabled = (bool)gicd_get_isenabler(RCAR4_GICD_BASE, interrupt); 

    return FWK_SUCCESS;
}

static int enable(unsigned int interrupt)
{
    if (!IS_SUPPORT_INT(interrupt))
        return FWK_E_PARAM;
    /*
    gicd_set_isenabler(RCAR4_GICD_BASE, interrupt);
    */

    Interrupt_Enable(interrupt);

    return FWK_SUCCESS;
}

static int disable(unsigned int interrupt)
{
    if (!IS_SUPPORT_INT(interrupt))
        return FWK_E_PARAM;

    //gicd_set_icenabler(RCAR4_GICD_BASE, interrupt);

    GIC_DisableInterface(interrupt);
    return FWK_SUCCESS;
}



static int clear_pending(unsigned int interrupt)
{
    //unsigned int bit;

    if (!IS_SUPPORT_INT(interrupt))
        return FWK_E_PARAM;

    //bit = interrupt % 32;
    /*fatih dummy
    gicd_write_icpendr(RCAR4_GICD_BASE, interrupt, 1U << bit);
*/
    return FWK_SUCCESS;
}

static int set_isr_irq(unsigned int interrupt, void (*isr)(void))
{
    struct callback *entry;
    int ret;

    if ((MIN_IRQ > interrupt) || (MAX_IRQ <= interrupt))
        return FWK_E_PARAM;

    entry = fwk_mm_calloc(1, sizeof(struct callback));
    if (NULL == entry)
        return FWK_E_PANIC;

    entry->funcn = isr;
    entry->param = (uintptr_t)NULL;
    ret = add_entry(radix, interrupt, (void *)entry, IID_LEN);
    if (ret)
        return FWK_E_PANIC;

    return FWK_SUCCESS;
}

static int set_isr_irq_param(
    unsigned int interrupt,
    void (*isr)(uintptr_t param),
    uintptr_t parameter)
{
    struct callback *entry;
    int ret;

    if ((MIN_IRQ > interrupt) || (MAX_IRQ <= interrupt))
        return FWK_E_PANIC;

    entry = fwk_mm_calloc(1, sizeof(struct callback));
    if (NULL == entry)
        return FWK_E_PANIC;

    entry->func = isr;
    entry->param = parameter;
    ret = add_entry(radix, interrupt, (void *)entry, IID_LEN);
    if (ret)
        return FWK_E_PARAM;

    return FWK_SUCCESS;
}

static int set_isr_dummy(void (*isr)(void))
{
    return FWK_SUCCESS;
}

static int set_isr_dummy_param(
    void (*isr)(uintptr_t param),
    uintptr_t parameter)
{
    return FWK_SUCCESS;
}

static int get_current(unsigned int *interrupt)
{
    *interrupt = c_interrupt;

    /* Not an interrupt */
    if (0 == *interrupt)
        return FWK_E_STATE;

    return FWK_SUCCESS;
}

static bool is_interrupt_context(void)
{
    /* Not an interrupt */
    if (c_interrupt == 0) {
        return false;
    }
    volatile int a = 7;
    a++;
    
    return true;
}


static const struct fwk_arch_interrupt_driver arm_gic_driver = {
    .global_enable = global_enable,
    .global_disable = global_disable,
    .is_enabled = is_enabled,
    .enable = enable,
    .disable = disable,
    .is_pending = is_pending,
    .set_pending = set_pending,
    .clear_pending = clear_pending,
    .set_isr_irq = set_isr_irq,
    .set_isr_irq_param = set_isr_irq_param,
    .set_isr_nmi = set_isr_dummy,
    .set_isr_nmi_param = set_isr_dummy_param,
    .set_isr_fault = set_isr_dummy,
    .get_current = get_current,
    .is_interrupt_context = is_interrupt_context,
};

int arm_gic_init(const struct fwk_arch_interrupt_driver **driver)
{
    /*
     * Allocate and initialize a table for the callback functions and their
     * corresponding parameters.
     */
    radix = init_entry(NULL);
    if (radix == NULL)
        return FWK_E_NOMEM;

    gic_init();

    /*
     * Initialize all exception entries to point to the arm_exception_invalid()
     * handler.
     *
     * Note: Initialization starts from entry 1 since entry 0 is not an
     * exception pointer but the default stack pointer.
     */

    *driver = &arm_gic_driver;

    return FWK_SUCCESS;
}
