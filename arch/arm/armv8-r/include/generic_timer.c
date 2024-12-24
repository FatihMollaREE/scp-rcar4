/*******************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only
* intended for use with Renesas products. No other uses are authorized. This
* software is owned by Renesas Electronics Corporation and is protected under
* all applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
* AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software
* and to discontinue the availability of this software. By using this software,
* you agree to the additional terms and conditions found by accessing the
* following link:
* http://www.renesas.com/disclaimer
* Copyright 2023 Renesas Electronics Corporation All rights reserved.
*******************************************************************************/


/*******************************************************************************
 * DESCRIPTION   : generic timer
 ******************************************************************************/
/******************************************************************************
 * @file          generic_timer.c
 * - Version      : 0.01
 * @brief
 * .
 *****************************************************************************/
/******************************************************************************
 * History : DD.MM.YYYY Version  Description
 *         : 14.09.2023 0.01     First Release
 *****************************************************************************/

#include <stdint.h>
#include <timer.h>
#include "scif.h"

#define RCAR_CNTC_EXTAL     (16666600U) /* V4H/V4M : 16.666600MHz */

#define RCAR_CONV_MICROSEC  (1000000U)

static inline uint32_t get_cntfrq(void)
{
    uint32_t    freq;
    __asm__ volatile("mrc p15, 0, %0, c14, c0, 0" : "=r" (freq));

    return(freq);
}

static inline void set_cntfrq(uint32_t reg_cntfid)
{
    __asm__ volatile("mcr p15, 0, %0, c14, c0, 0" : : "r" (reg_cntfid));
}

static inline uint64_t get_cntpct(void)
{
    uint64_t    base_count;
    __asm__ volatile ("mrrc p15, 0, %Q0, %R0, c14" : "=r" (base_count));

    return(base_count);
}

void generic_timer_init(void)
{
    /* Update memory mapped and register based freqency */
    /* AArch32:cntfrq */
    set_cntfrq(RCAR_CNTC_EXTAL);
}
/* End of function generic_timer_init(void) */

void micro_wait(uint64_t micro_sec)
{
    uint64_t base_count = 0U;
    uint64_t get_count  = 0U;
    uint64_t wait_time  = 0U;
    uint32_t freq       = 0U;


    /* cntfrq */
    freq = get_cntfrq();
    /* cntpct */
    base_count = get_cntpct();

    micro_sec *= freq;
    while (micro_sec > wait_time)
    {
        /* cntpct */
        get_count = get_cntpct();

        /* INT30-C Pre confirmation */
        if (get_count < base_count)
        {
            PutStr("micro_wait(Timer value error!!).", 1U);
            while(1U);   /* panic */
        }
        else
        {
            wait_time = ((get_count - base_count) * RCAR_CONV_MICROSEC);
        }
    }
}
/* End of function micro_wait(uint64_t micro_sec) */

