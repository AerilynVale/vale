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

#include "drivers/memory/pmm.h"
#include "drivers/memory/vmm.h"
#include "drivers/fb.h"

void _start(void) {
    __asm__ volatile("cli"); // disable interrupts; no idt yet

    init_gdt();

    init_fb(); // initialize framebuffer early for early logging
    clear(0x000000);

    init_pmm();
    init_vmm();

    printf("\n", 0x000000);

    printf("Welcome to Vale!\n", 0xFFFFFF);
    printf("0.1.0-alpha.1\n", 0xFFFFFF);
    printf("Copyright (c) 2026 Aerilyn Vale and contributers, ", 0xCC00DD);
    printf("GNU General Public License v3.0-or-later.\n", 0xFF2200);

    for (;;) __asm__("hlt");
}