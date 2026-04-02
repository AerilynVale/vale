PHDRS
{
    text PT_LOAD FLAGS(5);
    rodata PT_LOAD FLAGS(4);
    data PT_LOAD FLAGS(6);
}

SECTIONS
{
    . = 0xffffffff80000000;

    .text : {
        *(.text*)
    } :text

    . = ALIGN(0x1000);

    .rodata : {
        *(.rodata*)
    } :rodata

    .limine_requests : {
        KEEP(*(.limine_requests))
    } :rodata

    . = ALIGN(0x1000);

    .data : {
        *(.data*)
    } :data

    .bss : {
        *(COMMON)
        *(.bss*)
    } :data
}