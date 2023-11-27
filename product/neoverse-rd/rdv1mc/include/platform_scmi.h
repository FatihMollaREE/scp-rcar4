/*
 * Arm SCP/MCP Software
 * Copyright (c) 2020-2024, Arm Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * Description:
 *     Definitions for SCMI and TRANSPORT module configurations.
 */

#ifndef SCP_PLATFORM_SCMI_H
#define SCP_PLATFORM_SCMI_H

/* SCMI agent identifiers */
enum scp_platform_scmi_agent_id {
    /* 0 is reserved for the platform */
    SCP_SCMI_AGENT_ID_PSCI = 1,
};

/* SCMI service indexes */
enum scp_platform_scmi_service_idx {
    SCP_PLATFORM_SCMI_SERVICE_IDX_PSCI,
    SCP_PLATFORM_SCMI_SERVICE_IDX_COUNT,
};

/* SCP<->AP Fast channels indexes */
#ifdef BUILD_HAS_MOD_TRANSPORT_FC
enum rdv1mc_plat_fch_idx {
    RDV1MC_PLAT_FCH_CPU0_LEVEL_SET,
    RDV1MC_PLAT_FCH_CPU0_LIMIT_SET,
    RDV1MC_PLAT_FCH_CPU0_LEVEL_GET,
    RDV1MC_PLAT_FCH_CPU0_LIMIT_GET,

    RDV1MC_PLAT_FCH_CPU1_LEVEL_SET,
    RDV1MC_PLAT_FCH_CPU1_LIMIT_SET,
    RDV1MC_PLAT_FCH_CPU1_LEVEL_GET,
    RDV1MC_PLAT_FCH_CPU1_LIMIT_GET,

    RDV1MC_PLAT_FCH_CPU2_LEVEL_SET,
    RDV1MC_PLAT_FCH_CPU2_LIMIT_SET,
    RDV1MC_PLAT_FCH_CPU2_LEVEL_GET,
    RDV1MC_PLAT_FCH_CPU2_LIMIT_GET,

    RDV1MC_PLAT_FCH_CPU3_LEVEL_SET,
    RDV1MC_PLAT_FCH_CPU3_LIMIT_SET,
    RDV1MC_PLAT_FCH_CPU3_LEVEL_GET,
    RDV1MC_PLAT_FCH_CPU3_LIMIT_GET,

    RDV1MC_PLAT_FCH_COUNT,
};
#endif

/* SCP <-> AP Transport channels */
enum rdv1mc_transport_channel_idx {
    RDV1MC_TRANSPORT_SCMI_SERVICE_PSCI,

#if defined(BUILD_HAS_SCMI_PERF_FAST_CHANNELS)
    RDV1MC_TRANSPORT_SCMI_PERF_FCH_CPU0_LEVEL_SET,
    RDV1MC_TRANSPORT_SCMI_PERF_FCH_CPU0_LIMIT_SET,
    RDV1MC_TRANSPORT_SCMI_PERF_FCH_CPU0_LEVEL_GET,
    RDV1MC_TRANSPORT_SCMI_PERF_FCH_CPU0_LIMIT_GET,

    RDV1MC_TRANSPORT_SCMI_PERF_FCH_CPU1_LEVEL_SET,
    RDV1MC_TRANSPORT_SCMI_PERF_FCH_CPU1_LIMIT_SET,
    RDV1MC_TRANSPORT_SCMI_PERF_FCH_CPU1_LEVEL_GET,
    RDV1MC_TRANSPORT_SCMI_PERF_FCH_CPU1_LIMIT_GET,

    RDV1MC_TRANSPORT_SCMI_PERF_FCH_CPU2_LEVEL_SET,
    RDV1MC_TRANSPORT_SCMI_PERF_FCH_CPU2_LIMIT_SET,
    RDV1MC_TRANSPORT_SCMI_PERF_FCH_CPU2_LEVEL_GET,
    RDV1MC_TRANSPORT_SCMI_PERF_FCH_CPU2_LIMIT_GET,

    RDV1MC_TRANSPORT_SCMI_PERF_FCH_CPU3_LEVEL_SET,
    RDV1MC_TRANSPORT_SCMI_PERF_FCH_CPU3_LIMIT_SET,
    RDV1MC_TRANSPORT_SCMI_PERF_FCH_CPU3_LEVEL_GET,
    RDV1MC_TRANSPORT_SCMI_PERF_FCH_CPU3_LIMIT_GET,
#endif
    RDV1MC_TRANSPORT_CHANNELS_COUNT,
};

#endif /* SCP_PLATFORM_SCMI_H */
