/*******************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only
* intended for use with Renesas products. No other uses are authorized. This
* software is owned by Renesas Electronics Corporation and is protected under
* all applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
* AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software
* and to discontinue the availability of this software. By using this software,
* you agree to the additional terms and conditions found by accessing the
* following link:
* http://www.renesas.com/disclaimer
* Copyright 2018-2023 Renesas Electronics Corporation All rights reserved.
*******************************************************************************/



/*******************************************************************************
 * DESCRIPTION   : GIC Control Function
 ******************************************************************************/
/******************************************************************************
 * @file          gic.h
 * - Version      : 0.04
 * @brief         Controls GIC-600 registers and interrupts.
 * .
 *****************************************************************************/
/******************************************************************************
 * History : DD.MM.YYYY Version  Description
 *         : 02.08.2022 0.01     First Release
 *         : 20.09.2022 0.02     Set ChildrenAsleep of GICR_WAKER to 1 and end processing
 *         : 31.10.2022 0.03     License notation change.
 *         : 04.04.2023 0.04     Removed stdio.h.
 *****************************************************************************/

#ifndef GIC_H
#define GIC_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include <stdint.h>

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/* GIC base */
#define GICD_BASE    (0xF0000000UL)
#define GICR_BASE    (GICD_BASE + 0x60000U)

/* Generic Interrupt Controller Distributor (GICD) */
#define GICD_CTLR              *((volatile uint32_t *)(GICD_BASE + 0x000U))
#define GICD_IGROUPR(n)        *((volatile uint32_t *)(GICD_BASE + 0x080U + 4U*(n)))
#define GICD_ISENABLER(n)      *((volatile uint32_t *)(GICD_BASE + 0x100U + 4U*(n)))
#define GICD_ICENABLER(n)      *((volatile uint32_t *)(GICD_BASE + 0x180U + 4U*(n)))
#define GICD_ISPENDR(n)        *((volatile uint32_t *)(GICD_BASE + 0x200U + 4U*(n)))
#define GICD_ICPENDR(n)        *((volatile uint32_t *)(GICD_BASE + 0x280U + 4U*(n)))
#define GICD_IPRIORITYR(n)     *((volatile uint32_t *)(GICD_BASE + 0x400U + 4U*(n)))
#define GICD_ICFGR(n)          *((volatile uint32_t *)(GICD_BASE + 0xC00U + 4U*(n)))
#define GICD_IGRPMODR(n)       *((volatile uint32_t *)(GICD_BASE + 0xD00U + 4U*(n)))
#define GICD_IROUTER(n)        *((volatile uint64_t *)(GICD_BASE + 0x6000U + 8U*(n)))

/* Generic Interrupt Controller Redistributor (GICR) */
#define GICR_CTLR              *((volatile uint32_t *)(GICR_BASE + 0x0000U))
#define GICR_WAKER             *((volatile uint32_t *)(GICR_BASE + 0x0014U))
#define GICR_PWRR              *((volatile uint32_t *)(GICR_BASE + 0x0024U))

#define CHILDREN_ASLEEP        (1U << 2U)
#define PROCESSOR_SLEEP        (1U << 1U)
#define RDPOWER_DOWN           (1U << 0U)

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

/*******************************************************************************
**                      Macro                                                 **
*******************************************************************************/

/*******************************************************************************
 * Definitions for CPU system register interface to GICv3
 ******************************************************************************/
/* ICC_SRE_EL3 */
#define ICC_SRE_EN_BIT     (8U)
#define ICC_SRE_DIB_BIT    (4U)
#define ICC_SRE_DFB_BIT    (2U)
#define ICC_SRE_SRE_BIT    (1U)

/* SCR_EL3 */
#define SCR_NS_BIT         (1U)

/* Affinity Leve mask value */
#define AFFINITY0_MASK     (0xFFU)
#define AFFINITY1_MASK     (0xFF00U)
#define AFFINITY2_MASK     (0xFF0000U)
#define AFFINITY3_MASK     (0xFF00000000U)
#define IRM_OFF            (0x80000000U)

/* fatih: not validated
ICC_CTLR_EL1 (s3_0_c12_c12_4)
ICC_CTLR_EL3 (s3_6_c12_c12_4)
ICC_IGRPEN0_EL1 (s3_0_c12_c12_6)
ICC_IGRPEN1_EL1 (s3_0_c12_c12_7)
ICC_IGRPEN1_EL3 (s3_6_c12_c12_7)
ICC_PMR_EL1 (s3_0_c4_c6_0)
ICC_RPR_EL1 (s3_0_c12_c11_3)
ICC_SGI1R_EL1 (s3_0_c12_c11_5)
ICC_SRE_EL1 (s3_0_c12_c12_5)
ICC_SRE_EL2 (s3_4_c12_c9_5)
ICC_SRE_EL3 (s3_6_c12_c12_5)
ICV_CTLR_EL1 (s3_0_c12_c12_4)
ICV_IGRPEN0_EL1 (s3_0_c12_c12_6)
ICV_IGRPEN1_EL1 (s3_0_c12_c12_7)
ICV_PMR_EL1 (s3_0_c4_c6_0)
ICV_RPR_EL1 (s3_0_c12_c11_3)
*/

