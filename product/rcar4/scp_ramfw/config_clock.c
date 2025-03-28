/* FATIH: nix geändert
 * Renesas SCP/MCP Software
 * Copyright (c) 2020-2021, Renesas Electronics Corporation. All rights
 * reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <clock_devices.h>
//#include <clock_mstp_devices.h>
//#include <clock_sd_devices.h>
//#include <clock_ext_devices.h>
#include <config_power_domain.h>
#include <rcar4_core.h>

#include <mod_clock.h>
#include <mod_rcar4_clock.h>
#include <mod_power_domain.h>

#include <fwk_element.h>
#include <fwk_module.h>
#include <fwk_module_idx.h>

#include <stddef.h>

static struct fwk_element clock_dev_desc_table[] = {
    [CLOCK_DEV_IDX_BIG] = {
        .name = "CPU_GROUP_BIG",
        .data = &((struct mod_clock_dev_config) {
            .driver_id = FWK_ID_ELEMENT_INIT(FWK_MODULE_IDX_RCAR4_CLOCK, 0),
            .api_id = FWK_ID_API_INIT(FWK_MODULE_IDX_RCAR4_CLOCK,
                                       MOD_RCAR4_CLOCK_API_TYPE_CLOCK),
        }),
    },
    [CLOCK_DEV_IDX_LITTLE] = {
        .name = "CPU_GROUP_LITTLE",
        .data = &((struct mod_clock_dev_config) {
            .driver_id = FWK_ID_ELEMENT_INIT(FWK_MODULE_IDX_RCAR4_CLOCK, 1),
            .api_id = FWK_ID_API_INIT(FWK_MODULE_IDX_RCAR4_CLOCK,
                                       MOD_RCAR4_CLOCK_API_TYPE_CLOCK),
        }),
    },
    
    [CLOCK_DEV_IDX_COUNT] = { 0 }, /* Termination description. */
};

static const struct fwk_element *clock_get_dev_desc_table(fwk_id_t module_id)
{
    unsigned int i;
    unsigned int core_count;
    struct mod_clock_dev_config *dev_config;

    core_count = rcar4_core_get_count();

    /* Configure all clocks to respond to changes in SYSTOP power state */
    for (i = 0; i < CLOCK_DEV_IDX_COUNT; i++) {
        dev_config =
            (struct mod_clock_dev_config *)clock_dev_desc_table[i].data;
        dev_config->pd_source_id = FWK_ID_ELEMENT(
            FWK_MODULE_IDX_POWER_DOMAIN,
            CONFIG_POWER_DOMAIN_CHILD_COUNT + core_count);
    }
    return clock_dev_desc_table;
}

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
};
