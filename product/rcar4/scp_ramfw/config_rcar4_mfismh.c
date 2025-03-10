/*
 * Renesas SCP/MCP Software
 * Copyright (c) 2020-2021, Renesas Electronics Corporation. All rights
 * reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <rcar4_irq.h>
#include <rcar4_mfismh.h>
#include <rcar4_mmap.h>

#include <mod_rcar4_mfismh.h>

#include <fwk_element.h>
#include <fwk_id.h>
#include <fwk_module.h>

static const struct fwk_element mfismh_element_table[] = {
    
    [RCAR4_MFISMH_DEVICE_IDX_S] = { .name = "MFISMH_S",
                                    .sub_element_count = 1,
                                    .data =
                                        &((struct mod_rcar4_mfismh_device_config){
                                            .irq = MFIS_RT0_RT1_IRQ,
                                        }) },
    [RCAR4_MFISMH_DEVICE_IDX_NS_1] = { .name = "MSIFMH_NS_1",
                                      .sub_element_count = 1,
                                      .data = &((
                                          struct mod_rcar4_mfismh_device_config){
                                          .irq = MFIS_RT0_RT1_IRQ,
                                      }) },
    [RCAR4_MFISMH_DEVICE_IDX_NS_2] = { .name = "MSIFMH_NS_2",
                                      .sub_element_count = 1,
                                      .data = &((
                                          struct mod_rcar4_mfismh_device_config){
                                          .irq = MFIS_RT0_RT1_IRQ,
                                      }) },
    [RCAR4_MFISMH_DEVICE_IDX_NS_3] = { .name = "MSIFMH_NS_3",
                                      .sub_element_count = 1,
                                      .data = &((
                                          struct mod_rcar4_mfismh_device_config){
                                          .irq = MFIS_AP0_RT0_IRQ,
                                      }) },
    [RCAR4_MFISMH_DEVICE_IDX_NS_4] = { .name = "MSIFMH_NS_4",
                                      .sub_element_count = 1,
                                      .data = &((
                                          struct mod_rcar4_mfismh_device_config){
                                          .irq = MFIS_AP0_RT0_IRQ,
                                      }) },
    
    [RCAR4_MFISMH_DEVICE_IDX_COUNT] = {},
};

static const struct fwk_element *mfismh_get_element_table(fwk_id_t module_id)
{
    return mfismh_element_table;
}

struct fwk_module_config config_rcar4_mfismh = {
    .elements = FWK_MODULE_DYNAMIC_ELEMENTS(mfismh_get_element_table),
};
