/*
 * Copyright (c) 2015-2023, Renesas Electronics Corporation
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
#include "scif.h"
#include "timer.h"

/************************************************************************************************/
/*	Definitions																					*/
/************************************************************************************************/


/************************************************************************************************/
/*	Unions																						*/
/************************************************************************************************/


/************************************************************************************************/
/*	Structs																						*/
/************************************************************************************************/


/************************************************************************************************/
/*	Globals																						*/
/************************************************************************************************/


/************************************************************************************************/
/*	Macros																						*/
/************************************************************************************************/
#define MIDR_PN_SHIFT			(0x4U)
#define MIDR_PN_MASK			(0X0FFFU)
#define MIDR_CA57			(0x0D07U << MIDR_PN_SHIFT)
#define MIDR_CA53			(0x0D03U << MIDR_PN_SHIFT)
#define MIDR_CR7			(0x0C17U << MIDR_PN_SHIFT)
/* Input Dummy Program waiting time (us) */
#define WAIT_TIME_US    (2000000U)

/************************************************************************************************/
/*	Prototypes																					*/
/************************************************************************************************/
uint32_t arch_main(void);


uint32_t arch_main(void)
{
	scif_init();

    generic_timer_init();

    micro_wait(WAIT_TIME_US);

	PutStr("  ",1);
	PutStr("Dummy RTOS Program  Fatihs test",1);
	PutStr("Dummy RTOS Program boot end  Fatihs test End",1);

	return 0U;
}
