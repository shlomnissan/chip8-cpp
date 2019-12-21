cmake_minimum_required(VERSION 3.15)
project(chip8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIR})

add_executable(chip8 src/main.cpp src/emulator.cc src/emulator.h src/window.cc src/window.h src/chip8.cc src/chip8.h src/display.h src/interpreter.cc src/interpreter.h)

target_link_libraries(chip8 ${SDL2_LIBRARY})