/*
*
* LICENSE
*
*/

#include <mod_scmi_reset_domain.h>
#include <rcar4_scmi.h>

#include <fwk_element.h>
#include <fwk_macros.h>
#include <fwk_module.h>
#include <fwk_module_idx.h>

static const struct mod_scmi_reset_domain_device agent_device_table_ospm[] = {
    {
        /* srt28 */
        .element_id =
            FWK_ID_ELEMENT_INIT(FWK_MODULE_IDX_RESET_DOMAIN,
            RESET_DEV_IDX_SRT28),
        .permissions = MOD_SCMI_RESET_DOMAIN_PERM_ATTRIBUTES |
            MOD_SCMI_RESET_DOMAIN_PERM_RESET,
    },
};

static const struct mod_scmi_reset_domain_agent agent_table[] = {
    [SCMI_AGENT_ID_PSCI] = { /* No access */ },
    [SCMI_AGENT_ID_OSPM] = {
        .device_table = agent_device_table_ospm,
        .agent_domain_count = FWK_ARRAY_SIZE(agent_device_table_ospm),
    },
    [SCMI_AGENT_ID_VMM] = {
        .device_table = agent_device_table_ospm,
        .agent_domain_count = FWK_ARRAY_SIZE(agent_device_table_ospm),
    },
    [SCMI_AGENT_ID_VM1] = {
        .device_table = agent_device_table_ospm,
        .agent_domain_count = FWK_ARRAY_SIZE(agent_device_table_ospm),
    },
    [SCMI_AGENT_ID_VM2] = {
        .device_table = agent_device_table_ospm,
        .agent_domain_count = FWK_ARRAY_SIZE(agent_device_table_ospm),
    },
};

const struct fwk_module_config config_scmi_reset_domain = {
    .data = &((struct mod_scmi_reset_domain_config){
        .agent_table = agent_table,
        .agent_count = FWK_ARRAY_SIZE(agent_table),
    }),
};