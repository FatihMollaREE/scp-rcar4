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

#ifndef __SCIF_H__
#define __SCIF_H__


//SCIF0
#define SCIF_BASE_0     (0xE6E60000U)
#define	SCIF_SCSMR_0	(SCIF_BASE_0 + 0x0000)	// R/W	16	Serial mode register
#define	SCIF_SCBRR_0	(SCIF_BASE_0 + 0x0004)	// R/W	8	Bit rate register
#define	SCIF_SCSCR_0	(SCIF_BASE_0 + 0x0008)	// R/W	16	Serial control register
#define	SCIF_SCFTDR_0 	(SCIF_BASE_0 + 0x000C)	// W	8	Transmit FIFO data register
#define	SCIF_SCFSR_0	(SCIF_BASE_0 + 0x0010)	// R/W	16	Serial status register
#define	SCIF_SCFRDR_0	(SCIF_BASE_0 + 0x0014)	// R	8	Receive FIFO data register
#define	SCIF_SCFCR_0	(SCIF_BASE_0 + 0x0018)	// R/W	16	FIFO control register
#define	SCIF_SCFDR_0	(SCIF_BASE_0 + 0x001C)	// R	16	FIFO data count register
#define	SCIF_SCSPTR_0	(SCIF_BASE_0 + 0x0020)	// R/W	16	Serial port register
#define	SCIF_SCLSR_0	(SCIF_BASE_0 + 0x0024)	// R/W	16	Line status register
#define	SCIF_DL_0		(SCIF_BASE_0 + 0x0030)	// R/W	16	Frequency division register
#define	SCIF_CKS_0		(SCIF_BASE_0 + 0x0034)	// R/W	16	Clock Select register

//SCIF3
#define SCIF_BASE_3     (0xE6C50000U)
#define	SCIF_SCSMR_3	(SCIF_BASE_3 + 0x0000)	// R/W	16	Serial mode register
#define	SCIF_SCBRR_3	(SCIF_BASE_3 + 0x0004)	// R/W	8	Bit rate register
#define	SCIF_SCSCR_3	(SCIF_BASE_3 + 0x0008)	// R/W	16	Serial control register
#define	SCIF_SCFTDR_3 	(SCIF_BASE_3 + 0x000C)	// W	8	Transmit FIFO data register
#define	SCIF_SCFSR_3	(SCIF_BASE_3 + 0x0010)	// R/W	16	Serial status register
#define	SCIF_SCFRDR_3	(SCIF_BASE_3 + 0x0014)	// R	8	Receive FIFO data register
#define	SCIF_SCFCR_3	(SCIF_BASE_3 + 0x0018)	// R/W	16	FIFO control register
#define	SCIF_SCFDR_3	(SCIF_BASE_3 + 0x001C)	// R	16	FIFO data count register
#define	SCIF_SCSPTR_3	(SCIF_BASE_3 + 0x0020)	// R/W	16	Serial port register
#define	SCIF_SCLSR_3	(SCIF_BASE_3 + 0x0024)	// R/W	16	Line status register
#define	SCIF_DL_3		(SCIF_BASE_3 + 0x0030)	// R/W	16	Frequency division register
#define	SCIF_CKS_3		(SCIF_BASE_3 + 0x0034)	// R/W	16	Clock Select register

/* HSCIF0 */
#define HSCIF_BASE      (0xE6540000U)
#define	HSCIF_HSSMR		(HSCIF_BASE + 0x0000U)	// R/W	16	Serial mode register
#define	HSCIF_HSBRR		(HSCIF_BASE + 0x0004U)	// R/W	8	Bit rate register
#define	HSCIF_HSSCR		(HSCIF_BASE + 0x0008U)	// R/W	16	Serial control register
#define	HSCIF_HSFTDR	(HSCIF_BASE + 0x000CU)	// W	8	Transmit FIFO data register
#define	HSCIF_HSFSR		(HSCIF_BASE + 0x0010U)	// R/W	16	Serial status register
#define	HSCIF_HSFRDR	(HSCIF_BASE + 0x0014U)	// R	8	Receive FIFO data register
#define	HSCIF_HSFCR		(HSCIF_BASE + 0x0018U)	// R/W	16	FIFO control register
#define	HSCIF_HSFDR		(HSCIF_BASE + 0x001CU)	// R	16	FIFO data count register
#define	HSCIF_HSSPTR	(HSCIF_BASE + 0x0020U)	// R/W	16	Serial port register
#define	HSCIF_HSLSR		(HSCIF_BASE + 0x0024U)	// R/W	16	Line status register
#define HSCIF_HSSRR		(HSCIF_BASE + 0x0040U)	// R/W	16	Sampling rate register
/* BRG */
#define	HSCIF_DL	    (HSCIF_BASE + 0x0030U)	// R/W	16	Frequency division register
#define	HSCIF_CKS	    (HSCIF_BASE + 0x0034U)	// R/W	16	Clock select register

#define CR_CODE			(0x0DU)
#define LF_CODE			(0x0AU)

void scif_init(void);
void PutStr(const char *str,char rtn);
void PutChar(char outChar);


#endif	/* __SCIF_H__ */
