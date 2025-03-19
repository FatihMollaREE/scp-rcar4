
# Consider dependencies only in project.
set(CMAKE_DEPENDS_IN_PROJECT_ONLY OFF)

# The set of languages for which implicit dependencies are needed:
set(CMAKE_DEPENDS_LANGUAGES
  "ASM"
  )
# The set of files for implicit dependencies of each language:
set(CMAKE_DEPENDS_CHECK_ASM
  "C:/Users/a5137749/Documents/Abteilungen/shared/scp-rcar4/SCP-firmware/arch/arm/armv8-r/src/arch_crt0.S" "C:/Users/a5137749/Documents/Abteilungen/shared/scp-rcar4/SCP-firmware/DEBUGbuild/arch/armv8-r/CMakeFiles/arch-armv8r.dir/src/arch_crt0.S.obj"
  )
set(CMAKE_ASM_COMPILER_ID "GNU")

# Preprocessor definitions for this target.
set(CMAKE_TARGET_DEFINITIONS_ASM
  "BUILD_HAS_MOD_CLOCK=1"
  "BUILD_HAS_MOD_POWER_DOMAIN=1"
  "BUILD_HAS_MOD_RCAR4_CLOCK=1"
  "BUILD_HAS_MOD_RCAR4_MFISMH=1"
  "BUILD_HAS_MOD_RCAR4_PD_CORE=1"
  "BUILD_HAS_MOD_RCAR4_PD_SYSC=1"
  "BUILD_HAS_MOD_RCAR4_RESET=1"
  "BUILD_HAS_MOD_RCAR4_SYSTEM=1"
  "BUILD_HAS_MOD_RCAR4_SYSTEM_POWER=1"
  "BUILD_HAS_MOD_RESET_DOMAIN=1"
  "BUILD_HAS_MOD_SCMI=1"
  "BUILD_HAS_MOD_SCMI_RESET_DOMAIN=1"
  "BUILD_HAS_MOD_SDS=1"
  "BUILD_HAS_MOD_TRANSPORT=1"
  "BUILD_HAS_NOTIFICATION"
  "BUILD_HAS_OUTBAND_MSG_SUPPORT"
  "BUILD_HAS_SCMI_POWER_CAPPING_STD_COMMANDS"
  "BUILD_VERSION_DESCRIBE_STRING=\"v2.15.0-222-gaf4b6fef-dirty\""
  "BUILD_VERSION_MAJOR=2"
  "BUILD_VERSION_MINOR=15"
  "BUILD_VERSION_PATCH=0"
  "FWK_LOG_LEVEL=FWK_LOG_LEVEL_WARN"
  )

# The include file search paths:
set(CMAKE_ASM_TARGET_INCLUDE_PATH
  "../arch/arm/armv8-r/include"
  "../arch/arm/armv8-r/include/lib"
  "../product/rcar4/scp_ramfw/../src/CMSIS-FreeRTOS/Source/include"
  "../product/rcar4/scp_ramfw/../src/CMSIS-FreeRTOS/Source/portable/GCC/ARM_CA53_64_Rcar"
  "../product/rcar4/scp_ramfw/../include"
  "../product/rcar4/scp_ramfw"
  "../contrib/cmsis/git/CMSIS/RTOS2/Include"
  "../contrib/cmsis/git/CMSIS/Core/Include"
  "../framework/include"
  "framework/include"
  )

# The set of dependency files which are needed:
set(CMAKE_DEPENDS_DEPENDENCY_FILES
  "C:/Users/a5137749/Documents/Abteilungen/shared/scp-rcar4/SCP-firmware/arch/arm/armv8-r/src/arch_gic.c" "arch/armv8-r/CMakeFiles/arch-armv8r.dir/src/arch_gic.c.obj" "gcc" "arch/armv8-r/CMakeFiles/arch-armv8r.dir/src/arch_gic.c.obj.d"
  "C:/Users/a5137749/Documents/Abteilungen/shared/scp-rcar4/SCP-firmware/arch/arm/armv8-r/src/arch_main.c" "arch/armv8-r/CMakeFiles/arch-armv8r.dir/src/arch_main.c.obj" "gcc" "arch/armv8-r/CMakeFiles/arch-armv8r.dir/src/arch_main.c.obj.d"
  )

