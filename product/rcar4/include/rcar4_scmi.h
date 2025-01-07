/*
 * Renesas SCP/MCP Software
 * Copyright (c) 2020-2021, Renesas Electronics Corporation. All rights
 * reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef RCAR4_SCMI_H
#define RCAR4_SCMI_H

/* SCMI agent identifiers */
enum rcar4_scmi_agent_id {
    /* 0 is reserved for the platform */
    SCMI_AGENT_ID_OSPM = 1,
    SCMI_AGENT_ID_PSCI,
    SCMI_AGENT_ID_VMM,
    SCMI_AGENT_ID_VM1,
    SCMI_AGENT_ID_VM2,
    SCMI_AGENT_ID_COUNT,
};

/* SCMI service indexes */
enum rcar4_scmi_service_idx {
    RCAR4_SCMI_SERVICE_IDX_PSCI,
    RCAR4_SCMI_SERVICE_IDX_OSPM,
    RCAR4_SCMI_SERVICE_IDX_VMM,
    RCAR4_SCMI_SERVICE_IDX_VM1,
    RCAR4_SCMI_SERVICE_IDX_VM2,
    RCAR4_SCMI_SERVICE_IDX_COUNT,
};
#endif /* RCAR4_SCMI_H */