/* Get ICC_IAR0 */
static inline uint64_t get_ICC_IAR0(void)
{
    uint64_t value = 0U;
    __asm__ volatile("mrs %0, S3_0_c12_c8_0" : "=r" (value));
    return value;
}

/* Set ICC_PMR */
static inline void set_ICC_PMR(uint64_t value)
{
    //__asm__ volatile ("msr S3_0_C4_C6_0, %0" :: "r" (value));
}

/* Set ICC_IGRPEN0 */
static inline void set_ICC_IGRPEN0(uint64_t value)
{
    __asm__ volatile ("mcr p15, 0, %0, c12, c12, 6" :: "r" (value));
}

/* Set ICC_SRE_EL1 */
static inline void set_ICC_SRE_EL1(uint64_t value)
{
   // __asm__ volatile ("msr S3_0_C12_C12_5, %0" :: "r" (value));
}

/* Get ICC_SRE_EL3 */
static inline uint64_t get_ICC_SRE_EL3(void)
{
    uint64_t value = 0U;
    //__asm__ volatile("mrs %0, S3_6_C12_C12_5" : "=r" (value));
    return value;
}

/* Set ICC_SRE_EL3 */
static inline void set_ICC_SRE_EL3(uint64_t value)
{
   // __asm__ volatile ("msr S3_6_C12_C12_5, %0" :: "r" (value));
}

/* Get MPIDR_EL1 */
static inline uint64_t get_MPIDR_EL1(void)
{
    uint64_t value = 0U;
   // __asm__ volatile("mrs %0, MPIDR" : "=r" (value));
    return value;
}

/* ISB */
static inline void GIC_isb(void)
{
   // __asm__ volatile ("isb");
}

/*  Enable the interrupt distributor using the GIC's CTLR register */
static inline void GIC_EnableDistributor(void)
{
    GICD_CTLR |= 0x31U;
}

/* Disable the interrupt distributor using the GIC's CTLR register */
static inline void GIC_DisableDistributor(void)
{
    GICD_CTLR &= 0xFFFFFFFEU;
}

/* Set the interrupt enable from the GIC's ISENABLER register */
static inline void GIC_SetEnable(uint32_t intid, uint32_t value)
{
    uint32_t reg     = GICD_ISENABLER(intid / 32U);
    uint32_t shift   = (intid % 32U);

    reg &= (~(1U          << shift));
    reg |= ( (value & 1U) << shift);

    GICD_ISENABLER(intid / 32U) = reg;
}

/* Set the interrupt disable from the GIC's ICENABLER register */
static inline void GIC_SetClearEnable(uint32_t intid, uint32_t value)
{
    uint32_t reg     = GICD_ICENABLER(intid / 32U);
    uint32_t shift   = (intid % 32U);

    reg &= (~(1U          << shift));
    reg |= ( (value & 1U) << shift);

    GICD_ICENABLER(intid / 32U) = reg;
}

/* Sets the interrupt configuration using GIC's ICFGR register */
static inline void GIC_SetConfiguration(uint32_t intid, uint32_t int_config)
{
    uint32_t icfgr = GICD_ICFGR(intid / 16U);
    uint32_t shift = (intid % 16U) << 1U;

    icfgr &= (~(3U         << shift));
    icfgr |= (  int_config << shift);

    GICD_ICFGR(intid / 16U) = icfgr;
}

/* Set the priority for the given interrupt in the GIC's IPRIORITYR register */
static inline void GIC_SetPriority(uint32_t intid, uint32_t priority)
{
    uint32_t mask  = GICD_IPRIORITYR(intid / 4U);
	uint32_t shift = ((intid % 4U) * 8U);

    mask &= (~(0xFFU          << shift));
    mask |= ( (priority & 0xFFU) << shift);

    GICD_IPRIORITYR(intid / 4U) = mask;
}

/* Set the interrupt group from the GIC's IGROUPR register */
static inline void GIC_SetGroup(uint32_t intid, uint32_t group)
{
    uint32_t igroupr = GICD_IGROUPR(intid / 32U);
    uint32_t shift   = (intid % 32U);

    igroupr &= (~(1U          << shift));
    igroupr |= ( (group & 1U) << shift);

    GICD_IGROUPR(intid / 32U) = igroupr;
}

/* Set the interrupt group from the GIC's IGRPMODR register */
static inline void GIC_SetGrpMode(uint32_t intid, uint32_t mode)
{
    uint32_t imode   = GICD_IGRPMODR(intid / 32U);
    uint32_t shift   = (intid % 32U);

    imode &= (~(1U          << shift));
    imode |= ( (mode & 1U) << shift);

    GICD_IGRPMODR(intid / 32U) = imode;
}

