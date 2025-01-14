#
#
# LICENSE
#
#


add_executable(rcar4-bl)

target_include_directories(
    rcar4-bl
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/../include"
        "${CMAKE_CURRENT_SOURCE_DIR}")


target_sources(
    rcar4-bl
    PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/config_scmi.c"
            "${CMAKE_CURRENT_SOURCE_DIR}/config_transport.c"
            "${CMAKE_CURRENT_SOURCE_DIR}/../src/rcar4_core.c")

    if(SCP_ENABLE_SCMI_RESET)
    target_sources(rcar4-bl
        PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/config_rcar4_reset.c"
                "${CMAKE_CURRENT_SOURCE_DIR}/config_reset_domain.c"
                "${CMAKE_CURRENT_SOURCE_DIR}/config_scmi_reset_domain.c"
)

endif()

if(SCP_ENABLE_SCMI_RESET)
    list(APPEND SCP_MODULES "reset-domain")
    list(APPEND SCP_MODULES "rcar4-reset")
    list(APPEND SCP_MODULES "scmi-reset-domain")

endif()

set(SCP_MODULES ${SCP_MODULES} PARENT_SCOPE)
set(SCP_MODULE_PATHS ${SCP_MODULE_PATHS} PARENT_SCOPE)