/*
 * Arm SCP/MCP Software
 * Copyright (c) 2024, Arm Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * Description:
 *     Base address definitions for the SCP's sub-system and access extending
 *     into the rest of the CSS.
 */

#ifndef SCP_CSS_MMAP_H
#define SCP_CSS_MMAP_H

// clang-format off

/* SCP sub-system peripherals */
#define SCP_SID_BASE (0x1A4A0000)
#define SCP_UART_BASE (0x44002000)

/* SCP addresses mapped via ATU into address translation windows */
#define SCP_ADDRESS_TRANSLATION_WINDOW0_BASE (0x60000000)
#define SCP_ADDRESS_TRANSLATION_WINDOW1_BASE (0xA0000000)

// clang-format on

#endif /* SCP_CSS_MMAP_H */
