/*
 * Renesas SCP/MCP Software
 * Copyright (c) 2020-2021, Renesas Electronics Corporation. All rights
 * reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef RCAR4_IRQ_H
#define RCAR4_IRQ_H

#include <fwk_interrupt.h>

enum rcar4_irq {
    /**/
    MIN_IRQ = 16, // tbc
    VIRTUAL_TIMER_IRQ = 27,
    NS_PHYSICAL_TIMER_IRQ = 30,
    /**/
    MFIS_RT0_RT1_IRQ = 117+32,
    MFIS_AP0_RT0_IRQ = 124+32,
    /**/ /* The following numbers are virtual IID */
    SMCMH_IRQ_START = 1024, // tbc
    SMCMH_SECURE_IRQ = SMCMH_IRQ_START, /* SMC Secure */ // tbc
    SMCMH_LOW_PRIO_IRQ, /* SMC Low Priority */ // tbc
    SMCMH_HIGH_PRIO_IRQ, /* SMC High Priority */ // tbc
    SMCMH_IRQ_END,
    MAX_IRQ = SMCMH_IRQ_END,
    /**/
};

#endif /* RCAR4_IRQ_H */
