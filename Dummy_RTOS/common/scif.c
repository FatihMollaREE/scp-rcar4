/*
 * Copyright (c) 2015-2018, Renesas Electronics Corporation
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

#include <stdint.h>
#include <scif.h>
#include "reg_rcar_gen3.h"

#define	RST_MODEMR0						0xE6160000	// R	32	Mode Monitor Register
#define RST_MODEMR1						0xE6160004	// R	32	Mode Monitor Register2

#define MODEMR0_MD31_V3U		(0x80000000U)
#define MODEMR1_MD32_V3U		(0x00000001U)
#define MODEMR_SCIF_115200_V3U		(0x00000000U)
#define MODEMR_SCIF_921600_V3U		(0x80000000U)
#define MODEMR_SCIF_1843200_V3U		(0x00000001U)
#define MODEMR_SCIF_3000000_V3U		(0x80000001U)

static void (*putc)(char);

static void scif0_PutChar(char outchar);
static void scif3_PutChar(char outchar);
static void hscif_PutChar(char outchar);

/************************************************************************/
/*NAME		: PutStr						*/
/************************************************************************/
void PutStr(const char *str,char rtn)
{
	while(*str){
		PutChar(*str);
		str++;
	}
	if(rtn == 1){
		PutChar(CR_CODE);
		PutChar(LF_CODE);
	}
}

void scif_init(void)
{
	uint32_t product;
	uint32_t modemr0;
	uint32_t modemr1;
	
	product = *((volatile uint32_t*)RCAR_PRR) & RCAR_PRODUCT_MASK;
	switch (product) {
	case RCAR_PRODUCT_S4:
		modemr0 = *((volatile uint32_t*)RST_MODEMR0) & MODEMR0_MD31_V3U;	/* bit31 */
		modemr1 = *((volatile uint32_t*)RST_MODEMR1) & MODEMR1_MD32_V3U;	/* bit0  */
		
		switch (modemr0 | modemr1) {
		case MODEMR_SCIF_115200_V3U:	/* 0x00000000 */
			putc = scif3_PutChar;
			break;
		case MODEMR_SCIF_921600_V3U:	/* 0x80000000 */
		case MODEMR_SCIF_1843200_V3U:	/* 0x00000001 */
		case MODEMR_SCIF_3000000_V3U:	/* 0x80000001 */
			putc = hscif_PutChar;
			break;
		default:
			break;
		}
		break;
	case RCAR_PRODUCT_V4H:
	case RCAR_PRODUCT_V4M:
		modemr0 = *((volatile uint32_t*)RST_MODEMR0) & MODEMR0_MD31_V3U;	/* bit31 */
		modemr1 = *((volatile uint32_t*)RST_MODEMR1) & MODEMR1_MD32_V3U;	/* bit0  */
		
		switch (modemr0 | modemr1) {
		case MODEMR_SCIF_115200_V3U:	/* 0x00000000 */
			putc = scif0_PutChar;
			break;
		case MODEMR_SCIF_921600_V3U:	/* 0x80000000 */
		case MODEMR_SCIF_1843200_V3U:	/* 0x00000001 */
		case MODEMR_SCIF_3000000_V3U:	/* 0x80000001 */
			putc = hscif_PutChar;
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

void PutChar(char outChar)
{
	putc(outChar);
}

static void scif0_PutChar(char outChar)
{
	while(!(0x60 & *((volatile uint16_t*)SCIF_SCFSR_0) ));
	*((volatile uint8_t*)SCIF_SCFTDR_0) = outChar;
	*((volatile uint16_t*)SCIF_SCFSR_0) &= ~0x60;	/* TEND,TDFE clear */
}

static void scif3_PutChar(char outChar)
{
	while(!(0x60 & *((volatile uint16_t*)SCIF_SCFSR_3) ));
	*((volatile uint8_t*)SCIF_SCFTDR_3) = outChar;
	*((volatile uint16_t*)SCIF_SCFSR_3) &= ~0x60;	/* TEND,TDFE clear */
}

static void hscif_PutChar(char outChar)
{
	while(!(0x60 & *((volatile uint16_t*)HSCIF_HSFSR) ));
	*((volatile uint8_t*)HSCIF_HSFTDR) = outChar;
	*((volatile uint16_t*)HSCIF_HSFSR) &= ~0x60;	/* TEND,TDFE clear */
}
