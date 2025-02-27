/*
*
* LICENSE
*
*/

#include <fwk_element.h>
#include <fwk_module.h>
#include <mod_rcar4_reset.h>


const struct fwk_element rcar4_reset_element_table[] = {
    {
        .name = "srt28", /* PWM */
        .data = &( (struct mod_rcar4_reset_dev_config) {
            .control_reg = CPG_SMSTPCR6,
            .bit = 28,
        }),
    },
    {0}, // Terminate description 
};

static const struct mod_reset_domain_config rcar4_reset_config = {
    #ifdef BUILD_HAS_SCMI_NOTIFICATIONS
        .notification_id = FWK_ID_NOTIFICATION_INIT(FWK_MODULE_IDX_RESET_DOMAIN,
                                MOD_RESET_DOMAIN_NOTIFICATION_AUTORESET),
    #endif
    };

static const struct fwk_element *rcar4_reset_get_element_table(fwk_id_t module_id)
{
    return rcar4_reset_element_table;
}


struct fwk_module_config config_rcar4_reset = {
    .data =  &rcar4_reset_config, 
    .elements = FWK_MODULE_DYNAMIC_ELEMENTS(rcar4_reset_get_element_table),
};