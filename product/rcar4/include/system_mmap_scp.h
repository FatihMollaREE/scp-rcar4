/*
 * Renesas SCP/MCP Software
 * Copyright (c) 2020-2021, Renesas Electronics Corporation. All rights
 * reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef SYSTEM_MMAP_SCP_H
#define SYSTEM_MMAP_SCP_H

#include <rcar4_mmap_scp.h>
#include <fwk_macros.h>

// #define SCP_ROM_SIZE (64 * 1024) /* for SCP romfw */    // <-----tbd // do i need this?
#define SCP_RAM_SIZE (384 * 1024) /* for SCP ramfw */   // <-----tbd

#endif /* SYSTEM_MMAP_SCP_H */
