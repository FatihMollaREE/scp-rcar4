/*
 * Renesas SCP/MCP Software
 * Copyright (c) 2020-2021, Renesas Electronics Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*  fatih: disabl
*   #include <asm_macros.S>
*   .macro func _name, _align=2 ist auch einf tmp
*/

 .macro func _name, _align=2
    /*
     * Add Call Frame Information entry in the .debug_frame section for
     * debugger consumption. This enables callstack printing in debuggers.
     * This does not use any space in the final loaded binary, only in the
     * ELF file.
     * Note that a function manipulating the CFA pointer location (i.e. the
     * x29 frame pointer on AArch64) should declare it using the
     * appropriate .cfi* directives, or be prepared to have a degraded
     * debugging experience.
     */
    .cfi_sections .debug_frame
    .section .text.asm.\_name, "ax"
    .type \_name, %function
    /*
     * .cfi_startproc and .cfi_endproc are needed to output entries in
     * .debug_frame
     */
    .cfi_startproc
    .align \_align
    \_name:
    .endm

.if 0

.global rcar4_pwrc_switch_stack

/*
 * x0 : jump address,
 * x1 : stack address,
 * x2 : arg,
 * x3 : stack address (temporary)
 */
func rcar4_pwrc_switch_stack

    /* lr to stack */
    stp x29, x30, [sp,#-16]

    /* change stack pointer */
    mov x3, sp
    mov sp, x1

    /* save stack pointer */
    sub sp, sp, #16
    stp x0, x3, [sp]

    /* data synchronization barrier */
    dsb sy

    /* jump to code */
    mov x1, x0
    mov x0, x2
    blr x1

    /* load stack pointer */
    ldp     x0, x2, [sp,#0]

    /* change stack pointer */
    mov sp, x2

    /* return */
    ldp x29, x30, [sp,#-16]
    ret
endfunc rcar4_pwrc_switch_stack

.endif
