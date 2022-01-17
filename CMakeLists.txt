cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(learning-embd LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create ELF file.
add_executable(led.elf)
target_compile_options(led.elf
    PRIVATE
        -Werror
        -Wall
        -Wextra
)

find_package(arche REQUIRED)
target_link_libraries(led.elf arche::arche)

add_subdirectory(src)

# Generate hex file.
add_custom_command(
    OUTPUT led.hex
    COMMAND ${CMAKE_OBJCOPY} -O ihex $<TARGET_FILE:led.elf> led.hex
    DEPENDS led.elf
    COMMENT "Extracting HEX-file from led.elf ..."
    VERBATIM
)
add_custom_target(
    hex-file
    DEPENDS led.hex
)
