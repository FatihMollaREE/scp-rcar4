/*
 * Arm SCP/MCP Software
 * Copyright (c) 2021, Arm Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <fwk_module.h>
#include <fwk_module_idx.h>

#include <stddef.h>

extern const struct fwk_module module_rcar4_system;
extern const struct fwk_module module_scmi;
extern const struct fwk_module module_transport;
extern const struct fwk_module module_clock;
extern const struct fwk_module module_rcar4_clock;
extern const struct fwk_module module_rcar4_system_power;
extern const struct fwk_module module_rcar4_mfismh;
extern const struct fwk_module module_power_domain;
extern const struct fwk_module module_rcar4_pd_sysc;
extern const struct fwk_module module_rcar4_pd_core;
extern const struct fwk_module module_sds;
extern const struct fwk_module module_reset_domain;
extern const struct fwk_module module_rcar4_reset;
extern const struct fwk_module module_scmi_reset_domain;


const struct fwk_module *module_table[FWK_MODULE_IDX_COUNT] = {
    &module_rcar4_system,
    &module_scmi,
    &module_transport,
    &module_clock,
    &module_rcar4_clock,
    &module_rcar4_system_power,
    &module_rcar4_mfismh,
    &module_power_domain,
    &module_rcar4_pd_sysc,
    &module_rcar4_pd_core,
    &module_sds,
    &module_reset_domain,
    &module_rcar4_reset,
    &module_scmi_reset_domain,

};

extern const struct fwk_module_config config_rcar4_system;
extern const struct fwk_module_config config_scmi;
extern const struct fwk_module_config config_transport;
extern const struct fwk_module_config config_clock;
extern const struct fwk_module_config config_rcar4_clock;
extern const struct fwk_module_config config_rcar4_system_power;
extern const struct fwk_module_config config_rcar4_mfismh;
extern const struct fwk_module_config config_power_domain;
extern const struct fwk_module_config config_rcar4_pd_sysc;
extern const struct fwk_module_config config_rcar4_pd_core;
extern const struct fwk_module_config config_sds;
extern const struct fwk_module_config config_reset_domain;
extern const struct fwk_module_config config_rcar4_reset;
extern const struct fwk_module_config config_scmi_reset_domain;


const struct fwk_module_config *module_config_table[FWK_MODULE_IDX_COUNT] = {
    &config_rcar4_system,
    &config_scmi,
    &config_transport,
    &config_clock,
    &config_rcar4_clock,
    &config_rcar4_system_power,
    &config_rcar4_mfismh,
    &config_power_domain,
    &config_rcar4_pd_sysc,
    &config_rcar4_pd_core,
    &config_sds,
    &config_reset_domain,
    &config_rcar4_reset,
    &config_scmi_reset_domain,

};
