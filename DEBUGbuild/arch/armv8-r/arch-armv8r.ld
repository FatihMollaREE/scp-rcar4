    ASSERT((2 * 1024) < (384 * 1024),
        "FMW_STACK_SIZE does not fit in MEM0")
ASSERT((( ((( (((0xE2100000 + (384 * 1024) - (2 * 1024)) + 8 - 1) / 8) * 8 ) + (2 * 1024)) / 8) * 8 ) - ( (((0xE2100000 + (384 * 1024) - (2 * 1024)) + 8 - 1) / 8) * 8 )) > 0, "FMW_STACK_SIZE is too small")
OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(Vector)
MEMORY {
    mem0 (rxw): ORIGIN = 0xE2100000, LENGTH = (384 * 1024) - (2 * 1024)
    stack (rw): ORIGIN = ( (((0xE2100000 + (384 * 1024) - (2 * 1024)) + 8 - 1) / 8) * 8 ), LENGTH = (( ((( (((0xE2100000 + (384 * 1024) - (2 * 1024)) + 8 - 1) / 8) * 8 ) + (2 * 1024)) / 8) * 8 ) - ( (((0xE2100000 + (384 * 1024) - (2 * 1024)) + 8 - 1) / 8) * 8 ))
    sram (rxw): ORIGIN = ((0xE6302000)), LENGTH = (0x00001000)
}
SECTIONS
{
    . = 0xE2100000;
    ASSERT(. == ALIGN(4096),
           "CR7 dummy rtos address is not aligned on a page boundary.")
    ro . : {
        __RO_START__ = .;
        *rtos.o(.text*)
        *rtos_main.o(.text*)
        . = NEXT(32768);
        *(.text*)
        *(.rodata*)
        __RO_END_UNALIGNED__ = .;
        . = NEXT(4096);
        . = NEXT(16384);
        __RO_END__ = .;
    } >mem0
    .data . : {
        __DATA_START__ = .;
        *(.data*)
        __DATA_END__ = .;
    } >mem0
    stacks (NOLOAD) : ALIGN(16) {
        __STACKS_START__ = .;
        KEEP(*(tzfw_normal_stacks))
        __STACKS_END__ = .;
    } >mem0
    .init_array : {
        __init_array_start = .;
        KEEP(*(.init_array*))
        __init_array_end = .;
    } >mem0
    .bss : ALIGN(16) {
        __BSS_START__ = .;
        *(SORT_BY_ALIGNMENT(.bss*))
        *(COMMON)
        __BSS_END__ = .;
    } >mem0
    .stack (NOLOAD) : {
        . = . + (( ((( (((0xE2100000 + (384 * 1024) - (2 * 1024)) + 8 - 1) / 8) * 8 ) + (2 * 1024)) / 8) * 8 ) - ( (((0xE2100000 + (384 * 1024) - (2 * 1024)) + 8 - 1) / 8) * 8 ));
    } > stack
    __STACK_START__ = LOADADDR(.stack);
    __STACK_SIZE__ = SIZEOF(.stack);
    __STACK_END__ = __STACK_START__ + __STACK_SIZE__;
    __STACK_TOP__ = __STACK_END__;
    __BSS_START__ = ADDR(.bss);
    __BSS_SIZE__ = SIZEOF(.bss);
    __BSS_END__ = __BSS_START__ + __BSS_SIZE__;
    __HEAP_START__ = __BSS_START__ + __BSS_SIZE__;
    __HEAP_END__ = __STACK_START__;
    __HEAP_SIZE__ = __HEAP_END__ - __HEAP_START__;
    ASSERT(. <= 0xE24FE800, "CR7 dummy rtos has exceeded its limit.")
}
