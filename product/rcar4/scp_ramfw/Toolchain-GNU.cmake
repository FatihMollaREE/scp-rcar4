#
# LICENSE
#

include_guard()

set(CMAKE_SYSTEM_PROCESSOR "arm")  # worauf kompiliere ich  Wo gebe ich überhaupt das verzeichniss an für compiler??? C:\Program Files (x86)\Arm GNU Toolchain arm-none-eabi\13.3 rel1\bin

set(CMAKE_TOOLCHAIN_PREFIX "arm-none-eabi-")

set(CMAKE_ASM_COMPILER_TARGET "/c/Program\ Files\ \(x86\)/Arm\ GNU\ Toolchain\ arm-none-eabi/13.3\ rel1/bin/")
set(CMAKE_C_COMPILER_TARGET "/c/Program\ Files\ \(x86\)/Arm\ GNU\ Toolchain\ arm-none-eabi/13.3\ rel1/bin/")
set(CMAKE_CXX_COMPILER_TARGET "/c/Program\ Files\ \(x86\)/Arm\ GNU\ Toolchain\ arm-none-eabi/13.3\ rel1/bin/")

include(
    "${CMAKE_CURRENT_LIST_DIR}/../../../cmake/Toolchain/GNU-Baremetal.cmake") # hier muss ich glaub noch meinen compiler hinzufuegen