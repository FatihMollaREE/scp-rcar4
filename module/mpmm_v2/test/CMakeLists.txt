#
# Arm SCP/MCP Software
# Copyright (c) 2024, Arm Limited and Contributors. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#

set(TEST_SRC mod_mpmm_v2)
set(TEST_FILE mod_mpmm_v2)

set(UNIT_TEST_TARGET mod_${TEST_MODULE}_unit_test)

set(MODULE_SRC ${MODULE_ROOT}/${TEST_MODULE}/src)
set(MODULE_INC ${MODULE_ROOT}/${TEST_MODULE}/include)
set(MODULE_UT_SRC ${CMAKE_CURRENT_LIST_DIR})
set(MODULE_UT_INC ${CMAKE_CURRENT_LIST_DIR})
set(MODULE_UT_MOCK_SRC ${CMAKE_CURRENT_LIST_DIR}/mocks)

list(APPEND MOCK_REPLACEMENTS fwk_id)
list(APPEND MOCK_REPLACEMENTS fwk_core)
list(APPEND MOCK_REPLACEMENTS fwk_mm)
list(APPEND MOCK_REPLACEMENTS fwk_module)
list(APPEND MOCK_REPLACEMENTS fwk_notification)

list(APPEND OTHER_MODULE_INC ${MODULE_ROOT}/power_domain/include)
list(APPEND OTHER_MODULE_INC ${MODULE_ROOT}/metrics_analyzer/include)
list(APPEND OTHER_MODULE_INC ${MODULE_ROOT}/perf_controller/include)
list(APPEND OTHER_MODULE_INC ${SCP_ROOT}/interface/amu)
list(APPEND OTHER_MODULE_INC ${SCP_ROOT}/interface/power_management)

include(${SCP_ROOT}/unit_test/module_common.cmake)

target_compile_definitions(${UNIT_TEST_TARGET} PUBLIC "BUILD_HAS_NOTIFICATION")
target_compile_definitions(${UNIT_TEST_TARGET} PUBLIC
                           "BUILD_HAS_MOD_POWER_DOMAIN")
target_compile_definitions(${UNIT_TEST_TARGET} PUBLIC
                           "BUILD_HAS_MOD_PERF_CONTROLLER")
