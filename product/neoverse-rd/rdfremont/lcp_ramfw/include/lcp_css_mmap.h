/*
 * Arm SCP/MCP Software
 * Copyright (c) 2022-2024, Arm Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * Description:
 *     Base address definitions for the LCP's sub-system and access extending
 *     into the rest of the CSS.
 */

#ifndef LCP_CSS_MMAP_H
#define LCP_CSS_MMAP_H

#include <fwk_macros.h>

#define LCP_ITCM_SIZE (64 * 1024)
#define LCP_DTCM_SIZE (32 * 1024)

#define LCP_ITCM_S_BASE 0x10000000
#define LCP_DTCM_S_BASE 0x30000000

#define LCP_CORE_ITCM_REGION_START LCP_ITCM_S_BASE
#define LCP_CORE_ITCM_REGION_END   (LCP_ITCM_S_BASE + LCP_ITCM_SIZE - 1)

#define LCP_CORE_DTCM_REGION_START LCP_DTCM_S_BASE
#define LCP_CORE_DTCM_REGION_END   (LCP_DTCM_S_BASE + LCP_DTCM_SIZE - 1)

#define LCP_CORE_PERIPHERAL_REGION_START 0x30010000
#define LCP_CORE_PERIPHERAL_REGION_END   0x6FFFFFFF

#define LCP_SRAM_REGION_START 0x70000000
#define LCP_SRAM_REGION_END   0xB007FFFF

#define LCP_DEVICE_REGION_START 0xB0080000
#define LCP_DEVICE_REGION_END   0xFFFFFFFF

#define LCP_TIMER_BASE_NS UINT32_C(0x48000000)
#define LCP_TIMER_BASE_S  UINT32_C(0x5802F000)

#define LCP_AP_MHU_MBX_BASE 0xB00E0000

#define LCP_UART_BASE 0xB2000000

#define SCP_MHU3_PBX_MBX_SIZE (64 * 1024)

#define LCP_SCP_MHU_BASE 0xB3000000

