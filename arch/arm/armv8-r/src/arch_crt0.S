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


#define	DRAM_BASE		(0x40000000)
#define	SYSRAM_BASE		(0xE6300000)
#define	DTCM_BASE		(0xE2020000)

#define	STACK_BASE_ABT		(DTCM_BASE | 0x7080)
#define	STACK_BASE_UND		(DTCM_BASE | 0x7100)
#define	STACK_BASE_FIQ		(DTCM_BASE | 0x7180)
#define	STACK_BASE_IRQ		(DTCM_BASE | 0x7200)
#define	STACK_BASE_SVC		(DTCM_BASE | 0x8000)


	.global	Vector
	.global	Start
    .globl _shutdown_request
	.local	rtos_stacks

/*****************************************************************************
 *	Vector table
 *****************************************************************************/
	.align	5

Vector:
	b	Start				/* Reset */
	b	Undef				/* Undefined Instruction */
	b	SWI				/* Supervisor Call */
	b	PAbort				/* Prefetch Abort */
	b	DAbort				/* Data Abort */
	nop					/* Not used */
	b	IRQ				/* IRQ interrupt */
	b	FIQ				/* FIQ interrupt */


/*****************************************************************************
 *	Reset Hander
 *****************************************************************************/
Start:
	/* initialize registers*/
	mov	r0,  #0
	mov	r1,  #0
	mov	r2,  #0
	mov	r3,  #0
	mov	r4,  #0
	mov	r5,  #0
	mov	r6,  #0
	mov	r7,  #0
	mov	r8,  #0
	mov	r9,  #0
	mov	r10, #0
	mov	r11, #0
	mov	r12, #0
	mov	lr,  #0

	/* CR52_CONFIGURE_MPU */
;# MPU setting was given from BootROM team
;# Memory Attribute setting
    LDR     r0, =0xFF00                              ;# Attr1[15:8]=FF:Write-Back, Attr0[7:0]=00:Device-nGnRnE memory
    MCR     p15, 0, r0, c10, c2, 0                   ;# MAIR0
    MCR     p15, 4, r0, c10, c2, 0                   ;# HMAIR0

;# region 0: 0x00000000--0x3FFFFFFF AttrIndx=1(Write-Back)
    LDR     r0, =0x00000002                          ;# SH=b'00/AP=b'01/XN=b'0
    MCR     p15, 0, r0, c6, c8, 0                    ;# PRBAR0
    MCR     p15, 4, r0, c6, c8, 0                    ;# HPRBAR0
    LDR     r0, =0x3FFFFFC3                          ;# AttrIndx=1(Write-Back)
    MCR     p15, 0, r0, c6, c8, 1                    ;# PRLAR0
    MCR     p15, 4, r0, c6, c8, 1                    ;# HPRLAR0

;# region 1: 0x40000000--0xBFFFFFFF AttrIndx=1(Write-Back)
    LDR     r0, =0x40000002                          ;# SH=b'00/AP=b'01/XN=b'0
    MCR     p15, 0, r0, c6, c8, 4                    ;# PRBAR1
    MCR     p15, 4, r0, c6, c8, 4                    ;# HPRBAR1
    LDR     r0, =0xBFFFFFC3                          ;# AttrIndx=1(Write-Back)
    MCR     p15, 0, r0, c6, c8, 5                    ;# PRLAR1
    MCR     p15, 4, r0, c6, c8, 5                    ;# HPRLAR1

;# region 2: 0xC0000000--0xDFFFFFFF AttrIndx=0(Device)
    LDR     r0, =0xC0000003                          ;# SH=b'00/AP=b'01/XN=b'1
    MCR     p15, 0, r0, c6, c9, 0                    ;# PRBAR2
    MCR     p15, 4, r0, c6, c9, 0                    ;# HPRBAR2
    LDR     r0, =0xDFFFFFC1                          ;# AttrIndx=0(Device)
    MCR     p15, 0, r0, c6, c9, 1                    ;# PRLAR2
    MCR     p15, 4, r0, c6, c9, 1                    ;# HPRLAR2

