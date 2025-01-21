/*
 * Renesas SCP/MCP Software
 * Copyright (c) 2020-2021, Renesas Electronics Corporation. All rights
 * reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

//#include <mod_rcar4_system.h>
#include <mod_system_power.h>

#include <fwk_id.h>
#include <fwk_interrupt.h>
#include <fwk_macros.h>
#include <fwk_module.h>
#include <fwk_module_idx.h>
/* fatih: */
#define FatihBackdoor 0

const struct fwk_module_config config_rcar4_system_power = {
    .data = &((struct mod_system_power_config){
        .soc_wakeup_irq = FWK_INTERRUPT_NONE,
        .driver_id = FWK_ID_MODULE_INIT(FatihBackdoor),
        .driver_api_id = FWK_ID_API_INIT(
            FatihBackdoor,
            FatihBackdoor) })
};
