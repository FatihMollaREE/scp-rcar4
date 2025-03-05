# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

# compile ASM with C:/Program Files (x86)/Arm GNU Toolchain arm-none-eabi/13.3 rel1/bin/arm-none-eabi-gcc.exe
# compile C with C:/Program Files (x86)/Arm GNU Toolchain arm-none-eabi/13.3 rel1/bin/arm-none-eabi-gcc.exe
ASM_DEFINES = -DBUILD_HAS_MOD_CLOCK=1 -DBUILD_HAS_MOD_POWER_DOMAIN=1 -DBUILD_HAS_MOD_RCAR4_CLOCK=1 -DBUILD_HAS_MOD_RCAR4_MFISMH=1 -DBUILD_HAS_MOD_RCAR4_PD_CORE=1 -DBUILD_HAS_MOD_RCAR4_PD_SYSC=1 -DBUILD_HAS_MOD_RCAR4_RESET=1 -DBUILD_HAS_MOD_RCAR4_SYSTEM=1 -DBUILD_HAS_MOD_RCAR4_SYSTEM_POWER=1 -DBUILD_HAS_MOD_RESET_DOMAIN=1 -DBUILD_HAS_MOD_SCMI=1 -DBUILD_HAS_MOD_SCMI_RESET_DOMAIN=1 -DBUILD_HAS_MOD_SDS=1 -DBUILD_HAS_MOD_TRANSPORT=1 -DBUILD_HAS_NOTIFICATION -DBUILD_HAS_OUTBAND_MSG_SUPPORT -DBUILD_HAS_SCMI_POWER_CAPPING_STD_COMMANDS -DBUILD_MODE_DEBUG -DBUILD_VERSION_DESCRIBE_STRING=\"v2.15.0-219-gde8d2833-dirty\" -DBUILD_VERSION_MAJOR=2 -DBUILD_VERSION_MINOR=15 -DBUILD_VERSION_PATCH=0 -DFWK_LOG_LEVEL=FWK_LOG_LEVEL_WARN

ASM_INCLUDES = -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\product\rcar4\scp_ramfw\..\src\CMSIS-FreeRTOS\Source\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\product\rcar4\scp_ramfw\..\src\CMSIS-FreeRTOS\Source\portable\GCC\ARM_CA53_64_Rcar -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\product\rcar4\scp_ramfw\..\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\product\rcar4\scp_ramfw -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\contrib\cmsis\git\CMSIS\RTOS2\Include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\contrib\cmsis\git\CMSIS\Core\Include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\arch\arm\armv8-r\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\arch\arm\armv8-r\include\lib -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\product\rcar4\module\rcar4_pd_sysc\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\power_domain\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\framework\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\DEBUGbuild\framework\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\product\rcar4\module\rcar4_clock\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\clock\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\product\rcar4\module\rcar4_pd_core\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\product\rcar4\module\rcar4_system\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\product\rcar4\module\rcar4_system_power\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\product\rcar4\module\rcar4_mfismh\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\product\rcar4\module\rcar4_reset\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\interface\amu -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\amu_mmap\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\atu\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\apcontext\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\armv7m_mpu\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\armv8m_mpu\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\armv8r_mpu\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\bootloader\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\ccsm\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\cmn600\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\cmn_cyprus\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\interface\cmn -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\cmn_skeena\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\css_clock\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\ddr_phy500\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\debug\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\debugger_cli\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\timer\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\dmc500\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\dmc620\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\dvfs\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\dw_apb_i2c\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\atu_mmio\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\interface\address_remapper -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\gicx00\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\gtimer\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\i2c\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\metrics_analyzer\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\interface\power_management -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\mhu\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\mhu2\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\mhu3\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\mock_clock\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\mock_ppu\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\mock_psu\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\mock_voltage_domain\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\mpmm\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\mpmm\..\amu\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\msg_smt\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\msys_rom\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\noc_s3\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\pcid\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\perf_controller\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\pid_controller\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\pik_clock\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\pl011\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\power_capping\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\ppu_v0\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\ppu_v1\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\psu\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\reg_sensor\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\reset_domain\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\resource_perms\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\scmi\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\scmi_apcore\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\scmi_clock\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\scmi_perf\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\scmi_pin_control\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\scmi_power_capping\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\scmi_power_domain\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\scmi_power_domain_req\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\scmi_reset_domain\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\scmi_sensor\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\scmi_sensor_req\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\scmi_system_power\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\scmi_system_power_req\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\scmi_voltage_domain\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\sc_pll\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\sds\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\sensor\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\sensor_smcf_drv\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\sid\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\smcf\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\amu_smcf_drv\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\sp805\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\ssc\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\statistics\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\stdio\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\system_info\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\system_pll\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\system_power\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\thermal_mgmt\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\traffic_cop\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\transport\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\voltage_domain\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\xr77128\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\fch_polled\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\fch_polled\src

