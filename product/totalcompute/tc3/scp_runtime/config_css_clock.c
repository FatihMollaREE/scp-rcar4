/*
 * Arm SCP/MCP Software
 * Copyright (c) 2023-2024, Arm Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "clock_soc.h"
#include "tc_core.h"

#include <mod_css_clock.h>
#include <mod_pik_clock.h>
#include <mod_system_pll.h>

#include <fwk_element.h>
#include <fwk_id.h>
#include <fwk_macros.h>
#include <fwk_module.h>
#include <fwk_module_idx.h>

static const struct mod_css_clock_rate rate_table_cpu_group_group_little[5] = {
    {
        /* Super Underdrive */
        .rate = 768 * FWK_MHZ,
        .pll_rate = 768 * FWK_MHZ,
        .clock_source = MOD_PIK_CLOCK_CLUSCLK_SOURCE_TC3_PLL0,
        .clock_div_type = MOD_PIK_CLOCK_MSCLOCK_DIVIDER_DIV_EXT,
        .clock_div = 1,
        .clock_mod_numerator = 1,
        .clock_mod_denominator = 1,
    },
    {
        /* Underdrive */
        .rate = 1153 * FWK_MHZ,
        .pll_rate = 1153 * FWK_MHZ,
        .clock_source = MOD_PIK_CLOCK_CLUSCLK_SOURCE_TC3_PLL0,
        .clock_div_type = MOD_PIK_CLOCK_MSCLOCK_DIVIDER_DIV_EXT,
        .clock_div = 1,
        .clock_mod_numerator = 1,
        .clock_mod_denominator = 1,
    },
    {
        /* Nominal */
        .rate = 1537 * FWK_MHZ,
        .pll_rate = 1537 * FWK_MHZ,
        .clock_source = MOD_PIK_CLOCK_CLUSCLK_SOURCE_TC3_PLL0,
        .clock_div_type = MOD_PIK_CLOCK_MSCLOCK_DIVIDER_DIV_EXT,
        .clock_div = 1,
        .clock_mod_numerator = 1,
        .clock_mod_denominator = 1,
    },
    {
        /* Overdrive */
        .rate = 1844 * FWK_MHZ,
        .pll_rate = 1844 * FWK_MHZ,
        .clock_source = MOD_PIK_CLOCK_CLUSCLK_SOURCE_TC3_PLL0,
        .clock_div_type = MOD_PIK_CLOCK_MSCLOCK_DIVIDER_DIV_EXT,
        .clock_div = 1,
        .clock_mod_numerator = 1,
        .clock_mod_denominator = 1,
    },
    {
        /* Super Overdrive */
        .rate = 2152 * FWK_MHZ,
        .pll_rate = 2152 * FWK_MHZ,
        .clock_source = MOD_PIK_CLOCK_CLUSCLK_SOURCE_TC3_PLL0,
        .clock_div_type = MOD_PIK_CLOCK_MSCLOCK_DIVIDER_DIV_EXT,
        .clock_div = 1,
        .clock_mod_numerator = 1,
        .clock_mod_denominator = 1,
    },
};

