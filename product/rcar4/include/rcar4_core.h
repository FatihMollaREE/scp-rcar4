/*
 * Renesas SCP/MCP Software
 * Copyright (c) 2020-2021, Renesas Electronics Corporation. All rights
 * reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef RCAR4_CORE_H
#define RCAR4_CORE_H

#define RCAR4_CORE_PER_CLUSTER_MAX 8

unsigned int rcar4_core_get_count(void);
unsigned int rcar4_cluster_get_count(void);

#endif /* RCAR4_CORE_H */
