#
# License
#

# Setze die Assembler-Flags für ARMv8-R Architektur : Fatih: vielleicht sollte ich das woanders hintun
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -march=armv8-r")

add_library(arch-armv8r)

target_include_directories(
    arch-armv8r
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/lib")

# cmake-lint: disable=E1122

target_sources(
    arch-armv8r
    PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src/arch_crt0.S"
            "${CMAKE_CURRENT_SOURCE_DIR}/src/arch_gic.c"
            "${CMAKE_CURRENT_SOURCE_DIR}/src/arch_main.c")

            
include(SCPTargetLinkerScript)

set(scp_lds "${CMAKE_CURRENT_SOURCE_DIR}/src/arch.ld.S")

scp_target_linker_script(arch-armv8r "${scp_lds}")