/* Set the interrupt routing from the GIC's IROUTER register */
static inline void GIC_SetRouter(uint32_t intid)
{
    uint64_t affinity = 0U;

    /* Get Affinity level */
    //affinity = get_MPIDR_EL1();
    affinity &= (AFFINITY0_MASK | AFFINITY1_MASK | AFFINITY2_MASK | AFFINITY3_MASK);
    /* Interrupt routing mode bit OFF */
	affinity &= (~(IRM_OFF));

    GICD_IROUTER(intid) = affinity;
}

/* Get power register value from the GIC's GICR_PWRR register */
static inline uint32_t GIC_Getpwwr(void)
{
    return (GICR_PWRR);
}

/* Set power register value from the GIC's GICR_PWRR register */
static inline void GIC_Setpwwr(uint32_t set_value)
{
    GICR_PWRR = set_value;
}

/* Get power management cotrol register from the GIC's GICR_WAKER register */
static inline uint32_t GIC_Getwaker(void)
{
    return (GICR_WAKER);
}

/* Set power management cotrol register from the GIC's GICR_WAKER register */
static inline void GIC_Setwaker(uint32_t set_value)
{
    GICR_WAKER = set_value;
}

/* Enables the given interrupt using GIC's ISENABLER register */
static inline void GIC_EnableFIQ(uint32_t intid)
{

    /* Disable interrupt forwarding */
    GIC_DisableDistributor();

    /* Set level-sensitive */
    GIC_SetConfiguration(intid, 0U);

    /* Set priority */
    GIC_SetPriority(intid, 0U);

    /* Set group 0 (secure) */
    GIC_SetGroup(intid, 0U);

    /* Set group 0 (secure) */
    GIC_SetGrpMode(intid, 0U);

    /* Enable distributor */
    GIC_EnableDistributor();

    /* Enable the SPI interrupt */
    GIC_SetEnable(intid, 1U);

    /* Set the interrupt routing */
    GIC_SetRouter(intid);
}

/*  Enable the interrupt redistributor wakeup */
static inline void GIC_WakeupRedistributor(void)
{
    uint32_t    get_value = 0U;
    uint32_t    set_value = 0U;

    get_value = GIC_Getpwwr();
	set_value = get_value & ~(RDPOWER_DOWN);
    GIC_Setpwwr(set_value);

    get_value = GIC_Getwaker();
    set_value = get_value & ~(PROCESSOR_SLEEP);
    GIC_Setwaker(set_value);

    do 
    {
        get_value = GIC_Getwaker();
    }while((get_value & CHILDREN_ASLEEP) == CHILDREN_ASLEEP);
}

/* Enable the CPU's interrupt interface */
static inline void GIC_EnableInterface(void)
{
    //uint64_t reg = 0U;
    //uint64_t icc_sre_el3 = 0U;

    /* Disable the legacy interrupt bypass */
    //icc_sre_el3 = ICC_SRE_DIB_BIT | ICC_SRE_DFB_BIT | ICC_SRE_EN_BIT | ICC_SRE_SRE_BIT;

    //reg = get_ICC_SRE_EL3();
    //set_ICC_SRE_EL3(reg | icc_sre_el3);

    //set_ICC_SRE_EL1(ICC_SRE_SRE_BIT);
    GIC_isb();

    set_ICC_IGRPEN0(1U); /* enable interface grp0 */
    GIC_isb();
}

/* Disable the CPU's interrupt interface */
static inline void GIC_DisableInterface(uint32_t intid)
{
    uint32_t    get_value = 0U;
    uint32_t    set_value = 0U;

    /* Clear Enable the SPI interrupt */
    GIC_SetClearEnable(intid, 1U);

    /* Set ChildrenAsleep of GICR_WAKER to 1 and end processing */
    get_value = GIC_Getwaker();
    set_value = get_value | PROCESSOR_SLEEP;
    GIC_Setwaker(set_value);

    do
    {
        get_value = GIC_Getwaker();
    }while((get_value & CHILDREN_ASLEEP) != CHILDREN_ASLEEP);

}

/* Read the CPU's IAR register */
static inline uint32_t GIC_AcknowledgePending(void)
{
    return (uint32_t)(get_ICC_IAR0());
}

/* Set the interrupt priority mask using CPU's PMR register */
static inline void GIC_SetInterfacePriorityMask(uint64_t priority)
{
    /* Specify F8. 32 priority levels are bit0-2 invalid */
    set_ICC_PMR(priority << 3U);
}

/* Initialize and enable the GIC */
static inline void GIC_Enable(void)
{
    GIC_WakeupRedistributor();
    /* Enable interface */
    GIC_EnableInterface();
    /* Set priority mask */
    GIC_SetInterfacePriorityMask(0xFFUL);
}

/*******************************************************************************
**                      Function                                              **
*******************************************************************************/
/* Interrupt configuration */
#define Interrupt_Config(void)              GIC_Enable(void)

/* Enable */
#define Interrupt_Enable(intid)             GIC_EnableFIQ((uint32_t)intid)

/* Disable */
#define Interrupt_Disable(intid)            GIC_DisableInterface((uint32_t)intid)

#endif /* GIC_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