static const struct mod_css_clock_rate rate_table_cpu_group_group_mid[5] = {
    {
        /* Super Underdrive */
        .rate = 946 * FWK_MHZ,
        .pll_rate = 946 * FWK_MHZ,
        .clock_source = MOD_PIK_CLOCK_CLUSCLK_SOURCE_TC3_PLL1,
        .clock_div_type = MOD_PIK_CLOCK_MSCLOCK_DIVIDER_DIV_EXT,
        .clock_div = 1,
        .clock_mod_numerator = 1,
        .clock_mod_denominator = 1,
    },
    {
        /* Underdrive */
        .rate = 1419 * FWK_MHZ,
        .pll_rate = 1419 * FWK_MHZ,
        .clock_source = MOD_PIK_CLOCK_CLUSCLK_SOURCE_TC3_PLL1,
        .clock_div_type = MOD_PIK_CLOCK_MSCLOCK_DIVIDER_DIV_EXT,
        .clock_div = 1,
        .clock_mod_numerator = 1,
        .clock_mod_denominator = 1,
    },
    {
        /* Nominal */
        .rate = 1893 * FWK_MHZ,
        .pll_rate = 1893 * FWK_MHZ,
        .clock_source = MOD_PIK_CLOCK_CLUSCLK_SOURCE_TC3_PLL1,
        .clock_div_type = MOD_PIK_CLOCK_MSCLOCK_DIVIDER_DIV_EXT,
        .clock_div = 1,
        .clock_mod_numerator = 1,
        .clock_mod_denominator = 1,
    },
    {
        /* Overdrive */
        .rate = 2271 * FWK_MHZ,
        .pll_rate = 2271 * FWK_MHZ,
        .clock_source = MOD_PIK_CLOCK_CLUSCLK_SOURCE_TC3_PLL1,
        .clock_div_type = MOD_PIK_CLOCK_MSCLOCK_DIVIDER_DIV_EXT,
        .clock_div = 1,
        .clock_mod_numerator = 1,
        .clock_mod_denominator = 1,
    },
    {
        /* Super Overdrive */
        .rate = 2650 * FWK_MHZ,
        .pll_rate = 2650 * FWK_MHZ,
        .clock_source = MOD_PIK_CLOCK_CLUSCLK_SOURCE_TC3_PLL1,
        .clock_div_type = MOD_PIK_CLOCK_MSCLOCK_DIVIDER_DIV_EXT,
        .clock_div = 1,
        .clock_mod_numerator = 1,
        .clock_mod_denominator = 1,
    },
};

static const struct mod_css_clock_rate rate_table_cpu_group_group_big[5] = {
    {
        /* Super Underdrive */
        .rate = 1088 * FWK_MHZ,
        .pll_rate = 1088 * FWK_MHZ,
        .clock_source = MOD_PIK_CLOCK_CLUSCLK_SOURCE_TC3_PLL2,
        .clock_div_type = MOD_PIK_CLOCK_MSCLOCK_DIVIDER_DIV_EXT,
        .clock_div = 1,
        .clock_mod_numerator = 1,
        .clock_mod_denominator = 1,
    },
    {
        /* Underdrive */
        .rate = 1632 * FWK_MHZ,
        .pll_rate = 1632 * FWK_MHZ,
        .clock_source = MOD_PIK_CLOCK_CLUSCLK_SOURCE_TC3_PLL2,
        .clock_div_type = MOD_PIK_CLOCK_MSCLOCK_DIVIDER_DIV_EXT,
        .clock_div = 1,
        .clock_mod_numerator = 1,
        .clock_mod_denominator = 1,
    },
    {
        /* Nominal */
        .rate = 2176 * FWK_MHZ,
        .pll_rate = 2176 * FWK_MHZ,
        .clock_source = MOD_PIK_CLOCK_CLUSCLK_SOURCE_TC3_PLL2,
        .clock_div_type = MOD_PIK_CLOCK_MSCLOCK_DIVIDER_DIV_EXT,
        .clock_div = 1,
        .clock_mod_numerator = 1,
        .clock_mod_denominator = 1,
    },
    {
        /* Overdrive */
        .rate = 2612 * FWK_MHZ,
        .pll_rate = 2612 * FWK_MHZ,
        .clock_source = MOD_PIK_CLOCK_CLUSCLK_SOURCE_TC3_PLL2,
        .clock_div_type = MOD_PIK_CLOCK_MSCLOCK_DIVIDER_DIV_EXT,
        .clock_div = 1,
        .clock_mod_numerator = 1,
        .clock_mod_denominator = 1,
    },
    {
        /* Super Overdrive */
        .rate = 3047 * FWK_MHZ,
        .pll_rate = 3047 * FWK_MHZ,
        .clock_source = MOD_PIK_CLOCK_CLUSCLK_SOURCE_TC3_PLL2,
        .clock_div_type = MOD_PIK_CLOCK_MSCLOCK_DIVIDER_DIV_EXT,
        .clock_div = 1,
        .clock_mod_numerator = 1,
        .clock_mod_denominator = 1,
    },
};