# Targets to which this target links.
set(CMAKE_TARGET_LINKED_INFO_FILES
  "C:/Users/a5137749/Documents/Abteilungen/shared/scp-rcar4/SCP-firmware/DEBUGbuild/framework/CMakeFiles/framework.dir/DependInfo.cmake"
  "C:/Users/a5137749/Documents/Abteilungen/shared/scp-rcar4/SCP-firmware/DEBUGbuild/module/modules/rcar4-pd-sysc/CMakeFiles/module-rcar4-pd-sysc.dir/DependInfo.cmake"
  "C:/Users/a5137749/Documents/Abteilungen/shared/scp-rcar4/SCP-firmware/DEBUGbuild/module/modules/rcar4-clock/CMakeFiles/module-rcar4-clock.dir/DependInfo.cmake"
  "C:/Users/a5137749/Documents/Abteilungen/shared/scp-rcar4/SCP-firmware/DEBUGbuild/module/modules/rcar4-pd-core/CMakeFiles/module-rcar4-pd-core.dir/DependInfo.cmake"
  "C:/Users/a5137749/Documents/Abteilungen/shared/scp-rcar4/SCP-firmware/DEBUGbuild/module/modules/rcar4-system/CMakeFiles/module-rcar4-system.dir/DependInfo.cmake"
  "C:/Users/a5137749/Documents/Abteilungen/shared/scp-rcar4/SCP-firmware/DEBUGbuild/module/modules/rcar4-system-power/CMakeFiles/module-rcar4-system-power.dir/DependInfo.cmake"
  "C:/Users/a5137749/Documents/Abteilungen/shared/scp-rcar4/SCP-firmware/DEBUGbuild/module/modules/rcar4-mfismh/CMakeFiles/module-rcar4-mfismh.dir/DependInfo.cmake"
  "C:/Users/a5137749/Documents/Abteilungen/shared/scp-rcar4/SCP-firmware/DEBUGbuild/module/modules/rcar4-reset/CMakeFiles/module-rcar4-reset.dir/DependInfo.cmake"
  "C:/Users/a5137749/Documents/Abteilungen/shared/scp-rcar4/SCP-firmware/DEBUGbuild/module/modules/clock/CMakeFiles/module-clock.dir/DependInfo.cmake"
  "C:/Users/a5137749/Documents/Abteilungen/shared/scp-rcar4/SCP-firmware/DEBUGbuild/module/modules/power-domain/CMakeFiles/module-power-domain.dir/DependInfo.cmake"
  "C:/Users/a5137749/Documents/Abteilungen/shared/scp-rcar4/SCP-firmware/DEBUGbuild/module/modules/reset-domain/CMakeFiles/module-reset-domain.dir/DependInfo.cmake"
  "C:/Users/a5137749/Documents/Abteilungen/shared/scp-rcar4/SCP-firmware/DEBUGbuild/module/modules/scmi/CMakeFiles/module-scmi.dir/DependInfo.cmake"
  "C:/Users/a5137749/Documents/Abteilungen/shared/scp-rcar4/SCP-firmware/DEBUGbuild/module/modules/scmi-reset-domain/CMakeFiles/module-scmi-reset-domain.dir/DependInfo.cmake"
  "C:/Users/a5137749/Documents/Abteilungen/shared/scp-rcar4/SCP-firmware/DEBUGbuild/module/modules/sds/CMakeFiles/module-sds.dir/DependInfo.cmake"
  "C:/Users/a5137749/Documents/Abteilungen/shared/scp-rcar4/SCP-firmware/DEBUGbuild/module/modules/transport/CMakeFiles/module-transport.dir/DependInfo.cmake"
  )

# Fortran module output directory.
set(CMAKE_Fortran_TARGET_MODULE_DIR "")
