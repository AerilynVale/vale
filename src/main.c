// SPDX-License-Identifier: GPL-3.0-or-later

/*
    Vale only supports the x86_64 architecture.

    Compiling to a different architecture will result
    in unattended side effects, or completely unable to boot.
*/
#if defined(__x86_64__)
    #include "arch/x86_64/gdt.h"
#else
    #error "Unsupported architecture. Compile for x86_64."
#endif
#include "drivers/fb.h"

void _start(void) {
    __asm__ volatile("cli"); // disable interrupts; no idt yet

    init_gdt();
    init_fb();

    clear(0x000000);

    printf("Welcome to Vale!\n\n", 0xFFFFFF);
    // colour testing cause i want more "activity" on the screen, this is completely useless and colours do work
    printf("Red\n", 0xFF0000);
    printf("Green\n", 0x00FF00);
    printf("Blue\n", 0x0000FF);
    printf("Yellow\n", 0xFFFF00);
    printf("Cyan\n", 0x00FFFF);
    printf("Magenta\n", 0xFF00FF);

    for (;;) __asm__("hlt");
}