static const fwk_id_t member_table_cpu_group_group_little[2] = {
    FWK_ID_ELEMENT_INIT(FWK_MODULE_IDX_PIK_CLOCK, CLOCK_PIK_IDX_CLUS0_CPU0),
    FWK_ID_ELEMENT_INIT(FWK_MODULE_IDX_PIK_CLOCK, CLOCK_PIK_IDX_CLUS0_CPU1),
};

static const fwk_id_t member_table_cpu_group_group_mid[4] = {
    FWK_ID_ELEMENT_INIT(FWK_MODULE_IDX_PIK_CLOCK, CLOCK_PIK_IDX_CLUS0_CPU2),
    FWK_ID_ELEMENT_INIT(FWK_MODULE_IDX_PIK_CLOCK, CLOCK_PIK_IDX_CLUS0_CPU3),
    FWK_ID_ELEMENT_INIT(FWK_MODULE_IDX_PIK_CLOCK, CLOCK_PIK_IDX_CLUS0_CPU4),
    FWK_ID_ELEMENT_INIT(FWK_MODULE_IDX_PIK_CLOCK, CLOCK_PIK_IDX_CLUS0_CPU5),
};

static const fwk_id_t member_table_cpu_group_group_big[2] = {
    FWK_ID_ELEMENT_INIT(FWK_MODULE_IDX_PIK_CLOCK, CLOCK_PIK_IDX_CLUS0_CPU6),
    FWK_ID_ELEMENT_INIT(FWK_MODULE_IDX_PIK_CLOCK, CLOCK_PIK_IDX_CLUS0_CPU7),
};

static const fwk_id_t member_table_dpu[1] = {
    FWK_ID_ELEMENT_INIT(FWK_MODULE_IDX_PIK_CLOCK, CLOCK_PIK_IDX_DPU),
};

