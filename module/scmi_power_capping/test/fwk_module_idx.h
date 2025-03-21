/*
 * Arm SCP/MCP Software
 * Copyright (c) 2023-2024, Arm Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef TEST_FWK_MODULE_MODULE_IDX_H
#define TEST_FWK_MODULE_MODULE_IDX_H

#include <fwk_id.h>

enum fwk_module_idx {
    FWK_MODULE_IDX_SCMI,
    FWK_MODULE_IDX_POWER_CAPPING,
    FWK_MODULE_IDX_SCMI_POWER_CAPPING,
    FWK_MODULE_IDX_POWER_COORDINATOR,
    FWK_MODULE_IDX_POWER_METER,
#ifdef BUILD_HAS_FAST_CHANNELS
    FWK_MODULE_IDX_TRANSPORT,
#endif
#ifdef BUILD_HAS_MOD_RESOURCE_PERMS
    FWK_MODULE_IDX_RESOURCE_PERMS,
#endif
    FWK_MODULE_IDX_COUNT,
};

static const fwk_id_t fwk_module_id_scmi =
    FWK_ID_MODULE_INIT(FWK_MODULE_IDX_SCMI);

static const fwk_id_t fwk_module_id_power_capping =
    FWK_ID_MODULE_INIT(FWK_MODULE_IDX_POWER_CAPPING);

static const fwk_id_t fwk_module_id_scmi_power_capping =
    FWK_ID_MODULE_INIT(FWK_MODULE_IDX_SCMI_POWER_CAPPING);

#ifdef BUILD_HAS_FAST_CHANNELS
static const fwk_id_t fwk_module_id_transport =
    FWK_ID_MODULE_INIT(FWK_MODULE_IDX_TRANSPORT);
#endif

#ifdef BUILD_HAS_MOD_RESOURCE_PERMS
static const fwk_id_t fwk_module_id_resource_perms =
    FWK_ID_MODULE(FWK_MODULE_IDX_RESOURCE_PERMS);
#endif

#endif /* TEST_FWK_MODULE_MODULE_IDX_H */
