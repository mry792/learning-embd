# learning-embd
Repository for learning and experimentation projects for embedded C++.


Create a toolchain file "avr-gcc.toolchain.cmake" like the following:
```cmake
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR avr)

set(avr_gcc_dir <path/to/avr-gcc/install>)
set(CMAKE_C_COMPILER ${avr_gcc_dir}/bin/avr-gcc)
set(CMAKE_CXX_COMPILER ${avr_gcc_dir}/bin/avr-g++)
set(CMAKE_ASM_COMPILER ${avr_gcc_dir}/bin/avr-as)

set(avr_libc_dir <path/to/avr-libc/install>)

set(CMAKE_ASM_FLAGS "-mmcu=atmega328p" CACHE STRING "Flags passed to the assembler compiler")
set(CMAKE_CXX_FLAGS "-mmcu=atmega328p -O2 -isystem ${avr_libc_dir}/avr/include" CACHE STRING "Flags passed to the C++ compmiler")

# https://stackoverflow.com/a/53635241
set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

```

Initialize cmake:
```shell
cmake ../source -DCMAKE_TOOLCHAIN_FILE=../avr-gcc.toolchain.cmake
```

Build:
```shell
make
```