static const struct fwk_element css_clock_element_table[
    CLOCK_CSS_IDX_COUNT + 1] = {
    [CLOCK_CSS_IDX_CPU_GROUP_GROUP_LITTLE] =
        {
            .name = "CPU_GROUP_" TC_GROUP_LITTLE_NAME,
            .data = &((struct mod_css_clock_dev_config){
                .clock_type = MOD_CSS_CLOCK_TYPE_INDEXED,
                .rate_table = rate_table_cpu_group_group_little,
                .rate_count = FWK_ARRAY_SIZE(rate_table_cpu_group_group_little),
                .clock_switching_source =
                    MOD_PIK_CLOCK_CLUSCLK_SOURCE_TC3_PLL0,
                .pll_id = FWK_ID_ELEMENT_INIT(
                    FWK_MODULE_IDX_SYSTEM_PLL,
                    CLOCK_PLL_IDX_CPU_GROUP_LITTLE),
                .pll_api_id = FWK_ID_API_INIT(
                    FWK_MODULE_IDX_SYSTEM_PLL,
                    MOD_SYSTEM_PLL_API_TYPE_DEFAULT),
                .member_table = member_table_cpu_group_group_little,
                .member_count = FWK_ARRAY_SIZE(member_table_cpu_group_group_little),
                .member_api_id = FWK_ID_API_INIT(
                    FWK_MODULE_IDX_PIK_CLOCK,
                    MOD_PIK_CLOCK_API_TYPE_CSS),
                .initial_rate = 1537 * FWK_MHZ,
                .modulation_supported = true,
            }),
        },
    [CLOCK_CSS_IDX_CPU_GROUP_GROUP_MID] =
        {
            .name = "CPU_GROUP_" TC_GROUP_MID_NAME,
            .data = &((struct mod_css_clock_dev_config){
                .clock_type = MOD_CSS_CLOCK_TYPE_INDEXED,
                .rate_table = rate_table_cpu_group_group_mid,
                .rate_count = FWK_ARRAY_SIZE(rate_table_cpu_group_group_mid),
                .clock_switching_source =
                    MOD_PIK_CLOCK_CLUSCLK_SOURCE_TC3_PLL1,
                .pll_id = FWK_ID_ELEMENT_INIT(
                    FWK_MODULE_IDX_SYSTEM_PLL,
                    CLOCK_PLL_IDX_CPU_GROUP_MID),
                .pll_api_id = FWK_ID_API_INIT(
                    FWK_MODULE_IDX_SYSTEM_PLL,
                    MOD_SYSTEM_PLL_API_TYPE_DEFAULT),
                .member_table = member_table_cpu_group_group_mid,
                .member_count = FWK_ARRAY_SIZE(member_table_cpu_group_group_mid),
                .member_api_id = FWK_ID_API_INIT(
                    FWK_MODULE_IDX_PIK_CLOCK,
                    MOD_PIK_CLOCK_API_TYPE_CSS),
                .initial_rate = 1893 * FWK_MHZ,
                .modulation_supported = true,
            }),
        },
    [CLOCK_CSS_IDX_CPU_GROUP_GROUP_BIG] =
        {
            .name = "CPU_GROUP_" TC_GROUP_BIG_NAME,
            .data = &((struct mod_css_clock_dev_config){
                .clock_type = MOD_CSS_CLOCK_TYPE_INDEXED,
                .rate_table = rate_table_cpu_group_group_big,
                .rate_count = FWK_ARRAY_SIZE(rate_table_cpu_group_group_big),
                .clock_switching_source =
                    MOD_PIK_CLOCK_CLUSCLK_SOURCE_TC3_PLL2,
                .pll_id = FWK_ID_ELEMENT_INIT(
                    FWK_MODULE_IDX_SYSTEM_PLL,
                    CLOCK_PLL_IDX_CPU_GROUP_BIG),
                .pll_api_id = FWK_ID_API_INIT(
                    FWK_MODULE_IDX_SYSTEM_PLL,
                    MOD_SYSTEM_PLL_API_TYPE_DEFAULT),
                .member_table = member_table_cpu_group_group_big,
                .member_count =
                    FWK_ARRAY_SIZE(member_table_cpu_group_group_big),
                .member_api_id = FWK_ID_API_INIT(
                    FWK_MODULE_IDX_PIK_CLOCK,
                    MOD_PIK_CLOCK_API_TYPE_CSS),
                .initial_rate = 2176 * FWK_MHZ,
                .modulation_supported = true,
            }),
        },
    [CLOCK_CSS_IDX_DPU] =
        {
            .name = "DPU",
            .data = &((struct mod_css_clock_dev_config){
                .clock_type = MOD_CSS_CLOCK_TYPE_NON_INDEXED,
                .clock_default_source =
                    MOD_PIK_CLOCK_ACLKDPU_SOURCE_DISPLAYPLLCLK,
                .clock_switching_source =
                    MOD_PIK_CLOCK_ACLKDPU_SOURCE_SYSREFCLK,
                .pll_id = FWK_ID_ELEMENT_INIT(
                    FWK_MODULE_IDX_SYSTEM_PLL,
                    CLOCK_PLL_IDX_DPU),
                .pll_api_id = FWK_ID_API_INIT(
                    FWK_MODULE_IDX_SYSTEM_PLL,
                    MOD_SYSTEM_PLL_API_TYPE_DEFAULT),
                .member_table = member_table_dpu,
                .member_count = FWK_ARRAY_SIZE(member_table_dpu),
                .member_api_id = FWK_ID_API_INIT(
                    FWK_MODULE_IDX_PIK_CLOCK,
                    MOD_PIK_CLOCK_API_TYPE_CSS),
                .initial_rate = 600 * FWK_MHZ,
                .modulation_supported = false,
            }),
        },
    [CLOCK_CSS_IDX_COUNT] = { 0 }, /* Termination description. */
};

static const struct fwk_element *css_clock_get_element_table(fwk_id_t module_id)
{
    return css_clock_element_table;
}

const struct fwk_module_config config_css_clock = {
    .elements = FWK_MODULE_DYNAMIC_ELEMENTS(css_clock_get_element_table),
};
