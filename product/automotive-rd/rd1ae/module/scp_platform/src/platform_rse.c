/*
 * Arm SCP/MCP Software
 * Copyright (c) 2024, Arm Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * Description:
 *     SCP Platform Support - implements support for communication with RSE.
 */

#include <internal/scp_platform.h>

#include <mod_scp_platform.h>
#include <mod_timer.h>
#include <mod_transport.h>

#include <fwk_id.h>
#include <fwk_log.h>
#include <fwk_module.h>
#include <fwk_status.h>

#include <stdbool.h>

/* Platform RSE context */
struct platform_rse_ctx {
    /* Pointer to the module config data */
    const struct mod_scp_platform_config *config;

    /* Transport API to send/respond to a message */
    const struct mod_transport_firmware_api *transport_api;

    /* Timer API */
    const struct mod_timer_api *timer_api;

    /* Flag to indicate that the RSE doorbell has been received */
    volatile bool rse_doorbell_received;
};

static struct platform_rse_ctx ctx;

/* Utility function to check if SCP platform has received doorbell from RSE */
static bool is_rse_doorbell_received(void *unused)
{
    return ctx.rse_doorbell_received;
}

/*
 * Module 'transport' signal interface implementation.
 */
static int signal_error(fwk_id_t unused)
{
    FWK_LOG_ERR(MOD_NAME "Error! Invalid response received from RSE");

    ctx.transport_api->release_transport_channel_lock(ctx.config->transport_id);

    return FWK_SUCCESS;
}

static int signal_message(fwk_id_t unused)
{
    FWK_LOG_INFO(MOD_NAME "Received doorbell event from RSE");

    ctx.transport_api->release_transport_channel_lock(ctx.config->transport_id);

    /* Set the flag to indicate that the RSE initialization is complete */
    ctx.rse_doorbell_received = true;

    return FWK_SUCCESS;
}

const struct mod_transport_firmware_signal_api platform_transport_signal_api = {
    .signal_error = signal_error,
    .signal_message = signal_message,
};

/*
 * Helper function to retrieve the 'transport' module signal API.
 */
const void *get_platform_transport_signal_api(void)
{
    return &platform_transport_signal_api;
}

/*
 * RSE has to be notified that SYSTOP is powered up and so it can enable GPC
 * bypass in the system control block.
 */
int notify_rse_and_wait_for_response(void)
{
    int status;

    /*
     * Trigger doorbell to RSE to indicate that the SYSTOP domain is ON.
     */
    status = ctx.transport_api->trigger_interrupt(ctx.config->transport_id);
    if (status != FWK_SUCCESS) {
        FWK_LOG_ERR(MOD_NAME
                    "Error! Failed to send SYSTOP enabled message to RSE");
        return status;
    }

    /*
     * Wait till a doorbell from RSE is received. This doorbell event indicates
     * that the RSE has initialized the GPC adnd completed the peripheral
     * NI-Tower setup.
     */
    status = ctx.timer_api->wait(
        ctx.config->timer_id,
        ctx.config->rse_sync_wait_us,
        is_rse_doorbell_received,
        NULL);
    if (status != FWK_SUCCESS) {
        FWK_LOG_ERR(MOD_NAME "Error! No response from RSE for SYSTOP sync");
    }

    return status;
}

/*
 * Bind to timer and transport module to communicate with RSE.
 */
int platform_rse_bind(const struct mod_scp_platform_config *config)
{
    int status;
    fwk_id_t timer_api_id;
    fwk_id_t transport_api_id;

    ctx.config = config;

    timer_api_id = FWK_ID_API(FWK_MODULE_IDX_TIMER, MOD_TIMER_API_IDX_TIMER);
    status = fwk_module_bind(config->timer_id, timer_api_id, &ctx.timer_api);
    if (status != FWK_SUCCESS) {
        return status;
    }

    transport_api_id =
        FWK_ID_API(FWK_MODULE_IDX_TRANSPORT, MOD_TRANSPORT_API_IDX_FIRMWARE);
    return fwk_module_bind(
        config->transport_id, transport_api_id, &ctx.transport_api);
}
