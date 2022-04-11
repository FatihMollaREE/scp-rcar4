#
# Arm SCP/MCP Software
# Copyright (c) 2020-2022, Arm Limited and Contributors. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
# The order of the modules in the BS_FIRMWARE_MODULES list is the order in which
# the modules are initialized, bound, started during the pre-runtime phase.
#

BS_FIRMWARE_CPU := cortex-m7
BS_FIRMWARE_HAS_NOTIFICATION := yes
BS_FIRMWARE_USE_NEWLIB_NANO_SPECS := yes

BS_FIRMWARE_MODULE_HEADERS_ONLY := timer \
                                   power_domain

BS_FIRMWARE_MODULES := \
    pl011 \
    fip \
    morello_rom \
    clock

BS_FIRMWARE_SOURCES := \
    config_pl011.c \
    config_morello_rom.c \
    config_clock.c \
    config_fip.c

include $(BS_DIR)/firmware.mk
