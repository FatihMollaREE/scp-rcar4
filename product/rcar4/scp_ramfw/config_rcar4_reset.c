/*
*
* LICENSE
*
*/


/* ---------------------------- implement: ----------------------

struct fwk_module_elements {
    enum fwk_module_elements_type type;

    union {
        const struct fwk_element *(*generator)(fwk_id_t module_id);
        const struct fwk_element *table;
    };
}; 


struct fwk_module_config {
    const void *data;
    struct fwk_module_elements elements;
};
    ^
    |
    |
struct fwk_module_config config_clock = {
    .elements = FWK_MODULE_DYNAMIC_ELEMENTS(clock_get_dev_desc_table),
    .data = &((struct mod_clock_config){
        .pd_transition_notification_id = FWK_ID_NOTIFICATION_INIT(
            FWK_MODULE_IDX_POWER_DOMAIN,
            MOD_PD_NOTIFICATION_IDX_POWER_STATE_TRANSITION),
        .pd_pre_transition_notification_id = FWK_ID_NOTIFICATION_INIT(
            FWK_MODULE_IDX_POWER_DOMAIN,
            MOD_PD_NOTIFICATION_IDX_POWER_STATE_PRE_TRANSITION),
    }),
}; copied from rcar

------------------------------------------------------------------
*/