/*
 * Arm SCP/MCP Software
 * Copyright (c) 2023-2024, Arm Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * Description:
 *     Utility functions for accessing HN-S node.
 */

#include <internal/cmn_cyprus_common.h>
#include <internal/cmn_cyprus_hns_reg.h>
#include <internal/cmn_cyprus_reg.h>

#include <fwk_assert.h>
#include <fwk_math.h>

#include <stdint.h>

/* HN-S SAM_CONTROL */
#define HNS_SAM_CONTROL_SN_MODE_POS(sn_mode)   (36 + sn_mode)
#define HNS_SAM_CONTROL_SN_NODE_ID_POS(sn_idx) (sn_idx * 12)
#define HNS_SAM_CONTROL_SN_NODE_ID_MASK        (0x7FF)

/* Only 3 target SN node IDs can be programmed in a HN-S node */
#define HNS_SAM_CONTROL_SN_IDX_COUNT 3

/* HN-S SAM Top Address Bit */
#define HNS_SAM_CONTROL_TOP_ADDR_BIT_POS(x) (40 + (x * 8))

/* HN-S SAM */
#define HNS_UNIT_INFO_HNSAM_RCOMP_EN_MASK  (0x20000000)
#define HNS_UNIT_INFO_HNSAM_RCOMP_EN_POS   29
#define HNS_UNIT_INFO_HNSAM_RCOMP_LSB_MASK (0x7C0000000)
#define HNS_UNIT_INFO_HNSAM_RCOMP_LSB_POS  30
#define HNS_SAM_MEMREGION_SIZE_POS         12
#define HNS_SAM_MEMREGION_BASE_POS         20
#define HNS_SAM_MEMREGION_VALID            UINT64_C(0x8000000000000000)
#define HNS_SAM_MEMREGION_SN_NODE_ID_MASK  (0x7FF)

/* HN-S Power Policy */
#define HNS_PWPR_DYN_EN_POS  8
#define HNS_PWPR_OP_MODE_POS 4
#define HNS_PWPR_POLICY_POS  0

/*
 * Minimum size of hashed and non-hashed regions when RCOMP mode
 * is disabled is 64MB. In this mode, the base and the size of the
 * programmed region is used for comparison.
 */
#define HNSAM_REGION_MIN_SIZE (64 * FWK_MIB)

/* HN-S programming context structure */
struct cmn_cyprus_hns_ctx {
    /* Range comparison mode status flag */
    bool rcomp_en;

    /*
     * Minimum size of the regions when RCOMP is enabled. The size is
     * defined using user parameter HNSAM_RCOMP_LSB during CMN mesh build time.
     *
     * The values from 20 to 26 are valid for HNSAM_RCOMP_LSB parameter.
     * HNSAM_RCOMP_LSB = 20, defines minimum memory size = 1MB
     * HNSAM_RCOMP_LSB = 21, defines minimum memory size = 2MB
     * ...
     * HNSAM_RCOMP_LSB = 26, defines minimum memory size = 64MB
     */
    uint64_t min_region_size;

    /* Flag to indicate that the HN-S context has been initialized */
    bool is_initialized;
};

static struct cmn_cyprus_hns_ctx hns_ctx;

static uint8_t get_hns_rcomp_lsb_pos(struct cmn_cyprus_hns_reg *hns)
{
    return (
        (hns->UNIT_INFO[1] & HNS_UNIT_INFO_HNSAM_RCOMP_LSB_MASK) >>
        HNS_UNIT_INFO_HNSAM_RCOMP_LSB_POS);
}

void hns_enable_sn_mode(
    struct cmn_cyprus_hns_reg *hns,
    enum mod_cmn_cyprus_hnf_sam_hashed_mode sn_mode)
{
    /* Enable HN-F to SN-F memory striping mode */
    hns->SAM_CONTROL |= (UINT64_C(1) << HNS_SAM_CONTROL_SN_MODE_POS(sn_mode));
}

void hns_configure_top_address_bit(
    struct cmn_cyprus_hns_reg *hns,
    enum mod_cmn_cyprus_hns_sam_top_address_bit top_address_bit,
    unsigned int top_address_bit_value)
{
    /* Configure bit position of top_address_bit0 */
    hns->SAM_CONTROL |=
        ((uint64_t)top_address_bit_value
         << HNS_SAM_CONTROL_TOP_ADDR_BIT_POS(top_address_bit));
}

void hns_configure_sn_node_id(
    struct cmn_cyprus_hns_reg *hns,
    unsigned int sn_node_id,
    uint8_t sn_idx)
{
    /* Only 3 target SN node IDs can be programmed in a HN-S node */
    fwk_assert(sn_idx < HNS_SAM_CONTROL_SN_IDX_COUNT);

    /* Configure the SN node ID */
    hns->SAM_CONTROL |=
        ((uint64_t)sn_node_id << HNS_SAM_CONTROL_SN_NODE_ID_POS(sn_idx));
}

