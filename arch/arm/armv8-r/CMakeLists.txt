#
# License
#


include(SCPTargetLinkerScript)

set(scp_lds "${CMAKE_CURRENT_SOURCE_DIR}/src/arch.ld.S")

scp_target_linker_script(arch-armv8r "${scp_lds}")
