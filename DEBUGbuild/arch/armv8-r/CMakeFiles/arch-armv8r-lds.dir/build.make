# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Renesas\rcar-xos\v3.31.0\tools\cmake-3.21.0-windows-x86_64\bin\cmake.exe

# The command to remove a file.
RM = C:\Renesas\rcar-xos\v3.31.0\tools\cmake-3.21.0-windows-x86_64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\DEBUGbuild

# Utility rule file for arch-armv8r-lds.

# Include any custom commands dependencies for this target.
include arch/armv8-r/CMakeFiles/arch-armv8r-lds.dir/compiler_depend.make

# Include the progress variables for this target.
include arch/armv8-r/CMakeFiles/arch-armv8r-lds.dir/progress.make

arch/armv8-r/CMakeFiles/arch-armv8r-lds: arch/armv8-r/arch-armv8r.ld

arch/armv8-r/arch-armv8r.ld: ../arch/arm/armv8-r/src/arch.ld.S
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\DEBUGbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating arch-armv8r.ld"
	cd /d C:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\DEBUGbuild\arch\armv8-r && "C:\Program Files (x86)\Arm GNU Toolchain arm-none-eabi\13.3 rel1\bin\arm-none-eabi-gcc.exe" -DBUILD_HAS_NOTIFICATION -DBUILD_MODE_DEBUG -DBUILD_HAS_OUTBAND_MSG_SUPPORT -DBUILD_HAS_SCMI_POWER_CAPPING_STD_COMMANDS -DFWK_LOG_LEVEL=FWK_LOG_LEVEL_WARN -DBUILD_HAS_MOD_RCAR4_SYSTEM=1 -DBUILD_HAS_MOD_RCAR4_SYSTEM_POWER=1 -DBUILD_HAS_MOD_POWER_DOMAIN=1 -DBUILD_HAS_MOD_RCAR4_PD_SYSC=1 -DBUILD_HAS_MOD_RCAR4_PD_CORE=1 -DBUILD_HAS_MOD_TRANSPORT=1 -DBUILD_HAS_MOD_SCMI=1 -DBUILD_HAS_MOD_CLOCK=1 -DBUILD_HAS_MOD_RCAR4_CLOCK=1 -DBUILD_HAS_MOD_RCAR4_MFISMH=1 -DBUILD_HAS_MOD_SDS=1 -DBUILD_HAS_MOD_RESET_DOMAIN=1 -DBUILD_HAS_MOD_RCAR4_RESET=1 -DBUILD_HAS_MOD_SCMI_RESET_DOMAIN=1 -DBUILD_VERSION_DESCRIBE_STRING=\"v2.15.0-219-gde8d2833-dirty\" -DBUILD_VERSION_MAJOR=2 -DBUILD_VERSION_MINOR=15 -DBUILD_VERSION_PATCH=0 -IC:/Users/a5137749/Documents/Abteilungen/shared/scp-rcar4/SCP-firmware/arch/arm/armv8-r/include -IC:/Users/a5137749/Documents/Abteilungen/shared/scp-rcar4/SCP-firmware/arch/arm/armv8-r/include/lib -IC:/Users/a5137749/Documents/Abteilungen/shared/scp-rcar4/SCP-firmware/product/rcar4/scp_ramfw/../src/CMSIS-FreeRTOS/Source/include -IC:/Users/a5137749/Documents/Abteilungen/shared/scp-rcar4/SCP-firmware/product/rcar4/scp_ramfw/../src/CMSIS-FreeRTOS/Source/portable/GCC/ARM_CA53_64_Rcar -IC:/Users/a5137749/Documents/Abteilungen/shared/scp-rcar4/SCP-firmware/product/rcar4/scp_ramfw/../include -IC:/Users/a5137749/Documents/Abteilungen/shared/scp-rcar4/SCP-firmware/product/rcar4/scp_ramfw -IC:/Users/a5137749/Documents/Abteilungen/shared/scp-rcar4/SCP-firmware/contrib/cmsis/git/CMSIS/RTOS2/Include -IC:/Users/a5137749/Documents/Abteilungen/shared/scp-rcar4/SCP-firmware/contrib/cmsis/git/CMSIS/Core/Include -IC:/Users/a5137749/Documents/Abteilungen/shared/scp-rcar4/SCP-firmware/framework/include -IC:/Users/a5137749/Documents/Abteilungen/shared/scp-rcar4/SCP-firmware/DEBUGbuild/framework/include -IC:/Users/a5137749/Documents/Abteilungen/shared/scp-rcar4/SCP-firmware/arch/arm/armv8-r/include -IC:/Users/a5137749/Documents/Abteilungen/shared/scp-rcar4/SCP-firmware/arch/arm/armv8-r/include/lib -ffunction-sections -fdata-sections -fshort-enums -Wall -Werror -Wextra -Wno-error=deprecated-declarations -Wno-unused-parameter -Wno-missing-field-initializers -Wno-error=unused-but-set-variable -Wno-error=unused-variable -Og -g -P -E C:/Users/a5137749/Documents/Abteilungen/shared/scp-rcar4/SCP-firmware/arch/arm/armv8-r/src/arch.ld.S > C:/Users/a5137749/Documents/Abteilungen/shared/scp-rcar4/SCP-firmware/DEBUGbuild/arch/armv8-r/arch-armv8r.ld

arch-armv8r-lds: arch/armv8-r/CMakeFiles/arch-armv8r-lds
arch-armv8r-lds: arch/armv8-r/arch-armv8r.ld
arch-armv8r-lds: arch/armv8-r/CMakeFiles/arch-armv8r-lds.dir/build.make
.PHONY : arch-armv8r-lds

# Rule to build all files generated by this target.
arch/armv8-r/CMakeFiles/arch-armv8r-lds.dir/build: arch-armv8r-lds
.PHONY : arch/armv8-r/CMakeFiles/arch-armv8r-lds.dir/build

arch/armv8-r/CMakeFiles/arch-armv8r-lds.dir/clean:
	cd /d C:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\DEBUGbuild\arch\armv8-r && $(CMAKE_COMMAND) -P CMakeFiles\arch-armv8r-lds.dir\cmake_clean.cmake
.PHONY : arch/armv8-r/CMakeFiles/arch-armv8r-lds.dir/clean

arch/armv8-r/CMakeFiles/arch-armv8r-lds.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware C:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\arch\arm\armv8-r C:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\DEBUGbuild C:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\DEBUGbuild\arch\armv8-r C:\Users\a5137749\Documents\Abteilungen\shared\scp-rcar4\SCP-firmware\DEBUGbuild\arch\armv8-r\CMakeFiles\arch-armv8r-lds.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : arch/armv8-r/CMakeFiles/arch-armv8r-lds.dir/depend

