#
#
# LICENSE
#
#

#set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -march=armv8-r -mthumb")

add_executable(rcar4-bl)

target_include_directories(
    rcar4-bl
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/../src/CMSIS-FreeRTOS/Source/include"
        "${CMAKE_CURRENT_SOURCE_DIR}/../src/CMSIS-FreeRTOS/Source/portable/GCC/ARM_CA53_64_Rcar"
        "${CMAKE_CURRENT_SOURCE_DIR}/../include"
        "${CMAKE_CURRENT_SOURCE_DIR}")


# cmake-lint: disable=E1122

set(freertos_source "${CMAKE_CURRENT_SOURCE_DIR}/../src/CMSIS-FreeRTOS/Source")
set(freertos2_source
    "${CMAKE_CURRENT_SOURCE_DIR}/../src/CMSIS-FreeRTOS/CMSIS/RTOS2/FreeRTOS/Source")
    
target_sources(
    rcar4-bl
    PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/config_power_domain.c"
            "${CMAKE_CURRENT_SOURCE_DIR}/config_rcar4_pd_sysc.c"
            "${CMAKE_CURRENT_SOURCE_DIR}/config_rcar4_pd_core.c"
            "${CMAKE_CURRENT_SOURCE_DIR}/config_clock.c"
            "${CMAKE_CURRENT_SOURCE_DIR}/config_rcar4_clock.c"
            "${CMAKE_CURRENT_SOURCE_DIR}/config_rcar4_mfismh.c"
            "${CMAKE_CURRENT_SOURCE_DIR}/config_transport.c"
            "${CMAKE_CURRENT_SOURCE_DIR}/config_scmi.c"
            "${CMAKE_CURRENT_SOURCE_DIR}/config_rcar4_system_power.c"
            "${CMAKE_CURRENT_SOURCE_DIR}/config_rcar4_system.c"
            "${CMAKE_CURRENT_SOURCE_DIR}/config_sds.c"
            "${CMAKE_CURRENT_SOURCE_DIR}/../src/rcar4_core.c"
            "${CMAKE_CURRENT_SOURCE_DIR}/../src/rcar4_syscalls.c"
            "${freertos_source}/timers.c"
            "${freertos_source}/list.c"
            "${freertos_source}/queue.c"
            "${freertos_source}/tasks.c"
            "${freertos_source}/portable/MemMang/heap_1.c"
            "${freertos_source}/portable/GCC/ARM_CA53_64_Rcar/portASM.S"
            "${freertos_source}/portable/GCC/ARM_CA53_64_Rcar/port.c"
            "${freertos2_source}/cmsis_os2_tiny4scp.c")

    if(SCP_ENABLE_SCMI_RESET)
    target_sources(rcar4-bl
        PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/config_rcar4_reset.c"
                "${CMAKE_CURRENT_SOURCE_DIR}/config_reset_domain.c"
                "${CMAKE_CURRENT_SOURCE_DIR}/config_scmi_reset_domain.c"
)

endif()

target_include_directories(rcar4-bl
    PUBLIC $<TARGET_PROPERTY:cmsis::rtos2,INTERFACE_INCLUDE_DIRECTORIES>)

target_include_directories(rcar4-bl
    PUBLIC $<TARGET_PROPERTY:cmsis::core-m,INTERFACE_INCLUDE_DIRECTORIES>) # fatih: core m offensichtlich passt das nicht ganz, ich glaube ich benutzte aber nur die sachen die core unabhängig sind

if(SCP_ENABLE_SCMI_RESET)
    list(APPEND SCP_MODULES "reset-domain")
    list(APPEND SCP_MODULES "rcar4-reset")
    list(APPEND SCP_MODULES "scmi-reset-domain")

endif()

set(SCP_MODULES ${SCP_MODULES} PARENT_SCOPE)
set(SCP_MODULE_PATHS ${SCP_MODULE_PATHS} PARENT_SCOPE)