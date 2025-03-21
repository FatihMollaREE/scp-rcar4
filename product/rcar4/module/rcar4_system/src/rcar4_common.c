/* Fatih: einfach alle funktionen zu dummys gemacht
 * Renesas SCP/MCP Software
 * Copyright (c) 2020-2024, Renesas Electronics Corporation. All rights
 * reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <rcar4_common.h>
#include <rcar4_mmap.h>

#include <fwk_attributes.h>
#include <fwk_mmio.h>

void FWK_SECTION(".system_ram") cpg_write(uintptr_t regadr, uint32_t regval)
{
    uint32_t value = (regval);
    fwk_mmio_write_32((uintptr_t)RCAR4_CPGWPR, ~value);
    fwk_mmio_write_32(regadr, value);
}

void FWK_SECTION(".system_ram")
    mstpcr_write(uint32_t mstpcr, uint32_t mstpsr, uint32_t target_bit)
{
    uint32_t reg;
    reg = fwk_mmio_read_32(mstpcr);
    reg &= ~target_bit;
    cpg_write(mstpcr, reg);
    while ((fwk_mmio_read_32(mstpsr) & target_bit) != 0U)
        continue;
}

static inline void cpu_relax(void)
{
//    __asm__ volatile("yield" ::: "memory");
}

static uint64_t FWK_SECTION(".system_ram") get_cntfrq(void)
{
//    uint64_t val;
//    __asm__ volatile("mrs %0, cntfrq_el0" : "=r"(val));
//    return val;
        return 999;
}

static uint64_t FWK_SECTION(".system_ram") get_cntvct(void)
{
//    uint64_t val;
//    __asm__ volatile("mrs %0, cntvct_el0" : "=r"(val));
//    return val;
    return 999;
}

static void FWK_SECTION(".system_ram") delay(uint64_t cycles)
{
    uint64_t start = get_cntvct();

    while ((get_cntvct() - start) < cycles)
        cpu_relax();
}

void FWK_SECTION(".system_ram") udelay(unsigned long usec)
{
    delay((uint64_t)usec * get_cntfrq() / 1000000);
}

void FWK_SECTION(".system_ram") mdelay(unsigned long msecs)
{
    while (msecs--)
        udelay(1000);
}
