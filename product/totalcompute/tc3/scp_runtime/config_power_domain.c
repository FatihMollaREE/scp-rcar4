/*
 * Arm SCP/MCP Software
 * Copyright (c) 2023-2024, Arm Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "config_power_domain.h"
#include "tc3_mock_ppu.h"
#include "tc_core.h"
#include "tc_power_domain.h"
#include "tc_ppu_v1.h"

#include <power_domain_utils.h>

#include <mod_mock_ppu.h>
#include <mod_power_domain.h>
#include <mod_ppu_v1.h>
#include <mod_system_power.h>

#include <fwk_element.h>
#include <fwk_id.h>
#include <fwk_macros.h>
#include <fwk_mm.h>
#include <fwk_module.h>
#include <fwk_module_idx.h>

#include <stdint.h>
#include <stdio.h>
#include <string.h>

/* Maximum power domain name size including the null terminator */
#define PD_NAME_SIZE 12

/* Mask of the allowed states for the systop power domain */
static const uint32_t systop_allowed_state_mask_table[1] = {
    [0] = MOD_PD_STATE_ON_MASK
};

/* Mask of the allowed states for the gputop power domain depending on the
 * system states.
 */
static const uint32_t gputop_allowed_state_mask_table[] = {
    [MOD_PD_STATE_OFF] = MOD_PD_STATE_OFF_MASK,
    [MOD_PD_STATE_ON] = MOD_PD_STATE_OFF_MASK | MOD_PD_STATE_ON_MASK,
    [MOD_SYSTEM_POWER_POWER_STATE_SLEEP0] = MOD_PD_STATE_OFF_MASK,
    [MOD_SYSTEM_POWER_POWER_STATE_SLEEP1] = MOD_PD_STATE_OFF_MASK
};

/*
 * Mask of the allowed states for the cluster power domain depending on the
 * system states.
 */
static const uint32_t cluster_pd_allowed_state_mask_table[2] = {
    [MOD_PD_STATE_OFF] = MOD_PD_STATE_OFF_MASK,
    [MOD_PD_STATE_ON] = TC_CLUSTER_VALID_STATE_MASK,
};

/* Mask of the allowed states for a core depending on the cluster states. */
static const uint32_t core_pd_allowed_state_mask_table[2] = {
    [MOD_PD_STATE_OFF] = MOD_PD_STATE_OFF_MASK | MOD_PD_STATE_SLEEP_MASK,
    [MOD_PD_STATE_ON] = TC_CORE_VALID_STATE_MASK,
};

/* Power module specific configuration data (none) */
static const struct mod_power_domain_config tc3_power_domain_config = { 0 };

static struct fwk_element tc3_power_domain_static_element_table[] = {
    [PD_STATIC_DEV_IDX_GPUTOP] =
        {
            .name = "GPUCGRP",
            .data = &((struct mod_power_domain_element_config) {
                .attributes.pd_type = MOD_PD_TYPE_DEVICE,
                .driver_id = FWK_ID_ELEMENT_INIT(
                    FWK_MODULE_IDX_MOCK_PPU,
                    MOCK_PPU_ELEMENT_IDX_GPUCGRP),
                .api_id = FWK_ID_API_INIT(
                    FWK_MODULE_IDX_MOCK_PPU,
                    0),
                .allowed_state_mask_table = gputop_allowed_state_mask_table,
                .allowed_state_mask_table_size =
                    FWK_ARRAY_SIZE(gputop_allowed_state_mask_table) }),
        },
    [PD_STATIC_DEV_IDX_SYSTOP] =
        {
            .name = "SYSTOP",
            .data = &((struct mod_power_domain_element_config){
                .attributes.pd_type = MOD_PD_TYPE_SYSTEM,
                .parent_idx = PD_STATIC_DEV_IDX_NONE,
                .driver_id = FWK_ID_MODULE_INIT(FWK_MODULE_IDX_SYSTEM_POWER),
                .api_id = FWK_ID_API_INIT(
                    FWK_MODULE_IDX_SYSTEM_POWER,
                    MOD_SYSTEM_POWER_API_IDX_PD_DRIVER),
                .allowed_state_mask_table = systop_allowed_state_mask_table,
                .allowed_state_mask_table_size =
                    FWK_ARRAY_SIZE(systop_allowed_state_mask_table) }),
        },
};

/*
 * Function definitions with internal linkage
 */
static const struct fwk_element *tc3_power_domain_get_element_table(
    fwk_id_t module_id)
{
    return create_power_domain_element_table(
        TC_NUMBER_OF_CORES,
        TC_NUMBER_OF_CLUSTERS,
        FWK_MODULE_IDX_PPU_V1,
        MOD_PPU_V1_API_IDX_POWER_DOMAIN_DRIVER,
        core_pd_allowed_state_mask_table,
        FWK_ARRAY_SIZE(core_pd_allowed_state_mask_table),
        cluster_pd_allowed_state_mask_table,
        FWK_ARRAY_SIZE(cluster_pd_allowed_state_mask_table),
        tc3_power_domain_static_element_table,
        FWK_ARRAY_SIZE(tc3_power_domain_static_element_table));
}

/*
 * Power module configuration data
 */
const struct fwk_module_config config_power_domain = {
    .elements = FWK_MODULE_DYNAMIC_ELEMENTS(tc3_power_domain_get_element_table),
    .data = &tc3_power_domain_config,
};
