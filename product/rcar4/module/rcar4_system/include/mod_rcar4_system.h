/*
 * Renesas SCP/MCP Software
 * Copyright (c) 2020-2021, Renesas Electronics Corporation. All rights
 * reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef MOD_RCAR4_SYSTEM_H
#define MOD_RCAR4_SYSTEM_H

#include <fwk_id.h>

/*!
 * \addtogroup GroupRCAR4Module RCAR4 Product Modules
 * @{
 */

/*!
 * \defgroup GroupRCAR4System RCAR4 System Support
 *
 * @{
 */

/*! Fatih: nix gemacht ganze datei
 * \brief System device configuration.
 */
struct mod_rcar4_system_dev_config {
    /*! Reference to the device element within the associated driver module */
    const fwk_id_t driver_id;

    /*! Reference to the API provided by the device driver module */
    const fwk_id_t api_id;
};

/*!
 * \brief API indices.
 */
enum mod_rcar4_system_api_idx {
    /*! API index for the driver interface of the SYSTEM POWER module */
    MOD_RCAR4_SYSTEM_API_IDX_SYSTEM_POWER_DRIVER,

    /*! Number of defined APIs */
    MOD_RCAR4_SYSTEM_API_COUNT
};

/*!
 * @cond
 */

void rcar4_system_code_copy_to_system_ram(void);
extern void vConfigureTickInterrupt(void);
extern void _save_system(void);

/*!
 * \brief rcar4 system module interface.
 */
struct mod_rcar4_system_drv_api {
    int (*resume)(void);
};

/*!
 * @endcond
 */

/*!
 * @}
 */

/*!
 * @}
 */

#endif /* MOD_RCAR4_SYSTEM_H */