;# region 3: 0xE0000000--0xE1FFFFFF AttrIndx=0(Device)
;#    LDR     r0, =0xE0000003                          ;# SH=b'00/AP=b'01/XN=b'1
    LDR     r0, =0xE0000002                          ;# SH=b'00/AP=b'01/XN=b'0 ;# Enable RT-VRAM1 for V4H
    MCR     p15, 0, r0, c6, c9, 4                    ;# PRBAR3
    MCR     p15, 4, r0, c6, c9, 4                    ;# HPRBAR3
    LDR     r0, =0xE1FFFFC1                          ;# AttrIndx=0(Device)
    MCR     p15, 0, r0, c6, c9, 5                    ;# PRLAR3
    MCR     p15, 4, r0, c6, c9, 5                    ;# HPRLAR3

;# region 4: 0xE2000000--0xE42FFFFF AttrIndx=1(Write-Back)
    LDR     r0, =0xE2000002                          ;# SH=b'00/AP=b'01/XN=b'0
    MCR     p15, 0, r0, c6, c10, 0                   ;# PRBAR4
    MCR     p15, 4, r0, c6, c10, 0                   ;# HPRBAR4
    LDR     r0, =0xE42FFFC3                          ;# AttrIndx=(Write-Back)
    MCR     p15, 0, r0, c6, c10, 1                   ;# PRLAR4
    MCR     p15, 4, r0, c6, c10, 1                   ;# HPRLAR4

;# region 5: 0xE4300000--0xE62FFFFF AttrIndx=0(Device)
    LDR     r0, =0xE4300003                          ;# SH=b'00/AP=b'01/XN=b'1
    MCR     p15, 0, r0, c6, c10, 4                   ;# PRBAR5
    MCR     p15, 4, r0, c6, c10, 4                   ;# HPRBAR5
    LDR     r0, =0xE62FFFC1                          ;# AttrIndx=0(Device)
    MCR     p15, 0, r0, c6, c10, 5                   ;# PRLAR5
    MCR     p15, 4, r0, c6, c10, 5                   ;# HPRLAR5

;# region 6: 0xE6300000--0xE63FFFFF AttrIndx=1(Write-Back)
    LDR     r0, =0xE6300002                          ;# SH=b'00/AP=b'01/XN=b'0
    MCR     p15, 0, r0, c6, c11, 0                   ;# PRBAR6
    MCR     p15, 4, r0, c6, c11, 0                   ;# HPRBAR6
    LDR     r0, =0xE63FFFC3                          ;# AttrIndx=(Write-Back)
    MCR     p15, 0, r0, c6, c11, 1                   ;# PRLAR6
    MCR     p15, 4, r0, c6, c11, 1                   ;# HPRLAR6

;# region 7: 0xE6400000--0xEB0FFFFF AttrIndx=0(Device)
    LDR     r0, =0xE6400003                          ;# SH=b'00/AP=b'01/XN=b'1
    MCR     p15, 0, r0, c6, c11, 4                   ;# PRBAR7
    MCR     p15, 4, r0, c6, c11, 4                   ;# HPRBAR7
    LDR     r0, =0xEB0FFFC1                          ;# AttrIndx=0(Device)
    MCR     p15, 0, r0, c6, c11, 5                   ;# PRLAR7
    MCR     p15, 4, r0, c6, c11, 5                   ;# HPRLAR7

;# region 8: 0xEB100000--0xEB127FFF AttrIndx=1(Write-Back)
    LDR     r0, =0xEB100006                          ;# SH=b'00/AP=b'10/XN=b'0
    MCR     p15, 0, r0, c6, c12, 0                   ;# PRBAR8
    MCR     p15, 4, r0, c6, c12, 0                   ;# HPRBAR8
    LDR     r0, =0xEB127FC3                          ;# AttrIndx=(Write-Back)
    MCR     p15, 0, r0, c6, c12, 1                   ;# PRLAR8
    MCR     p15, 4, r0, c6, c12, 1                   ;# HPRLAR8

;# region 9: 0xEB128000--0xEB1FFFFF AttrIndx=0(Device)
    LDR     r0, =0xEB128003                          ;# SH=b'00/AP=b'01/XN=b'1
    MCR     p15, 0, r0, c6, c12, 4                   ;# PRBAR9
    MCR     p15, 4, r0, c6, c12, 4                   ;# HPRBAR9
    LDR     r0, =0xEB1FFFC1                          ;# AttrIndx=0(Device)
    MCR     p15, 0, r0, c6, c12, 5                   ;# PRLAR9
    MCR     p15, 4, r0, c6, c12, 5                   ;# HPRLAR9

