// SPDX-License-Identifier: GPL-3.0-or-later

#include "drivers/fb.h"

void _start(void) {
    init_fb();
    clear(0x000000);

    printf("Welcome to Vale!\n\n", 0xFFFFFF);
    printf("Red\n", 0xFF0000);
    printf("Green\n", 0x00FF00);
    printf("Blue\n", 0x0000FF);
    printf("Yellow\n", 0xFFFF00);
    printf("Cyan\n", 0x00FFFF);
    printf("Magenta\n", 0xFF00FF);

    for (;;) __asm__("hlt");
}