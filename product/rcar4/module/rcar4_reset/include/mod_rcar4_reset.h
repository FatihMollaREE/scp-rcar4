/*
* LICENSE
*/


#ifndef MOD_RCAR4_RESET_H
#define MOD_RCAR4_RESET_H


struct mod_rcar4_reset_dev_config {
    /*! pointer to reset control register*/
    volatile uint32_t const control_reg;

    /*! enable / disable bit position*/
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

/*
struct mod_rcar4_reset_drv_api {

};

ich glaube braucht man hier nicht weil wir von reset module from framework api nutzen / imlementieren
*/

enum mod_rcar4_reset_api_type {
    
    MOD_RCAR_RESET_APIY_TYPE_CLOCK,
    MOD_RCAR4_RESET_API_COUNT, // tbu  
};

#endif /* MOD_RCAR4_RESET_H */