/*
 * Arm SCP/MCP Software
 * Copyright (c) 2024, Arm Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * Description:
 *     SCP Power Control registers
 */

#ifndef SCP_PWRCTRL_H
#define SCP_PWRCTRL_H

#include "scp_css_mmap.h"

#include <fwk_macros.h>

#include <stdint.h>

/*!
 * \brief SCP Power Control register definitions
 */

// clang-format off
struct scp_power_control_reg {
            uint8_t   RESERVED0[0x10 - 0x0];
    FWK_RW  uint32_t  RESET_SYNDROME;
            uint8_t   RESERVED1[0x200 - 0x01C];
    FWK_R   uint32_t  SCP2LCP_MHU_PBX_INT_SOURCE_GROUP;
    FWK_R   uint32_t  SCP2LCP_MHU_PBX_INT_SOURCE_GROUP0;
    FWK_R   uint32_t  SCP2LCP_MHU_PBX_INT_SOURCE_GROUP1;
    FWK_R   uint32_t  SCP2LCP_MHU_PBX_INT_SOURCE_GROUP2;
    FWK_R   uint32_t  SCP2LCP_MHU_PBX_INT_SOURCE_GROUP3;
    FWK_R   uint32_t  SCP2LCP_MHU_PBX_INT_SOURCE_GROUP4;
    FWK_R   uint32_t  SCP2LCP_MHU_PBX_INT_SOURCE_GROUP5;
    FWK_R   uint32_t  SCP2LCP_MHU_PBX_INT_SOURCE_GROUP6;
    FWK_R   uint32_t  SCP2LCP_MHU_PBX_INT_SOURCE_GROUP7;
    FWK_R   uint32_t  LCP2SCP_MHU_MBX_INT_SOURCE_GROUP;
    FWK_R   uint32_t  LCP2SCP_MHU_MBX_INT_SOURCE_GROUP0;
    FWK_R   uint32_t  LCP2SCP_MHU_MBX_INT_SOURCE_GROUP1;
    FWK_R   uint32_t  LCP2SCP_MHU_MBX_INT_SOURCE_GROUP2;
    FWK_R   uint32_t  LCP2SCP_MHU_MBX_INT_SOURCE_GROUP3;
    FWK_R   uint32_t  LCP2SCP_MHU_MBX_INT_SOURCE_GROUP4;
    FWK_R   uint32_t  LCP2SCP_MHU_MBX_INT_SOURCE_GROUP5;
    FWK_R   uint32_t  LCP2SCP_MHU_MBX_INT_SOURCE_GROUP6;
    FWK_R   uint32_t  LCP2SCP_MHU_MBX_INT_SOURCE_GROUP7;
            uint8_t   RESERVED2[0x810 - 0x248];
    FWK_RW  uint32_t  CORECLK_CTRL;
    FWK_RW  uint32_t  CORECLK_DIV1;
            uint8_t   RESERVED3[0x820 - 0x818];
    FWK_RW  uint32_t  ACLK_CTRL;
    FWK_RW  uint32_t  ACLK_DIV1;
            uint8_t   RESERVED4[0x830 - 0x828];
    FWK_RW  uint32_t  GTSYNCCLK_CTRL;
    FWK_RW  uint32_t  GTSYNCCLK_DIV1;
            uint8_t   RESERVED5[0x840 - 0x838];
    FWK_RW  uint32_t  LCPCLK_CTRL;
    FWK_RW  uint32_t  LCPCLK_DIV1;
            uint8_t   RESERVED6[0xA00 - 0x848];
    FWK_R   uint32_t  CLKFORCE_STATUS;
    FWK_W   uint32_t  CLKFORCE_SET;
    FWK_W   uint32_t  CLKFORCE_CLEAR;
            uint8_t   RESERVED7[0xC10 - 0xA0C];
    FWK_W   uint32_t  SMCF_MGI_TRIGGER;
            uint8_t   RESERVED8[0xC20 - 0xC14];
    FWK_R   uint32_t  SRAMECC_ERRFR;
    FWK_R   uint32_t  SRAMECC_ERRFR_H;
    FWK_RW  uint32_t  SRAMECC_ERRCTRL;
    FWK_RW  uint32_t  SRAMECC_ERRCTRL_H;
    FWK_RW  uint32_t  SRAMECC_ERRSTATUS;
    FWK_RW  uint32_t  SRAMECC_ERRSTATUS_H;
    FWK_RW  uint32_t  SRAMECC_ERRADDR;
    FWK_RW  uint32_t  SRAMECC_ERRADDR_H;
            uint8_t   RESERVED9[0xC48 - 0xC40];
    FWK_RW  uint32_t  SRAMECC_ERRMISC1;
    FWK_RW  uint32_t  SRAMECC_ERRMISC1_H;
            uint8_t   RESERVED10[0xC60 - 0xC50];
    FWK_R   uint32_t  SYSNCI_PMU_CONS_INT_STATUS;
    FWK_R   uint32_t  SYSNCI_CONS_INT_STATUS;
    FWK_R   uint32_t  INTNCI_PMU_CONS_INT_STATUS;
    FWK_R   uint32_t  INTNCI_CONS_INT_STATUS;
    FWK_R   uint32_t  PERIPHNCI_PMU_CONS_INT_STATUS;
    FWK_R   uint32_t  PERIPHNCI_CONS_INT_STATUS;
            uint8_t   RESERVED11[0xFC0 - 0xC7A];
    FWK_R   uint32_t  PWR_CTRL_CONFIG;
            uint8_t   RESERVED12[0xFD0 - 0xFC4];
    FWK_R   uint32_t  PERIPHERAL_ID4;
    FWK_R   uint32_t  PERIPHERAL_ID5;
    FWK_R   uint32_t  PERIPHERAL_ID6;
    FWK_R   uint32_t  PERIPHERAL_ID7;
    FWK_R   uint32_t  PERIPHERAL_ID0;
    FWK_R   uint32_t  PERIPHERAL_ID1;
    FWK_R   uint32_t  PERIPHERAL_ID2;
    FWK_R   uint32_t  PERIPHERAL_ID3;
    FWK_R   uint32_t  COMPONENT_ID0;
    FWK_R   uint32_t  COMPONENT_ID1;
    FWK_R   uint32_t  COMPONENT_ID2;
    FWK_R   uint32_t  COMPONENT_ID3;
};
// clang-format on

/* Pointer to SCP Power Control register block */
#define SCP_PWRCTRL_PTR ((struct scp_power_control_reg *)SCP_POWER_CONTROL_BASE)

#endif /* SCP_PWRCTRL_H */
