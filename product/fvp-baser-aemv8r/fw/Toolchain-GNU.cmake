#
# Arm SCP/MCP Software
# Copyright (c) 2024, Arm Limited and Contributors. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#

include_guard()

set(CMAKE_SYSTEM_PROCESSOR "aarch64")

set(SCP_AARCH64_PROCESSOR_TARGET "cortex-r82")

set(CMAKE_TOOLCHAIN_PREFIX "aarch64-none-elf-")

include(
    "${CMAKE_CURRENT_LIST_DIR}/../../../cmake/Toolchain/GNU-Baremetal.cmake")
