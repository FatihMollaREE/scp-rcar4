#
# LICENSE
#

set(SCP_FIRMWARE "rcar4-bl")

set(SCP_FIRMWARE_TARGET "rcar4-bl")

set(SCP_TOOLCHAIN_INIT "GNU")

set(SCP_GENERATE_FLAT_BINARY_INIT TRUE)

set(SCP_ENABLE_NOTIFICATIONS_INIT TRUE) 

set(SCP_ENABLE_SCMI_RESET_INIT TRUE)

set(SCP_ENABLE_IPO_INIT FALSE)

set(SCP_ENABLE_OUTBAND_MSG_SUPPORT_INIT TRUE)

set(SCP_ARCHITECTURE "armv8-r") 
                                                                   
list(PREPEND SCP_MODULE_PATHS "${CMAKE_CURRENT_LIST_DIR}/../module/rcar4_reset")
list(PREPEND SCP_MODULE_PATHS "${CMAKE_CURRENT_LIST_DIR}/../module/rcar4_mfismh")
list(PREPEND SCP_MODULE_PATHS "${CMAKE_CURRENT_LIST_DIR}/../module/rcar4_system_power")
list(PREPEND SCP_MODULE_PATHS "${CMAKE_CURRENT_LIST_DIR}/../module/rcar4_system")
list(PREPEND SCP_MODULE_PATHS "${CMAKE_CURRENT_LIST_DIR}/../module/rcar4_pd_core")
list(PREPEND SCP_MODULE_PATHS "${CMAKE_CURRENT_LIST_DIR}/../module/rcar4_clock")
list(PREPEND SCP_MODULE_PATHS "${CMAKE_CURRENT_LIST_DIR}/../module/rcar4_pd_sysc")

list(APPEND SCP_MODULES "rcar4-system")
list(APPEND SCP_MODULES "scmi")
list(APPEND SCP_MODULES "transport")
list(APPEND SCP_MODULES "clock")
list(APPEND SCP_MODULES "rcar4-clock")
list(APPEND SCP_MODULES "rcar4-system-power")
list(APPEND SCP_MODULES "rcar4-mfismh")
list(APPEND SCP_MODULES "power-domain")
list(APPEND SCP_MODULES "rcar4-pd-sysc")
list(APPEND SCP_MODULES "rcar4-pd-core")
list(APPEND SCP_MODULES "sds")