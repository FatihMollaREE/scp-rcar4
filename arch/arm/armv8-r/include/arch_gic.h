/*
*
* License
*
*/

#ifndef ARMV8R_GIC_H
#define ARMV8R_GIC_H

#include <fwk_arch.h>

#include <arch_helpers.h>
#include "../include/utils_def.h"

#include "gic.h"

// fatih: tmp gicc define

void gic_init(void);
int arm_gic_init(const struct fwk_arch_interrupt_driver **driver);
void irq_global(uint32_t iid);

#endif /* ARMV8R_GIC_H */
