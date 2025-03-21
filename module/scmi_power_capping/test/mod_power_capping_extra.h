/*
 * Arm SCP/MCP Software
 * Copyright (c) 2023-2024, Arm Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef MOD_POWER_CAPPING_EXTRA_H_
#define MOD_POWER_CAPPING_EXTRA_H_

#include "fwk_id.h"
#include "mod_power_capping.h"

int get_applied_cap(fwk_id_t domain_id, uint32_t *cap);
int request_cap(fwk_id_t domain_id, uint32_t cap);
#endif /* MOD_POWER_CAPPING_EXTRA_H_ */
