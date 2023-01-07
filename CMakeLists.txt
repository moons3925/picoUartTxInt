# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)
set(PICO_SDK_PATH "C:/Users/m3925/Documents/Pico/pico-sdk")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(picoUartTxInt C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(picoUartTxInt picoUartTxInt.c uart_ex.c)

add_compile_options(-std=c11 -O0 -g -Wall)
add_compile_options(-std=c++17 -O0 -g -Wall)

pico_set_program_name(picoUartTxInt "picoUartTxInt")
pico_set_program_version(picoUartTxInt "0.1")

pico_enable_stdio_uart(picoUartTxInt 0)
pico_enable_stdio_usb(picoUartTxInt 0)

# Add the standard library to the build
target_link_libraries(picoUartTxInt pico_stdlib)

pico_add_extra_outputs(picoUartTxInt)

