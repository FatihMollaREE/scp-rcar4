/*
 * Renesas SCP/MCP Software
 * Copyright (c) 2020-2021, Renesas Electronics Corporation. All rights
 * reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <clock_devices.h>
//#include <clock_mstp_devices.h>
//#include <clock_sd_devices.h>
#include <rcar4_core.h>
//#include <config_rcar4_pd_pmic_bd9571.h>

#include <mod_clock.h>
#include <mod_rcar4_clock.h>
#include <mod_rcar4_system.h>
//#include <mod_reg_sensor.h>
//#include <mod_rcar4_scif.h>
#include <mod_rcar4_pd_sysc.h>
//#include <mod_rcar4_pd_pmic_bd9571.h>

#include <fwk_element.h>
#include <fwk_module.h>
#include <fwk_module_idx.h>

#include <stddef.h>

static struct fwk_element rcar4_system_element_table[] = {
    {
        .name = "pd_sysc",
        .data = &((struct mod_rcar4_system_dev_config) {
            .driver_id = FWK_ID_ELEMENT_INIT(FWK_MODULE_IDX_RCAR4_PD_SYSC, 0),
            .api_id = FWK_ID_API_INIT(
                FWK_MODULE_IDX_RCAR4_PD_SYSC,
                MOD_RCAR4_PD_SYSC_API_TYPE_SYSTEM),
        }),
    },
    { 0 }, /* Termination description. */
};

static const struct fwk_element *get_element_table(fwk_id_t module_id)
{
    return rcar4_system_element_table;
}

struct fwk_module_config config_rcar4_system = {
    .elements = FWK_MODULE_DYNAMIC_ELEMENTS(get_element_table),
    .data = NULL,
};
