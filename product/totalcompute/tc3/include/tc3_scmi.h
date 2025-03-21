/*
 * Arm SCP/MCP Software
 * Copyright (c) 2023-2024, Arm Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * Description:
 *     Definitions for SCMI and TRANSPORT module configurations.
 */

#ifndef SCP_TC3_SCMI_H
#define SCP_TC3_SCMI_H

/* SCMI agent identifiers */
enum scp_tc3_scmi_agent_id {
    /* 0 is reserved for the platform */
    SCP_SCMI_AGENT_ID_OSPM = 1,
    SCP_SCMI_AGENT_ID_PSCI,
    SCP_SCMI_AGENT_ID_COUNT
};

/* SCMI service indexes */
enum scp_tc3_scmi_service_idx {
    SCP_TC3_SCMI_SERVICE_IDX_PSCI,
    SCP_TC3_SCMI_SERVICE_IDX_OSPM_A2P,
#ifdef BUILD_HAS_SCMI_NOTIFICATIONS
    SCP_TC3_SCMI_SERVICE_IDX_OSPM_P2A,
#endif
    SCP_TC3_SCMI_SERVICE_IDX_COUNT,
};

/* SCP<->AP Fast channels indexes */
enum tc3_plat_fch_idx {
    /* Fast channels from 0 - 3 */
    TC3_PLAT_FCH_GROUP_LITTLE_LEVEL_SET,
    TC3_PLAT_FCH_GROUP_LITTLE_LIMIT_SET,
    TC3_PLAT_FCH_GROUP_LITTLE_LEVEL_GET,
    TC3_PLAT_FCH_GROUP_LITTLE_LIMIT_GET,

    /* Fast channels from 4 - 7 */
    TC3_PLAT_FCH_GROUP_MID_LEVEL_SET,
    TC3_PLAT_FCH_GROUP_MID_LIMIT_SET,
    TC3_PLAT_FCH_GROUP_MID_LEVEL_GET,
    TC3_PLAT_FCH_GROUP_MID_LIMIT_GET,

    /* Fast channels from 8 - 11 */
    TC3_PLAT_FCH_GROUP_BIG_LEVEL_SET,
    TC3_PLAT_FCH_GROUP_BIG_LIMIT_SET,
    TC3_PLAT_FCH_GROUP_BIG_LEVEL_GET,
    TC3_PLAT_FCH_GROUP_BIG_LIMIT_GET,

    /* Fast chanels from 12 - 15*/
    TC3_PLAT_FCH_GPU_LEVEL_SET,
    TC3_PLAT_FCH_GPU_LIMIT_SET,
    TC3_PLAT_FCH_GPU_LEVEL_GET,
    TC3_PLAT_FCH_GPU_LIMIT_GET,

    TC3_PLAT_FCH_COUNT,
};

/* SCP <-> AP Transport channels */
enum tc3_transport_channel_idx {
    TC3_TRANSPORT_SCMI_SERVICE_PSCI,
    TC3_TRANSPORT_SCMI_SERVICE_OSPM_A2P,
    TC3_TRANSPORT_SCMI_SERVICE_OSPM_P2A,

#if defined(BUILD_HAS_SCMI_PERF_FAST_CHANNELS)
    TC3_TRANSPORT_SCMI_PERF_FCH_GROUP_LITTLE_LEVEL_SET,
    TC3_TRANSPORT_SCMI_PERF_FCH_GROUP_LITTLE_LIMIT_SET,
    TC3_TRANSPORT_SCMI_PERF_FCH_GROUP_LITTLE_LEVEL_GET,
    TC3_TRANSPORT_SCMI_PERF_FCH_GROUP_LITTLE_LIMIT_GET,

    TC3_TRANSPORT_SCMI_PERF_FCH_GROUP_MID_LEVEL_SET,
    TC3_TRANSPORT_SCMI_PERF_FCH_GROUP_MID_LIMIT_SET,
    TC3_TRANSPORT_SCMI_PERF_FCH_GROUP_MID_LEVEL_GET,
    TC3_TRANSPORT_SCMI_PERF_FCH_GROUP_MID_LIMIT_GET,

    TC3_TRANSPORT_SCMI_PERF_FCH_GROUP_BIG_LEVEL_SET,
    TC3_TRANSPORT_SCMI_PERF_FCH_GROUP_BIG_LIMIT_SET,
    TC3_TRANSPORT_SCMI_PERF_FCH_GROUP_BIG_LEVEL_GET,
    TC3_TRANSPORT_SCMI_PERF_FCH_GROUP_BIG_LIMIT_GET,

    TC3_TRANSPORT_SCMI_PERF_FCH_GPU_LEVEL_SET,
    TC3_TRANSPORT_SCMI_PERF_FCH_GPU_LIMIT_SET,
    TC3_TRANSPORT_SCMI_PERF_FCH_GPU_LEVEL_GET,
    TC3_TRANSPORT_SCMI_PERF_FCH_GPU_LIMIT_GET,
#endif
    TC3_TRANSPORT_CHANNELS_COUNT,
};

#endif /* SCP_TC3_SCMI_H */
