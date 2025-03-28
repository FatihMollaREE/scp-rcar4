/*
 * Renesas SCP/MCP Software
 * Copyright (c) 2020-2024, Renesas Electronics Corporation. All rights
 * reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <rcar4_common.h>
#include <rcar4_pd_sysc.h>

#include <fwk_mmio.h>
#include <fwk_status.h>

#include <stddef.h>

/*****************************************************************************
 * LOCAL FUNCTIONS fatih: nix gemacht
 *****************************************************************************/
static int rcar4_sysc_pwr_on_off(struct rcar4_sysc_pd_ctx *pd_ctx, bool on)
{
    unsigned int sr_bit, reg_offs;
    int k;

    if (on) {
        sr_bit = SYSCSR_PONENB;
        reg_offs = PWRONCR_OFFS;
    } else {
        sr_bit = SYSCSR_POFFENB;
        reg_offs = PWROFFCR_OFFS;
    }

    /* Wait until SYSC is ready to accept a power request */
    for (k = 0; k < SYSCSR_RETRIES; k++) {
        if (fwk_mmio_read_32(SYSC_BASE_ADDR + SYSCSR) & BIT_SHIFT(sr_bit))
            break;
        udelay(SYSCSR_DELAY_US);
    }

    if (k == SYSCSR_RETRIES) {
        return FWK_E_TIMEOUT;
    }

    /* Submit power shutoff or power resume request */
    udelay(SYSCSR_DELAY_US);

    fwk_mmio_write_32(
        (SYSC_BASE_ADDR + pd_ctx->config->chan_offs + reg_offs),
        BIT_SHIFT(pd_ctx->config->chan_bit));
    return 0;
}

int rcar4_sysc_power(struct rcar4_sysc_pd_ctx *pd_ctx, bool on)
{
    unsigned int isr_mask = BIT_SHIFT(pd_ctx->config->isr_bit);
    unsigned int chan_mask = BIT_SHIFT(pd_ctx->config->chan_bit);
    unsigned int status;
    int ret = 0;
    int k;
    uint32_t syscier, syscimr;

    syscimr = fwk_mmio_read_32(SYSC_BASE_ADDR + SYSCIMR);
    syscier = fwk_mmio_read_32(SYSC_BASE_ADDR + SYSCIER);
    fwk_mmio_write_32((SYSC_BASE_ADDR + SYSCIMR), (syscimr | isr_mask));
    fwk_mmio_write_32((SYSC_BASE_ADDR + SYSCIER), (syscier | isr_mask));
    fwk_mmio_write_32((SYSC_BASE_ADDR + SYSCISCR), isr_mask);

    /* Submit power shutoff or resume request until it was accepted */
    for (k = 0; k < PWRER_RETRIES; k++) {
        ret = rcar4_sysc_pwr_on_off(pd_ctx, on);
        if (ret)
            return ret;

        status = fwk_mmio_read_32(
            SYSC_BASE_ADDR + pd_ctx->config->chan_offs + PWRER_OFFS);
        if (!(status & chan_mask)) {
            break;
        }

        udelay(PWRER_DELAY_US);
    }

    if (k == PWRER_RETRIES)
        return FWK_E_BUSY;

    /* Wait until the power shutoff or resume request has completed * */
    for (k = 0; k < SYSCISR_RETRIES; k++) {
        if (fwk_mmio_read_32(SYSC_BASE_ADDR + SYSCISR) & isr_mask)
            break;
        udelay(SYSCISR_DELAY_US);
    }

    if (k == SYSCISR_RETRIES) {
        ret = FWK_E_BUSY;
    }

    fwk_mmio_write_32((SYSC_BASE_ADDR + SYSCISCR), isr_mask);

    if (on)
        pd_ctx->current_state = MOD_PD_STATE_ON;
    else
        pd_ctx->current_state = MOD_PD_STATE_OFF;

    return ret;
}

int rcar4_sysc_power_get(struct rcar4_sysc_pd_ctx *pd_ctx, unsigned int *statee)
{
    *statee = pd_ctx->current_state;

    return FWK_SUCCESS;
}
