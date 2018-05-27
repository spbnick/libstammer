libstammer
==========

Libstammer is a basic firmware C library for an [STM32F103 development
board][board]. It is inteded primarily for the education of the author and
possibly whoever else is interested in learning firmware development for STM32
microcontrollers.

Building
--------
You'll need the gcc compiler. If you're using a Debian-based Linux you can get
it by installing `gcc-arm-none-eabi` package. The Makefile expects the
compiler prefix to be `arm-none-eabi-`, as provided by e.g. the Debian package
above. So if you have that, just running `make` will build the library.
Otherwise, you can specify another prefix with the `CCPFX` variable.

Usage
-----
To use libstammer in your own program, build the library first, then make sure
to pass an `-I` option to your compiler, as well as an `-L` option to your
linker, both pointing to the libstammer directory. Also, specify
`-Tlibstammer.ld` and `-lstammer` options to your linker to have your program
link with libstammer linker script and library.

[board]: http://item.taobao.com/item.htm?spm=a1z10.1-c.w4004-9679183684.4.26lLDG&id=22097803050
