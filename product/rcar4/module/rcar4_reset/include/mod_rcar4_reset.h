/*
* LICENSE
*/


#ifndef MOD_RCAR4_RESET_H
#define MOD_RCAR4_RESET_H

#include <rcar4_mmap.h>


struct mod_rcar4_reset_dev_config {
    /*! pointer to reset control register */
    volatile uint32_t const control_reg;

    /*! bit position of enable / disable */
    volatile uint32_t const bit;
};

/* Device context*/
struct rcar4_reset_dev_ctx {
    const struct mod_rcar4_reset_dev_config *config;
    struct mod_reset_domain_drv_api *api;
};

/* Module context */
struct rcar4_reset_ctx {
    struct rcar4_reset_dev_ctx *dev_ctx_table;
    unsigned int dev_count;
};

/* software reset control register offsets */
#define SOFTWARE_RESET_BASE + SRCR(i) (0x2C + (i) * 4)
/* software reset clearing register offsets*/
#define SOFTWARE_RESET_BASE + 0x80 + SRSTCLR(i) (0x2C + (i) * 4) 

#define CPG_SMSTPCR0    0
#define CPG_SMSTPCR1    1
#define CPG_SMSTPCR2    2
#define CPG_SMSTPCR3    3
#define CPG_SMSTPCR4    4
#define CPG_SMSTPCR5    5
#define CPG_SMSTPCR6    6
#define CPG_SMSTPCR7    7
#define CPG_SMSTPCR8    8
#define CPG_SMSTPCR9    9
#define CPG_SMSTPCR10   10
#define CPG_SMSTPCR11   11
#define CPG_SMSTPCR12   12
#define CPG_SMSTPCR13   13
#define CPG_SMSTPCR14   14
#define CPG_SMSTPCR15   15
#define CPG_SMSTPCR16   16
#define CPG_SMSTPCR17   17
#define CPG_SMSTPCR18   18
#define CPG_SMSTPCR19   19
#define CPG_SMSTPCR20   20
#define CPG_SMSTPCR21   21
#define CPG_SMSTPCR22   22
#define CPG_SMSTPCR23   23
#define CPG_SMSTPCR24   24
#define CPG_SMSTPCR25   25
#define CPG_SMSTPCR26   26
#define CPG_SMSTPCR27   27
#define CPG_SMSTPCR28   28
#define CPG_SMSTPCR29   29


#define DELAY_CNT_1US       (10UL)
#define SCSR_DELAY_US       (DELAY_CNT_1US * 35)


/* APIs provided by the driver */
enum mod_rcar4_reset_api_type {
    
    MOD_RCAR_RESET_API_TYPE_CLOCK,
    MOD_RCAR4_RESET_API_COUNT, // tbu  
};

#endif /* MOD_RCAR4_RESET_H */