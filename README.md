# Vale

Vale is a 64-bit operating system available for the x86_64 architecture. 
At it's current state, Vale is extremely limited and has not yet been tested on real hardware.

I plan to make Vale Unix-like and POSIX-complaint.

## License

    Copyright (C) 2026  Aerilyn Vale and contributers.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

## Build

Required build tools:

* Any GNU/Linux system.
* Python 3.14 `python3`
* GNU C Compiler `gcc`
* GNU Linker `ld`
* Xorriso `xorriso`
* Limine 11 `limine`
* QEMU `qemu-system-x86_64` if you want to emulate Vale.

In the project route, simply run `make`; an ISO file will be generated in ./build.
Alternatively, type `make run` to emulate Vale using QEMU.
