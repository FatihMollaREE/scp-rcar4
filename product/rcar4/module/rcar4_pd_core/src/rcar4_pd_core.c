/*
 * Renesas SCP/MCP Software
 * Copyright (c) 2020-2024, Renesas Electronics Corporation. All rights
 * reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <rcar4_common.h>
#include <rcar4_mmap.h>
#include <rcar4_pd_core.h>

#include <mod_rcar4_pd_core.h>

#include <fwk_assert.h>
#include <fwk_mmio.h>
#include <fwk_status.h>

#include <stddef.h>

// Diese Datei wurde nicht richtig geprüft, sie ist nur als Abhängigkeit enthalten

void rcar4_pwrc_cpuoff(uint32_t core)
{
    /*
    uintptr_t off_reg;
    uint32_t cpu_no;

    if (core & CLUSTER_CPU_MASK) {
        off_reg = (uintptr_t)RCAR4_CA53CPU0CR;
        cpu_no = (core & (~CLUSTER_CPU_MASK));
    } else {
        off_reg = (uintptr_t)RCAR4_CA57CPU0CR;
        cpu_no = core;
    }
    //Fatih: register wurden noch nicht geprüft
    //fwk_mmio_write_32(RCAR4_CPGWPR, ~((uint32_t)CPU_PWR_OFF));
    //fwk_mmio_write_32(off_reg + (cpu_no * 0x0010U), (uint32_t)CPU_PWR_OFF);
    */
}

void rcar4_pwrc_cpuon(uint32_t core)
{
    /*
    uintptr_t res_reg;
    uint32_t res_data;
    uintptr_t on_reg;
    uint32_t upper_value;
    uint32_t wup_data;
    uint32_t cpu_no;

    if (core & CLUSTER_CPU_MASK) {
    
        res_reg = (uintptr_t)RCAR4_CA53RESCNT;
        on_reg = (uintptr_t)RCAR4_CA53WUPCR;
        upper_value = 0x5A5A0000U;
        cpu_no = (core & (~CLUSTER_CPU_MASK));
        ;
    } else {
        res_reg = (uintptr_t)RCAR4_CA57RESCNT;
        on_reg = (uintptr_t)RCAR4_CA57WUPCR;
        upper_value = 0xA5A50000U;
        cpu_no = core;
    }

    res_data = fwk_mmio_read_32(res_reg) | upper_value;
    SCU_power_up(core);
    wup_data = (uint32_t)((uint32_t)1U << cpu_no);
    //fwk_mmio_write_32(RCAR4_CPGWPR, ~wup_data);
    //fwk_mmio_write_32(on_reg, wup_data);
    // Dessert to CPU reset
    //fwk_mmio_write_32(res_reg, (res_data & (~((uint32_t)1U << (3U - cpu_no)))));
    */
}

void SCU_power_up(uint32_t core)
{
    /*
    uint32_t reg_SYSC_bit;
    uintptr_t reg_PWRONCR;
    volatile uintptr_t reg_PWRER;
    uintptr_t reg_PWRSR;
    uintptr_t reg_CPUCMCR;
    uintptr_t reg_SYSCIER = (uintptr_t)RCAR4_SYSCIER;
    uintptr_t reg_SYSCIMR = (uintptr_t)RCAR4_SYSCIMR;
    volatile uintptr_t reg_SYSCSR = (volatile uintptr_t)RCAR4_SYSCSR;
    volatile uintptr_t reg_SYSCISR = (volatile uintptr_t)RCAR4_SYSCISR;
    volatile uintptr_t reg_SYSCISCR = (volatile uintptr_t)RCAR4_SYSCISCR;

    if (core < 4) {
        reg_SYSC_bit = (uint32_t)BIT_CA57_SCU;
        reg_PWRONCR = (uintptr_t)RCAR4_PWRONCR5;
        reg_PWRER = (volatile uintptr_t)RCAR4_PWRER5;
        reg_PWRSR = (uintptr_t)RCAR4_PWRSR5;
        reg_CPUCMCR = (uintptr_t)RCAR4_CA57CPUCMCR;
    } else {
        reg_SYSC_bit = (uint32_t)BIT_CA53_SCU;
        reg_PWRONCR = (uintptr_t)RCAR4_PWRONCR3;
        reg_PWRER = (volatile uintptr_t)RCAR4_PWRER3;
        reg_PWRSR = (uintptr_t)RCAR4_PWRSR3;
        reg_CPUCMCR = (uintptr_t)RCAR4_CA53CPUCMCR;
    }
    if ((fwk_mmio_read_32(reg_PWRSR) & (uint32_t)STATUS_PWRDOWN) != 0x0000U) {
        if (fwk_mmio_read_32(reg_CPUCMCR) != 0U) {
            //fwk_mmio_write_32(reg_CPUCMCR, (uint32_t)0x00000000U);
        }
        do {
            while ((fwk_mmio_read_32(reg_SYSCSR) & (uint32_t)REQ_RESUME) == 0U)
                continue;

        } while ((fwk_mmio_read_32(reg_PWRER) & 0x0001U) != 0U);
          
        while ((fwk_mmio_read_32(reg_SYSCISR) & reg_SYSC_bit) == 0U)
            continue;

        while ((fwk_mmio_read_32(reg_PWRSR) & (uint32_t)STATUS_PWRUP) ==
               0x0000U)
            continue;
    }
    */
}
