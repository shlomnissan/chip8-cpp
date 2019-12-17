cmake_minimum_required(VERSION 3.15)
project(chip8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIR})

add_executable(chip8 main.cpp emulator.cc emulator.h window.cc window.h chip8.cc chip8.h)

target_link_libraries(chip8 ${SDL2_LIBRARY})