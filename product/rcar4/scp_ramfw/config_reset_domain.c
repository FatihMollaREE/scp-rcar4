/*
*
* LICENSE
*
*/

#include <reset_devices.h>
//#include <reset_mstp_devices.h>

#include <mod_reset_domain.h>
#include <mod_rcar4_reset.h>

#include <fwk_element.h>
#include <fwk_macros.h>
#include <fwk_module.h>
#include <fwk_module_idx.h>

/*temporary  define*/
#define RESET_DEV_IDX_COUNTFM 1

const struct fwk_element reset_domain_element_table[] = {
    [0] = {
        .name = "srt28",
        .data = &((struct mod_reset_domain_dev_config) {
            .driver_id = FWK_ID_ELEMENT_INIT(FWK_MODULE_IDX_RCAR4_RESET,/*FATIH woher kommen die module indexes, passt das so?*/
                RESET_DEV_IDX_SRT28),
            .driver_api_id = FWK_ID_API_INIT(FWK_MODULE_IDX_RCAR4_RESET,
                MOD_RCAR_RESET_API_TYPE_CLOCK),
            .modes = MOD_RESET_DOMAIN_MODE_EXPLICIT_ASSERT |
                MOD_RESET_DOMAIN_MODE_EXPLICIT_DEASSERT,
        }),
    },
    [RESET_DEV_IDX_COUNTFM] = { 0 }, /* Termination description. */

};

static const struct mod_reset_domain_config reset_domain_config = {
#ifdef BUILD_HAS_SCMI_NOTIFICATIONS
    .notification_id = FWK_ID_NOTIFICATION_INIT(FWK_MODULE_IDX_RESET_DOMAIN,
        MOD_RESET_DOMAIN_NOTIFICATION_AUTORESET),
#endif
};

static const struct fwk_element *reset_domain_get_element_table
    (fwk_id_t module_id)
{
    return reset_domain_element_table;
}

struct fwk_module_config config_reset_domain = {
    .data = &reset_domain_config,
    .elements = FWK_MODULE_DYNAMIC_ELEMENTS(reset_domain_get_element_table),
};