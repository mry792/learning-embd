cmake_minimum_required(VERSION 3.10)
project(learning-embd LANGUAGES CXX ASM)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(led_program
    crt0.s
    led_program.cpp
)

set_target_properties(led_program
    PROPERTIES
        LINK_FLAGS "-nostartfiles -nostdlib -Wl,-T${CMAKE_CURRENT_SOURCE_DIR}/avr.ld,-Map,${CMAKE_CURRENT_BINARY_DIR}/led.map"
)
target_include_directories(led_program
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}"
)
