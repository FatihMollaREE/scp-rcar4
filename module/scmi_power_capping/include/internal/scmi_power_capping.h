/*
 * Arm SCP/MCP Software
 * Copyright (c) 2023, Arm Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * Description:
 *      SCMI power capping and monitoring protocol completer support.
 */

#ifndef INTERNAL_SCMI_POWER_CAPPING_H
#define INTERNAL_SCMI_POWER_CAPPING_H

#include "mod_power_allocator.h"
#include "mod_scmi_power_capping.h"

#include <fwk_event.h>
#include <fwk_id.h>

#include <stdint.h>

/*!
 * \addtogroup GroupModules Modules
 * \{
 */

/*!
 * \defgroup GroupSCMI_POWER_CAPPING SCMI power capping and monitoring Protocol
 * \{
 */

/*
 * SCMI power cap event IDs
 */
enum scmi_power_capping_event_idx {
#ifdef BUILD_HAS_SCMI_NOTIFICATIONS
    SCMI_POWER_CAPPING_EVENT_IDX_SET_CAP_NOTIFY_PROCESS,
#endif
#ifdef BUILD_HAS_SCMI_POWER_CAPPING_FAST_CHANNELS
    SCMI_POWER_CAPPING_EVENT_IDX_FAST_CHANNELS_PROCESS,
#endif
    SCMI_POWER_CAPPING_EVENT_COUNT,
};

/*!
 * \brief Power management related APIs.
 */
struct mod_scmi_power_capping_power_apis {
    /* Power allocator API */
    const struct mod_power_allocator_api *power_allocator_api;
};

struct mod_scmi_power_capping_domain_context {
    /* Power capping domain configuration */
    const struct mod_scmi_power_capping_domain_config *config;

    /*!
     * \brief Service ID
     *
     * \details Stores the service id corresponding to the agent that requested
     *      a power cap indicating that the domain is busy.
     *      It is set to FWK_ID_NONE when the domain is not used by an agent.
     */
    fwk_id_t cap_pending_service_id;

    /*!
     * \brief Power capping configuration support.
     */
    bool cap_config_support;
};

struct mod_scmi_power_capping_context {
    /* Table of power capping domain ctxs */
    struct mod_scmi_power_capping_domain_context
        *power_capping_domain_ctx_table;
    /* Power capping domain count */
    uint32_t domain_count;
};

/*!
 * \}
 */

/*!
 * \}
 */

#endif /* INTERNAL_SCMI_POWER_CAPPING_H */