#define LCP0_SCP_MHU_PBX_BASE  LCP_SCP_MHU_BASE
#define LCP0_SCP_MHU_MBX_BASE  (LCP0_SCP_MHU_PBX_BASE + SCP_MHU3_PBX_MBX_SIZE)
#define LCP1_SCP_MHU_PBX_BASE  (LCP0_SCP_MHU_MBX_BASE + SCP_MHU3_PBX_MBX_SIZE)
#define LCP1_SCP_MHU_MBX_BASE  (LCP1_SCP_MHU_PBX_BASE + SCP_MHU3_PBX_MBX_SIZE)
#define LCP2_SCP_MHU_PBX_BASE  (LCP1_SCP_MHU_MBX_BASE + SCP_MHU3_PBX_MBX_SIZE)
#define LCP2_SCP_MHU_MBX_BASE  (LCP2_SCP_MHU_PBX_BASE + SCP_MHU3_PBX_MBX_SIZE)
#define LCP3_SCP_MHU_PBX_BASE  (LCP2_SCP_MHU_MBX_BASE + SCP_MHU3_PBX_MBX_SIZE)
#define LCP3_SCP_MHU_MBX_BASE  (LCP3_SCP_MHU_PBX_BASE + SCP_MHU3_PBX_MBX_SIZE)
#define LCP4_SCP_MHU_PBX_BASE  (LCP3_SCP_MHU_MBX_BASE + SCP_MHU3_PBX_MBX_SIZE)
#define LCP4_SCP_MHU_MBX_BASE  (LCP4_SCP_MHU_PBX_BASE + SCP_MHU3_PBX_MBX_SIZE)
#define LCP5_SCP_MHU_PBX_BASE  (LCP4_SCP_MHU_MBX_BASE + SCP_MHU3_PBX_MBX_SIZE)
#define LCP5_SCP_MHU_MBX_BASE  (LCP5_SCP_MHU_PBX_BASE + SCP_MHU3_PBX_MBX_SIZE)
#define LCP6_SCP_MHU_PBX_BASE  (LCP5_SCP_MHU_MBX_BASE + SCP_MHU3_PBX_MBX_SIZE)
#define LCP6_SCP_MHU_MBX_BASE  (LCP6_SCP_MHU_PBX_BASE + SCP_MHU3_PBX_MBX_SIZE)
#define LCP7_SCP_MHU_PBX_BASE  (LCP6_SCP_MHU_MBX_BASE + SCP_MHU3_PBX_MBX_SIZE)
#define LCP7_SCP_MHU_MBX_BASE  (LCP7_SCP_MHU_PBX_BASE + SCP_MHU3_PBX_MBX_SIZE)
#define LCP8_SCP_MHU_PBX_BASE  (LCP7_SCP_MHU_MBX_BASE + SCP_MHU3_PBX_MBX_SIZE)
#define LCP8_SCP_MHU_MBX_BASE  (LCP8_SCP_MHU_PBX_BASE + SCP_MHU3_PBX_MBX_SIZE)
#define LCP9_SCP_MHU_PBX_BASE  (LCP8_SCP_MHU_MBX_BASE + SCP_MHU3_PBX_MBX_SIZE)
#define LCP9_SCP_MHU_MBX_BASE  (LCP9_SCP_MHU_PBX_BASE + SCP_MHU3_PBX_MBX_SIZE)
#define LCP10_SCP_MHU_PBX_BASE (LCP9_SCP_MHU_MBX_BASE + SCP_MHU3_PBX_MBX_SIZE)
#define LCP10_SCP_MHU_MBX_BASE (LCP10_SCP_MHU_PBX_BASE + SCP_MHU3_PBX_MBX_SIZE)
#define LCP11_SCP_MHU_PBX_BASE (LCP10_SCP_MHU_MBX_BASE + SCP_MHU3_PBX_MBX_SIZE)
#define LCP11_SCP_MHU_MBX_BASE (LCP11_SCP_MHU_PBX_BASE + SCP_MHU3_PBX_MBX_SIZE)
#define LCP12_SCP_MHU_PBX_BASE (LCP11_SCP_MHU_MBX_BASE + SCP_MHU3_PBX_MBX_SIZE)
#define LCP12_SCP_MHU_MBX_BASE (LCP12_SCP_MHU_PBX_BASE + SCP_MHU3_PBX_MBX_SIZE)
#define LCP13_SCP_MHU_PBX_BASE (LCP12_SCP_MHU_MBX_BASE + SCP_MHU3_PBX_MBX_SIZE)
#define LCP13_SCP_MHU_MBX_BASE (LCP13_SCP_MHU_PBX_BASE + SCP_MHU3_PBX_MBX_SIZE)
#define LCP14_SCP_MHU_PBX_BASE (LCP13_SCP_MHU_MBX_BASE + SCP_MHU3_PBX_MBX_SIZE)
#define LCP14_SCP_MHU_MBX_BASE (LCP14_SCP_MHU_PBX_BASE + SCP_MHU3_PBX_MBX_SIZE)
#define LCP15_SCP_MHU_PBX_BASE (LCP14_SCP_MHU_MBX_BASE + SCP_MHU3_PBX_MBX_SIZE)
#define LCP15_SCP_MHU_MBX_BASE (LCP15_SCP_MHU_PBX_BASE + SCP_MHU3_PBX_MBX_SIZE)

#define LCP_EXTEND_CTRL_FRAME_BASE 0xB0083000
#define LCP_CFG_BASE               LCP_EXTEND_CTRL_FRAME_BASE + 0x000
#define LCP_RST_SYN_BASE           LCP_EXTEND_CTRL_FRAME_BASE + 0x010

#define LCP_DVFS_FRAME_BASE 0xB0081000

#endif /* LCP_CSS_MMAP_H */