;# region 10: 0xEB200000--0xEB3FFFFF AttrIndx=1(Write-Back)
    LDR     r0, =0xEB200002                          ;# SH=b'00/AP=b'01/XN=b'0
    MCR     p15, 0, r0, c6, c13, 0                   ;# PRBAR10
    MCR     p15, 4, r0, c6, c13, 0                   ;# HPRBAR10
    LDR     r0, =0xEB3FFFC3                          ;# AttrIndx=(Write-Back)
    MCR     p15, 0, r0, c6, c13, 1                   ;# PRLAR10
    MCR     p15, 4, r0, c6, c13, 1                   ;# HPRLAR10

;# region 11: 0xEB400000--0xFFFFFFFF AttrIndx=0(Device)
    LDR     r0, =0xEB400003                          ;# SH=b'00/AP=b'01/XN=b'1
    MCR     p15, 0, r0, c6, c13, 4                   ;# PRBAR11
    MCR     p15, 4, r0, c6, c13, 4                   ;# HPRBAR11
    LDR     r0, =0xFFFFFFC1                          ;# AttrIndx=0(Device)
    MCR     p15, 0, r0, c6, c13, 5                   ;# PRLAR11
    MCR     p15, 4, r0, c6, c13, 5                   ;# HPRLAR11

;#CR52_SET_MPU_ON
    MRC     p15, 4, r0, c1, c0, 0                    ;# HSCTLR
    ORR     r0, r0, #0x00000001                      ;# EL2-controlled MPU enable
    DSB
    MCR     p15, 4, r0, c1, c0, 0
    ISB

    MRC     p15, 0, r0, c1, c0, 0                    ;# SCTLR
    ORR     r0, r0, #0x00000001                      ;# EL1-controlled MPU enable
    DSB
    MCR     p15, 0, r0, c1, c0, 0
    ISB

	LDR	PC, =STACK_INIT

STACK_INIT:
	/* stack initialize */
	ldr	r0, =__STACKS_END__

;#	msr	CPSR_c, #(0x17 | 0x80 | 0x40)	/* ABT */
;#	mov	sp, r0				/* STACK_BASE_ABT */

;#	msr	CPSR_c, #(0x1B | 0x80 | 0x40)	/* UND */
;#	sub	r0, r0, #0x80			/* STACK_BASE_UND */
;#	mov	sp, r0

;#	msr	CPSR_c, #(0x11 | 0x80 | 0x40)	/* FIQ */
;#	sub	r0, r0, #0x80			/* STACK_BASE_FIQ */
;#	mov	sp, r0

;#	msr	CPSR_c, #(0x12 | 0x80 | 0x40)	/* IRQ */
;#	sub	r0, r0, #0x80			/* STACK_BASE_IRQ */
;#	mov	sp, r0

;#	msr	CPSR_c, #(0x13 | 0x80 | 0x40)	/* SVC */
;#	sub	r0, r0, #0x80			/* STACK_BASE_SVC */
	mov	sp, r0


	/* Loader Main */
	BL     arch_main

NO_BOOT:
	nop
1:
;#	wfe
	b	1b


/*****************************************************************************
 *	Exception Handers
 *****************************************************************************/

	/* Undefined Instruction */
Undef:
	nop
1:
	wfe
	b	1b

	/* Supervisor Call */
SWI:
	nop
1:
	wfe
	b	1b

	/* Prefetch Abort */
PAbort:
	nop
1:
	wfe
	b	1b

	/* Data Abort */
DAbort:
	nop
1:
	wfe
	b	1b

	/* IRQ interrupt */
IRQ:
	nop
1:
	wfe
	b	1b

	/* FIQ interrupt */
FIQ:
	nop
1:
	wfe
	b	1b


/*****************************************************************************
 *	Define stack
 *****************************************************************************/
	.section tzfw_normal_stacks, "aw"
	.align   6

rtos_stacks:
	.space   4 * 1024

_shutdown_request:
    .long 0

    .align 4

	.end
