/*
 * Copyright (c) 2015-2017, Renesas Electronics Corporation
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   - Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *
 *   - Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 *   - Neither the name of Renesas nor the names of its contributors may be
 *     used to endorse or promote products derived from this software without
 *     specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#define ARCH_MEM_MODE_SINGLE_REGION             0
#define ARCH_MEM_MODE_DUAL_REGION_RELOCATION    1
#define ARCH_MEM_MODE_DUAL_REGION_NO_RELOCATION 2

#include <fmw_memory.h>

#define STACK_ALIGNMENT 8

/*
 * Input validation
 */

#ifndef FMW_MEM_MODE
    #error "FMW_MEM_MODE has not been configured"
#endif

#ifndef FMW_STACK_SIZE
    #error "FMW_STACK_SIZE has not been configured"
#endif

#ifndef FMW_MEM0_BASE
    #error "FMW_MEM0_BASE has not been configured"
#endif

#ifndef FMW_MEM0_SIZE
    #error "FMW_MEM0_SIZE has not been configured"
#endif

#if ((FMW_MEM_MODE != ARCH_MEM_MODE_SINGLE_REGION) && \
     (FMW_MEM_MODE != ARCH_MEM_MODE_DUAL_REGION_RELOCATION) && \
     (FMW_MEM_MODE != ARCH_MEM_MODE_DUAL_REGION_NO_RELOCATION))
    #error "FMW_MEM_MODE has been configured improperly"
#endif

#if FMW_MEM_MODE != ARCH_MEM_MODE_SINGLE_REGION
    #ifndef FIRMWARE_MEM1_BASE
        #error "FIRMWARE_MEM1_BASE has not been configured"
    #endif

    #ifndef FIRMWARE_MEM1_SIZE
        #error "FIRMWARE_MEM1_SIZE has not been configured"
    #endif
#endif

/*
 * Calculate stack region in the data memory.
 */

#if FMW_MEM_MODE == ARCH_MEM_MODE_SINGLE_REGION
    ASSERT(FMW_STACK_SIZE < FMW_MEM0_SIZE,
        "FMW_STACK_SIZE does not fit in MEM0")
    #define UNALIGNED_STACK_BASE \
        (FMW_MEM0_BASE + FMW_MEM0_SIZE - FMW_STACK_SIZE)
#else
    ASSERT(FMW_STACK_SIZE < FIRMWARE_MEM1_SIZE,
        "FMW_STACK_SIZE does not fit in MEM1")
    #define UNALIGNED_STACK_BASE \
        (FIRMWARE_MEM1_BASE + FIRMWARE_MEM1_SIZE - FMW_STACK_SIZE)
#endif

#define STACK_BASE \
    ( \
        ((UNALIGNED_STACK_BASE + STACK_ALIGNMENT - 1) / STACK_ALIGNMENT) \
            * STACK_ALIGNMENT \
    )

#define STACK_SIZE \
    (( \
        ((STACK_BASE + FMW_STACK_SIZE) / STACK_ALIGNMENT) \
            * STACK_ALIGNMENT \
    ) - STACK_BASE)

ASSERT(STACK_SIZE > 0, "FMW_STACK_SIZE is too small")


OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(Vector) /* eventuell hier anpassen*/

MEMORY {
#if FMW_MEM_MODE == ARCH_MEM_MODE_SINGLE_REGION
    /* Only one memory region with read, execute and write attributes */
    mem0 (rxw): ORIGIN = FMW_MEM0_BASE, LENGTH = FMW_MEM0_SIZE - \
                                                      FMW_STACK_SIZE
#else
    mem0 (rx):  ORIGIN = FMW_MEM0_BASE, LENGTH = FMW_MEM0_SIZE
    mem1 (rxw): ORIGIN = FIRMWARE_MEM1_BASE, LENGTH = FIRMWARE_MEM1_SIZE - \
                                                      FMW_STACK_SIZE
#endif
    stack (rw):  ORIGIN = STACK_BASE, LENGTH = STACK_SIZE
    #hier bin ich unsicher, brauch ich das, was muss dann hierhin?# sram (rxw): ORIGIN = ((0xE6302000)), LENGTH = (0x00001000)
}



SECTIONS
{
    . = FMW_MEM0_BASE;
    ASSERT(. == ALIGN(4096),
           "CR7 dummy rtos address is not aligned on a page boundary.")

    ro . : {
        __RO_START__ = .;
        *rtos.o(.text*)
        *rtos_main.o(.text*)
        . = NEXT(32768);
        *(.text*)
        *(.rodata*)
        __RO_END_UNALIGNED__ = .;
        /*
         * Memory page(s) mapped to this section will be marked as
         * read-only, executable.  No RW data from the next section must
         * creep in.  Ensure the rest of the current memory page is unused.
         */
        . = NEXT(4096);
        . = NEXT(16384);
        __RO_END__ = .;
    } >mem0

    .data . : {
        __DATA_START__ = .;
        *(.data*)
        __DATA_END__ = .;
    } >mem0

    stacks (NOLOAD) : ALIGN(16) {
        __STACKS_START__ = .;
        KEEP(*(tzfw_normal_stacks))
        __STACKS_END__ = .;
    } >mem0

    /*
     * The .bss section gets initialised to 0 at runtime.
     * Its base address must be 16-byte aligned.
     */
    .bss : ALIGN(16) {
        __BSS_START__ = .;
        *(SORT_BY_ALIGNMENT(.bss*))
        *(COMMON)
        __BSS_END__ = .;
    } >mem0

    __BSS_SIZE__ = SIZEOF(.bss);

    ASSERT(. <= 0xE24FE800, "CR7 dummy rtos has exceeded its limit.")
}