bool hns_is_range_comparison_mode_enabled(struct cmn_cyprus_hns_reg *hns)
{
    return (hns->UNIT_INFO[1] & HNS_UNIT_INFO_HNSAM_RCOMP_EN_MASK) >>
        HNS_UNIT_INFO_HNSAM_RCOMP_EN_POS;
}

void hns_configure_non_hashed_region_addr_range(
    struct cmn_cyprus_hns_reg *hns,
    bool hnsam_range_comp_en_mode,
    uint64_t base,
    uint64_t size,
    unsigned int non_hashed_region_idx)
{
    /* Only 2 SAM_MEMREGION registers have been defined in the driver */
    fwk_assert(non_hashed_region_idx < 2);

    /* Configure non-hashed region based on address range comparison mode */
    if (hnsam_range_comp_en_mode) {
        /* Configure end address of the region */
        hns->SAM_MEMREGION_END_ADDR[non_hashed_region_idx] =
            ((base + size - 1));

        /* Configure base address of the region */
        hns->SAM_MEMREGION[non_hashed_region_idx] |=
            ((base / hns_ctx.min_region_size) << HNS_SAM_MEMREGION_BASE_POS);
    } else {
        /* Configure region size */
        hns->SAM_MEMREGION[non_hashed_region_idx] |=
            (sam_encode_region_size(size, hns_ctx.min_region_size)
             << HNS_SAM_MEMREGION_SIZE_POS);

        /* Configure region base */
        hns->SAM_MEMREGION[non_hashed_region_idx] |=
            ((base / hns_ctx.min_region_size) << HNS_SAM_MEMREGION_BASE_POS);
    }
}

void hns_configure_non_hashed_region_sn_node_id(
    struct cmn_cyprus_hns_reg *hns,
    unsigned int sn_node_id,
    unsigned int non_hashed_region_idx)
{
    /*
     * Only 2 registers have been defined in the driver for configuring
     * non-hashed memory regions.
     */
    fwk_assert(non_hashed_region_idx < 2);

    /* Clear the SN node ID */
    hns->SAM_MEMREGION[non_hashed_region_idx] &=
        ~(HNS_SAM_MEMREGION_SN_NODE_ID_MASK);

    /* Configure target node ID */
    hns->SAM_MEMREGION[non_hashed_region_idx] |= sn_node_id;
}

void hns_set_non_hashed_region_valid(
    struct cmn_cyprus_hns_reg *hns,
    unsigned int non_hashed_region_idx)
{
    /* Only 2 SAM_MEMREGION registers have been defined in the driver */
    fwk_assert(non_hashed_region_idx < 2);

    /* Set the region as valid */
    hns->SAM_MEMREGION[non_hashed_region_idx] |= HNS_SAM_MEMREGION_VALID;
}

void hns_set_pwpr_dynamic_enable(struct cmn_cyprus_hns_reg *hns)
{
    /* Clear the dyn_en bit */
    hns->PPU_PWPR &= ~(0x1 << HNS_PWPR_DYN_EN_POS);

    /* Enable dynamic transition for system cache RAM PPU */
    hns->PPU_PWPR |= (0x1 << HNS_PWPR_DYN_EN_POS);
}

void hns_set_pwpr_op_mode(
    struct cmn_cyprus_hns_reg *hns,
    enum mod_cmn_cyprus_hns_pwpr_op_mode op_mode)
{
    /* Clear the bit op_mode bits */
    hns->PPU_PWPR &= ~(0xF << HNS_PWPR_OP_MODE_POS);

    /* Configure HN-F operational power mode */
    hns->PPU_PWPR |= (op_mode << HNS_PWPR_OP_MODE_POS);
}

void hns_set_pwpr_policy(struct cmn_cyprus_hns_reg *hns, uint8_t policy)
{
    /* Clear the power policy bits */
    hns->PPU_PWPR &= ~(0xF << HNS_PWPR_POLICY_POS);

    /* Configure HN-F power policy */
    hns->PPU_PWPR |= (policy << HNS_PWPR_POLICY_POS);
}

int setup_hns_ctx(struct cmn_cyprus_hns_reg *hns)
{
    uint8_t lsb_pos;

    /* Return if initialized already */
    if (hns_ctx.is_initialized == true) {
        return FWK_SUCCESS;
    }

    if (hns == NULL) {
        return FWK_E_PARAM;
    }

    /*
     * Check if the start and end address has to be programmed for
     * regions.
     */
    hns_ctx.rcomp_en = hns_is_range_comparison_mode_enabled(hns);

    /* Get the minimum region size */
    if (hns_ctx.rcomp_en != 0) {
        lsb_pos = get_hns_rcomp_lsb_pos(hns);
        hns_ctx.min_region_size = fwk_math_pow2(lsb_pos);
    } else {
        hns_ctx.min_region_size = HNSAM_REGION_MIN_SIZE;
    }

    hns_ctx.is_initialized = true;

    return FWK_SUCCESS;
}
