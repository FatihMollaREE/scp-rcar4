/*
 * Arm SCP/MCP Software
 * Copyright (c) 2024, Arm Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * Description:
 *      System PIK device driver.
 */

#include <mod_system_pik.h>

#include <fwk_id.h>
#include <fwk_module.h>
#include <fwk_status.h>

/* System PIK module context */
struct mod_system_pik_ctx {
    /*! Base address of the system PIK register block */
    struct system_pik_reg *system_pik_reg;
};

struct mod_system_pik_ctx system_pik_ctx;

/*
 * Framework handlers
 */
static int mod_system_pik_init(
    fwk_id_t module_id,
    unsigned int device_count,
    const void *data)
{
    struct mod_system_pik_device_config *config =
        (struct mod_system_pik_device_config *)data;

    system_pik_ctx.system_pik_reg =
        (struct system_pik_reg *)config->system_pik_base;

    /*
     * Apply all the boot time configuration.
     */

    if (config->l0_gpt_size != 0) {
        system_pik_ctx.system_pik_reg->IOMACRO_OVERRIDE &=
            ~(IOMACRO_OVERRIDE_TCU_L0GPTSZ_MASK
              << IOMACRO_OVERRIDE_TCU_L0GPTSZ_SHIFT);
        system_pik_ctx.system_pik_reg->IOMACRO_OVERRIDE |=
            (config->l0_gpt_size << IOMACRO_OVERRIDE_TCU_L0GPTSZ_SHIFT);
    }

    return FWK_SUCCESS;
}

static int mod_system_pik_start(fwk_id_t id)
{
    return FWK_SUCCESS;
}

/* System PIK module definition */
const struct fwk_module module_system_pik = {
    .type = FWK_MODULE_TYPE_DRIVER,
    .init = mod_system_pik_init,
    .start = mod_system_pik_start,
};
