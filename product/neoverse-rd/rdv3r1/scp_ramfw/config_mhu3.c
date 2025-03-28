/*
 * Arm SCP/MCP Software
 * Copyright (c) 2024, Arm Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * Description:
 *     Configuration data for module 'mhu3'.
 */

#include "scp_cfgd_mhu3.h"
#include "scp_css_mmap.h"

#include <mod_mhu3.h>

#include <fwk_element.h>
#include <fwk_id.h>
#include <fwk_macros.h>
#include <fwk_module.h>

#include <fmw_cmsis.h>

/* AP<-->SCP Secure MHUv3 channel configuration */
struct mod_mhu3_channel_config scp2ap_s_ch_config[] = {
    /* PBX CH 0, FLAG 0, MBX CH 0, FLAG 0 */
    MOD_MHU3_INIT_DBCH(0, 0, 0, 0),
};

/* SCP<-->RSS MHUv3 channel configuration */
struct mod_mhu3_channel_config scp2rss_ch_config[] = {
    /* PBX CH 1, FLAG 0, MBX CH 1, FLAG 0 */
    MOD_MHU3_INIT_DBCH(1, 0, 1, 0),
};

/* Module element table */
static const struct fwk_element mhu_element_table[] = {
    [SCP_CFGD_MOD_MHU3_EIDX_SCP_AP_S] = {
        .name = "SCP2AP_NS_MHU",
        .sub_element_count = FWK_ARRAY_SIZE(scp2ap_s_ch_config),
        .data = &(struct mod_mhu3_device_config) {
            .irq = (unsigned int) MHU3_AP2SCP_IRQ_S,
            .in = SCP_AP2SCP_MHUV3_RCV_S_BASE,
            .out = SCP_SCP2AP_MHUV3_SEND_S_BASE,
            .channels = &scp2ap_s_ch_config[0],
            .timer_id = FWK_ID_ELEMENT(FWK_MODULE_IDX_TIMER, 0),
        },
    },
   [SCP_CFGD_MOD_MHU3_EIDX_SCP_RSS] = {
        .name = "SCP2RSS_MHU",
        .sub_element_count = FWK_ARRAY_SIZE(scp2rss_ch_config),
        .data = &(struct mod_mhu3_device_config) {
            .irq = (unsigned int) MHU3_RSS2SCP_IRQ,
            .in = SCP_RSS2SCP_MHUV3_RCV_BASE,
            .out = SCP_SCP2RSS_MHUV3_SEND_BASE,
            .channels = &scp2rss_ch_config[0],
            .timer_id = FWK_ID_ELEMENT(FWK_MODULE_IDX_TIMER, 0),
        },
    },
    [SCP_CFGD_MOD_MHU3_EIDX_COUNT] = { 0 },
};

static const struct fwk_element *get_element_table(fwk_id_t module_id)
{
    return mhu_element_table;
}

struct fwk_module_config config_mhu3 = {
    .elements = FWK_MODULE_DYNAMIC_ELEMENTS(get_element_table),
};
