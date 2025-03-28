#
# Arm SCP/MCP Software
# Copyright (c) 2022-2024, Arm Limited and Contributors. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#

set(TEST_SRC mod_transport)
set(TEST_FILE mod_transport)

set(UNIT_TEST_TARGET mod_${TEST_MODULE}_unit_test)

set(MODULE_SRC ${MODULE_ROOT}/${TEST_MODULE}/src)
set(MODULE_INC ${MODULE_ROOT}/${TEST_MODULE}/include)
set(MODULE_UT_SRC ${CMAKE_CURRENT_LIST_DIR})
set(MODULE_UT_INC ${CMAKE_CURRENT_LIST_DIR})
set(MODULE_UT_MOCK_SRC ${CMAKE_CURRENT_LIST_DIR}/mocks)

list(APPEND MOCK_REPLACEMENTS fwk_core)
list(APPEND MOCK_REPLACEMENTS fwk_module)
list(APPEND MOCK_REPLACEMENTS fwk_id)
list(APPEND MOCK_REPLACEMENTS fwk_notification)

include(${SCP_ROOT}/unit_test/module_common.cmake)

target_compile_definitions(${UNIT_TEST_TARGET} PUBLIC
    "BUILD_HAS_SCMI_NOTIFICATION")

target_compile_definitions(${UNIT_TEST_TARGET} PRIVATE BUILD_HAS_MOD_TRANSPORT)
target_compile_definitions(${UNIT_TEST_TARGET} PUBLIC BUILD_HAS_INBAND_MSG_SUPPORT)
target_compile_definitions(${UNIT_TEST_TARGET} PUBLIC BUILD_HAS_OUTBAND_MSG_SUPPORT)
target_compile_definitions(${UNIT_TEST_TARGET} PRIVATE BUILD_HAS_NOTIFICATION)
