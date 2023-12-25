/*
 * Arm SCP/MCP Software
 * Copyright (c) 2023-2024, Arm Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "config_power_domain.h"
#include "tc4_ppu_v1.h"
#include "scp_mmap.h"
#include "tc4_core.h"

#include <mod_power_domain.h>
#include <mod_ppu_v1.h>
#include <mod_tc4_bl1.h>

#include <fwk_element.h>
#include <fwk_id.h>
#include <fwk_interrupt.h>
#include <fwk_macros.h>
#include <fwk_mm.h>
#include <fwk_module.h>
#include <fwk_module_idx.h>
#include <fwk_string.h>

#include <stdio.h>
#include <string.h>

/* Maximum PPU core name size including the null terminator */
#define PPU_CORE_NAME_SIZE 12

/* Maximum PPU cluster name size including the null terminator */
#define PPU_CLUS_NAME_SIZE 6

/* Cluster ID for Theodul DSU */
#define CLUSTER_ID 0

/* Module configuration data */
static struct mod_ppu_v1_config ppu_v1_config_data = {
    .pd_notification_id = FWK_ID_NOTIFICATION_INIT(
        FWK_MODULE_IDX_TC4_BL1,
        MOD_TC4_BL1_NOTIFICATION_IDX_POWER_SYSTOP),
    .pd_source_id = FWK_ID_MODULE_INIT(FWK_MODULE_IDX_TC4_BL1),
};

static const struct fwk_element *ppu_v1_get_element_table(fwk_id_t module_id)
{
    struct fwk_element *element_table, *element;
    struct mod_ppu_v1_pd_config *pd_config_table, *pd_config;
    unsigned char core_idx;
    unsigned int core_count;
    unsigned int cluster_count;
    unsigned int core_element_count = 0;

    core_count = TC4_NUMBER_OF_CORES;
    cluster_count = TC4_NUMBER_OF_CLUSTERS;

    /*
     * Allocate element descriptors based on:
     *   Number of cores
     *   + Number of cluster descriptors
     *   + Number of system power domain descriptors
     *   + 1 terminator descriptor
     */
    element_table = fwk_mm_calloc(
        core_count + cluster_count + 1,
        sizeof(struct fwk_element));
    if (element_table == NULL) {
        return NULL;
    }

    pd_config_table = fwk_mm_calloc(
        core_count + cluster_count, sizeof(struct mod_ppu_v1_pd_config));
    if (pd_config_table == NULL) {
        return NULL;
    }

    for (core_idx = 0;
         core_idx < TC4_NUMBER_OF_CORES;
         core_idx++) {
        element = &element_table[core_element_count];
        pd_config = &pd_config_table[core_element_count];

        element->name = fwk_mm_alloc(PPU_CORE_NAME_SIZE, 1);
        if (element->name == NULL) {
            return NULL;
        }

        (void)snprintf(
            (char *)element->name, PPU_CORE_NAME_SIZE, "CORE%u", core_idx);

        element->data = pd_config;

        pd_config->pd_type = MOD_PD_TYPE_CORE;
        pd_config->ppu.reg_base = SCP_PPU_CORE_BASE(core_idx);
        pd_config->ppu.irq = FWK_INTERRUPT_NONE;
        pd_config->cluster_id =
            FWK_ID_ELEMENT(FWK_MODULE_IDX_PPU_V1, core_count);
        pd_config->observer_id = FWK_ID_NONE;
        core_element_count++;
    }

    element = &element_table[core_count];
    pd_config = &pd_config_table[core_count];

    element->name = fwk_mm_alloc(PPU_CLUS_NAME_SIZE, 1);
    if (element->name == NULL) {
        return NULL;
    }

    element->data = pd_config;

    pd_config->pd_type = MOD_PD_TYPE_CLUSTER;
    pd_config->ppu.reg_base = SCP_PPU_CLUSTER_BASE;
    pd_config->ppu.irq = FWK_INTERRUPT_NONE;
    pd_config->observer_id = FWK_ID_NONE;

    return element_table;
}

/*
 * Power module configuration data
 */
const struct fwk_module_config config_ppu_v1 = {
    .elements = FWK_MODULE_DYNAMIC_ELEMENTS(ppu_v1_get_element_table),
    .data = &ppu_v1_config_data,
};
