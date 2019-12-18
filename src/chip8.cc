//
// Created by Shlomi Nissan on 12/17/19.
//

#include "chip8.h"
#include <iostream>

const std::array<uint8_t, 0x50> kSprites {
    0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
    0x20, 0x60, 0x20, 0x20, 0x70, // 1
    0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
    0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
    0x90, 0x90, 0xF0, 0x10, 0x10, // 4
    0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
    0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
    0xF0, 0x10, 0x20, 0x40, 0x40, // 7
    0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
    0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
    0xF0, 0x90, 0xF0, 0x90, 0x90, // A
    0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
    0xF0, 0x80, 0x80, 0x80, 0xF0, // C
    0xE0, 0x90, 0x90, 0x90, 0xE0, // D
    0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
    0xF0, 0x80, 0xF0, 0x80, 0x80  // F
};

constexpr int kStartAddress = 0x200;

Chip8::Chip8(): memory({0}),
                V({0}),
                display({0}),
                stack({0}),
                t_delay(0),
                t_sound(0),
                I(0),
                pc(kStartAddress),
                sp(0),
                opcode(0) {

    // Store sprites data at the beginning of the memory
    std::memcpy(memory.data(), kSprites.data(), kSprites.size());

    operations[0x6] = std::bind(&Chip8::OP_6xkk, this);
}

void Chip8::SaveRom(const void *source, size_t size) {
    // 0x200 (512) Start of most Chip-8 programs
    std::memcpy(memory.data() + kStartAddress, source, size);
}

void Chip8::Reset() {
    // Clear out rom data from memory
    std::memset(memory.data() + kStartAddress, 0, memory.size() - kStartAddress);
    V = {0};
    display = {0};
    stack = {0};
    I = 0;
    pc = 0x200;
    sp = 0;
    t_delay = 0;
    t_sound = 0;
}

void Chip8::Cycle() {
    // Fetch opcode
    opcode = memory[pc] << 8 | memory[pc + 1];

    // Decrement the delay timer if it's been set
    if (t_delay > 0) {
        --t_delay;
    }

    // Decrement the sound timer if it's been set
    if (t_sound > 0) {
        --t_sound;
    }
}

void Chip8::OP_6xkk() {
    std::cout << "Execute OP_6xkk\n";
}

