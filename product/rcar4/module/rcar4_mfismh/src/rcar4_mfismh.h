/*
 * Renesas SCP/MCP Software
 * Copyright (c) 2020-2021, Renesas Electronics Corporation. All rights
 * reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef RCAR4_MFISMH_H
#define RCAR4_MFISMH_H

#include <mod_rcar4_mfismh.h>

#include <fwk_macros.h>

#include <stdint.h>

// nach excel sind interupts von mfis bei ca. 117 oder 916? anders als bei rcar 3 sowie unten

#define MFIS_IRQ_MIN (117U)
#define MFIS_IRQ_MAX (MFIS_IRQ_MIN + 13U)
#define MFIS_IRQ2NO(irn) (irn - MFIS_IRQ_MIN)
#define IS_MFIS_IRQ(irn) \
    (((irn < MFIS_IRQ_MIN) || (irn > MFIS_IRQ_MAX)) ? 0 : 1)

/*!
 * \brief SMCMB Register Definitions
 */
struct mfismh_reg {
    /*! Communication Control Register(->R) */
    FWK_R uint32_t reserve;
    /*! Communication Control Register(->CA) */
    FWK_W union {
        struct {
            uint32_t eir : 1;
            uint32_t eic : 15;
            uint32_t reserve : 16;
        } CCR;
        uint32_t CCR2CA;
    };
};

#endif /* RCAR4_MFISMH_H */
