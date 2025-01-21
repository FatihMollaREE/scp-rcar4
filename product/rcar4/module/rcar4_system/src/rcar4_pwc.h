/*
 * Renesas SCP/MCP Software
 * Copyright (c) 2020-2021, Renesas Electronics Corporation. All rights
 * reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef RCAR4_PWC_H
#define RCAR4_PWC_H

void rcar4_pwrc_go_suspend_to_ram(void);
void rcar4_pwrc_set_suspend_to_ram(void);
void rcar4_system_off(void);
void rcar4_system_reset(void);

#endif /* RCAR4_PWC_H */
