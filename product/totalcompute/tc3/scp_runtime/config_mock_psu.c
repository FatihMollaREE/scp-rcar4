/*
 * Arm SCP/MCP Software
 * Copyright (c) 2023-2024, Arm Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <tc3_mock_psu.h>
#include <tc_core.h>

#include <mod_mock_psu.h>

#include <fwk_element.h>
#include <fwk_module.h>

static const struct fwk_element element_table[MOCK_PSU_ELEMENT_IDX_COUNT + 1] = {
    [MOCK_PSU_ELEMENT_IDX_GROUP_LITTLE] = {
        .name = "DVFS_GROUP_" TC_GROUP_LITTLE_NAME,
        .data =
            &(const struct mod_mock_psu_element_cfg){
                .async_alarm_id = FWK_ID_NONE_INIT,
                .async_alarm_api_id = FWK_ID_NONE_INIT,

                .async_response_id = FWK_ID_NONE_INIT,
                .async_response_api_id = FWK_ID_NONE_INIT,

                .default_enabled = true,
                .default_voltage = 550,
            },
    },
    [MOCK_PSU_ELEMENT_IDX_GROUP_MID] = {
        .name = "DVFS_GROUP_" TC_GROUP_MID_NAME,
        .data =
            &(const struct mod_mock_psu_element_cfg){
                .async_alarm_id = FWK_ID_NONE_INIT,
                .async_alarm_api_id = FWK_ID_NONE_INIT,

                .async_response_id = FWK_ID_NONE_INIT,
                .async_response_api_id = FWK_ID_NONE_INIT,

                .default_enabled = true,
                .default_voltage = 550,
            },
    },
    [MOCK_PSU_ELEMENT_IDX_GROUP_BIG] = {
        .name = "DVFS_GROUP_" TC_GROUP_BIG_NAME,
        .data =
            &(const struct mod_mock_psu_element_cfg){
                .async_alarm_id = FWK_ID_NONE_INIT,
                .async_alarm_api_id = FWK_ID_NONE_INIT,

                .async_response_id = FWK_ID_NONE_INIT,
                .async_response_api_id = FWK_ID_NONE_INIT,

                .default_enabled = true,
                .default_voltage = 550,
            },
    },
    [MOCK_PSU_ELEMENT_IDX_GPU] = {
        .name = "DVFS_GROUP_GPU",
        .data =
            &(const struct mod_mock_psu_element_cfg){
                .async_alarm_id = FWK_ID_NONE_INIT,
                .async_alarm_api_id = FWK_ID_NONE_INIT,

                .async_response_id = FWK_ID_NONE_INIT,
                .async_response_api_id = FWK_ID_NONE_INIT,

                .default_enabled = true,
                .default_voltage = 550,
            },
    },
    { 0 }
};

static const struct fwk_element *get_element_table(fwk_id_t module_id)
{
    return element_table;
}

const struct fwk_module_config config_mock_psu = {
    .elements = FWK_MODULE_DYNAMIC_ELEMENTS(get_element_table),
};