ASM_FLAGS = -ffunction-sections -fdata-sections -fshort-enums -Wall -Werror -Wextra -Wno-error=deprecated-declarations -Wno-unused-parameter -Wno-missing-field-initializers -Og -g

C_DEFINES = -DBUILD_HAS_MOD_CLOCK=1 -DBUILD_HAS_MOD_POWER_DOMAIN=1 -DBUILD_HAS_MOD_RCAR4_CLOCK=1 -DBUILD_HAS_MOD_RCAR4_MFISMH=1 -DBUILD_HAS_MOD_RCAR4_PD_CORE=1 -DBUILD_HAS_MOD_RCAR4_PD_SYSC=1 -DBUILD_HAS_MOD_RCAR4_RESET=1 -DBUILD_HAS_MOD_RCAR4_SYSTEM=1 -DBUILD_HAS_MOD_RCAR4_SYSTEM_POWER=1 -DBUILD_HAS_MOD_RESET_DOMAIN=1 -DBUILD_HAS_MOD_SCMI=1 -DBUILD_HAS_MOD_SCMI_RESET_DOMAIN=1 -DBUILD_HAS_MOD_SDS=1 -DBUILD_HAS_MOD_TRANSPORT=1 -DBUILD_HAS_NOTIFICATION -DBUILD_HAS_OUTBAND_MSG_SUPPORT -DBUILD_HAS_SCMI_POWER_CAPPING_STD_COMMANDS -DBUILD_MODE_DEBUG -DBUILD_VERSION_DESCRIBE_STRING=\"v2.15.0-219-gde8d2833-dirty\" -DBUILD_VERSION_MAJOR=2 -DBUILD_VERSION_MINOR=15 -DBUILD_VERSION_PATCH=0 -DFWK_LOG_LEVEL=FWK_LOG_LEVEL_WARN

C_INCLUDES = -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\product\rcar4\scp_ramfw\..\src\CMSIS-FreeRTOS\Source\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\product\rcar4\scp_ramfw\..\src\CMSIS-FreeRTOS\Source\portable\GCC\ARM_CA53_64_Rcar -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\product\rcar4\scp_ramfw\..\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\product\rcar4\scp_ramfw -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\contrib\cmsis\git\CMSIS\RTOS2\Include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\contrib\cmsis\git\CMSIS\Core\Include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\arch\arm\armv8-r\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\arch\arm\armv8-r\include\lib -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\product\rcar4\module\rcar4_pd_sysc\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\power_domain\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\framework\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\DEBUGbuild\framework\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\product\rcar4\module\rcar4_clock\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\clock\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\product\rcar4\module\rcar4_pd_core\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\product\rcar4\module\rcar4_system\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\product\rcar4\module\rcar4_system_power\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\product\rcar4\module\rcar4_mfismh\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\product\rcar4\module\rcar4_reset\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\interface\amu -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\amu_mmap\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\atu\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\apcontext\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\armv7m_mpu\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\armv8m_mpu\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\armv8r_mpu\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\bootloader\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\ccsm\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\cmn600\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\cmn_cyprus\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\interface\cmn -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\cmn_skeena\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\css_clock\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\ddr_phy500\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\debug\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\debugger_cli\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\timer\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\dmc500\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\dmc620\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\dvfs\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\dw_apb_i2c\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\atu_mmio\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\interface\address_remapper -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\gicx00\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\gtimer\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\i2c\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\metrics_analyzer\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\interface\power_management -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\mhu\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\mhu2\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\mhu3\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\mock_clock\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\mock_ppu\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\mock_psu\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\mock_voltage_domain\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\mpmm\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\mpmm\..\amu\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\msg_smt\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\msys_rom\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\noc_s3\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\pcid\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\perf_controller\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\pid_controller\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\pik_clock\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\pl011\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\power_capping\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\ppu_v0\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\ppu_v1\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\psu\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\reg_sensor\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\reset_domain\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\resource_perms\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\scmi\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\scmi_apcore\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\scmi_clock\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\scmi_perf\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\scmi_pin_control\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\scmi_power_capping\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\scmi_power_domain\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\scmi_power_domain_req\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\scmi_reset_domain\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\scmi_sensor\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\scmi_sensor_req\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\scmi_system_power\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\scmi_system_power_req\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\scmi_voltage_domain\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\sc_pll\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\sds\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\sensor\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\sensor_smcf_drv\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\sid\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\smcf\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\amu_smcf_drv\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\sp805\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\ssc\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\statistics\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\stdio\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\system_info\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\system_pll\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\system_power\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\thermal_mgmt\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\traffic_cop\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\transport\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\voltage_domain\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\xr77128\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\fch_polled\include -IC:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\module\fch_polled\src

C_FLAGS = -ffunction-sections -fdata-sections -fshort-enums -Wall -Werror -Wextra -Wno-error=deprecated-declarations -Wno-unused-parameter -Wno-missing-field-initializers -Wno-error=unused-but-set-variable -Wno-error=unused-variable -Og -g -std=gnu11

