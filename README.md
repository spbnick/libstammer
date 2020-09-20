libstammer
==========

Libstammer is a basic firmware C library for STM32 microcontrollers. It is
inteded primarily for the education of the author and possibly whoever else is
interested in learning firmware development for STM32.

Building
--------
You'll need the gcc compiler. If you're using a Debian-based Linux you can get
it by installing `gcc-arm-none-eabi` package. The Makefile expects the
compiler prefix to be `arm-none-eabi-`, as provided by e.g. the Debian package
above. You can change the prefix by specifying the `CCPFX` variable.

Provided you have your compiler setup, run `make` in the directory matching
your target to build the library.

Usage
-----
To use libstammer in your own program, build the library first, then make sure
to pass an `-I` option to your compiler, as well as an `-L` option to your
linker, both pointing to the libstammer's directory where you ran `make`.
Also, specify `-Tlibstammer.ld` and `-lstammer` options to your linker to have
your program link with libstammer linker script and library. See
[stm32-poke][stm32-poke] for usage examples.

[stm32-poke]: https://github.com/spbnick/stm32-poke
