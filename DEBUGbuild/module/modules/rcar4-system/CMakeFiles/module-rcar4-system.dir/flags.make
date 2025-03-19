# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

# compile ASM with C:/Program Files (x86)/Arm GNU Toolchain arm-none-eabi/13.3 rel1/bin/arm-none-eabi-gcc.exe
# compile C with C:/Program Files (x86)/Arm GNU Toolchain arm-none-eabi/13.3 rel1/bin/arm-none-eabi-gcc.exe
ASM_DEFINES = -DBUILD_HAS_MOD_CLOCK=1 -DBUILD_HAS_MOD_POWER_DOMAIN=1 -DBUILD_HAS_MOD_RCAR4_CLOCK=1 -DBUILD_HAS_MOD_RCAR4_MFISMH=1 -DBUILD_HAS_MOD_RCAR4_PD_CORE=1 -DBUILD_HAS_MOD_RCAR4_PD_SYSC=1 -DBUILD_HAS_MOD_RCAR4_RESET=1 -DBUILD_HAS_MOD_RCAR4_SYSTEM=1 -DBUILD_HAS_MOD_RCAR4_SYSTEM_POWER=1 -DBUILD_HAS_MOD_RESET_DOMAIN=1 -DBUILD_HAS_MOD_SCMI=1 -DBUILD_HAS_MOD_SCMI_RESET_DOMAIN=1 -DBUILD_HAS_MOD_SDS=1 -DBUILD_HAS_MOD_TRANSPORT=1 -DBUILD_HAS_NOTIFICATION -DBUILD_HAS_OUTBAND_MSG_SUPPORT -DBUILD_HAS_SCMI_POWER_CAPPING_STD_COMMANDS -DBUILD_VERSION_DESCRIBE_STRING=\"v2.15.0-222-gaf4b6fef-dirty\" -DBUILD_VERSION_MAJOR=2 -DBUILD_VERSION_MINOR=15 -DBUILD_VERSION_PATCH=0 -DFWK_LOG_LEVEL=FWK_LOG_LEVEL_WARN

ASM_INCLUDES = -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\product\rcar4\module\rcar4_system\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\product\rcar4\module\rcar4_system\src -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\product\rcar4\scp_ramfw\..\src\CMSIS-FreeRTOS\Source\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\product\rcar4\scp_ramfw\..\src\CMSIS-FreeRTOS\Source\portable\GCC\ARM_CA53_64_Rcar -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\product\rcar4\scp_ramfw\..\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\product\rcar4\scp_ramfw -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\contrib\cmsis\git\CMSIS\RTOS2\Include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\contrib\cmsis\git\CMSIS\Core\Include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\sds\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\framework\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\DEBUGbuild\framework\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\arch\arm\armv8-r\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\arch\arm\armv8-r\include\lib -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\product\rcar4\module\rcar4_clock\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\clock\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\scmi\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\system_power\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\power_domain\include

ASM_FLAGS = -ffunction-sections -fdata-sections -fshort-enums -Wall -Werror -Wextra -Wno-error=deprecated-declarations -Wno-unused-parameter -Wno-missing-field-initializers -Og -g

C_DEFINES = -DBUILD_HAS_MOD_CLOCK=1 -DBUILD_HAS_MOD_POWER_DOMAIN=1 -DBUILD_HAS_MOD_RCAR4_CLOCK=1 -DBUILD_HAS_MOD_RCAR4_MFISMH=1 -DBUILD_HAS_MOD_RCAR4_PD_CORE=1 -DBUILD_HAS_MOD_RCAR4_PD_SYSC=1 -DBUILD_HAS_MOD_RCAR4_RESET=1 -DBUILD_HAS_MOD_RCAR4_SYSTEM=1 -DBUILD_HAS_MOD_RCAR4_SYSTEM_POWER=1 -DBUILD_HAS_MOD_RESET_DOMAIN=1 -DBUILD_HAS_MOD_SCMI=1 -DBUILD_HAS_MOD_SCMI_RESET_DOMAIN=1 -DBUILD_HAS_MOD_SDS=1 -DBUILD_HAS_MOD_TRANSPORT=1 -DBUILD_HAS_NOTIFICATION -DBUILD_HAS_OUTBAND_MSG_SUPPORT -DBUILD_HAS_SCMI_POWER_CAPPING_STD_COMMANDS -DBUILD_VERSION_DESCRIBE_STRING=\"v2.15.0-222-gaf4b6fef-dirty\" -DBUILD_VERSION_MAJOR=2 -DBUILD_VERSION_MINOR=15 -DBUILD_VERSION_PATCH=0 -DFWK_LOG_LEVEL=FWK_LOG_LEVEL_WARN

C_INCLUDES = -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\product\rcar4\module\rcar4_system\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\product\rcar4\module\rcar4_system\src -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\product\rcar4\scp_ramfw\..\src\CMSIS-FreeRTOS\Source\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\product\rcar4\scp_ramfw\..\src\CMSIS-FreeRTOS\Source\portable\GCC\ARM_CA53_64_Rcar -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\product\rcar4\scp_ramfw\..\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\product\rcar4\scp_ramfw -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\contrib\cmsis\git\CMSIS\RTOS2\Include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\contrib\cmsis\git\CMSIS\Core\Include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\sds\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\framework\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\DEBUGbuild\framework\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\arch\arm\armv8-r\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\arch\arm\armv8-r\include\lib -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\product\rcar4\module\rcar4_clock\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\clock\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\scmi\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\system_power\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\power_domain\include

C_FLAGS = -ffunction-sections -fdata-sections -fshort-enums -Wall -Werror -Wextra -Wno-error=deprecated-declarations -Wno-unused-parameter -Wno-missing-field-initializers -Og -g -std=gnu11

