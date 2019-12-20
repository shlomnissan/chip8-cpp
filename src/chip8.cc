//
// Created by Shlomi Nissan on 12/17/19.
//

#include "chip8.h"
#include <iostream>
#include <cstring>

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

constexpr int kOperationsDefault = 0x1;
constexpr int kOperations0 = 0x0;
constexpr int kOperations8 = 0x8;
constexpr int kOperationsE = 0xE;
constexpr int kOperationsF = 0xF;

Chip8::Chip8(): memory({0}),
                V({0}),
                stack({0}),
                operations(),
                display(Display::Instance()),
                t_delay(0),
                t_sound(0),
                I(0),
                pc(kStartAddress),
                sp(0),
                opcode(0) {

    // Store sprites data at the beginning of the memory
    std::memcpy(memory.data(), kSprites.data(), kSprites.size());

    operations[kOperations0][0x0] = std::bind(&Chip8::OP_00E0, this);
    operations[kOperations0][0xE] = std::bind(&Chip8::OP_00EE, this);

    operations[kOperationsDefault][0x1] = std::bind(&Chip8::OP_1nnn, this);
    operations[kOperationsDefault][0x2] = std::bind(&Chip8::OP_2nnn, this);
    operations[kOperationsDefault][0x3] = std::bind(&Chip8::OP_3xkk, this);
    operations[kOperationsDefault][0x4] = std::bind(&Chip8::OP_4xkk, this);
    operations[kOperationsDefault][0x5] = std::bind(&Chip8::OP_5xy0, this);
    operations[kOperationsDefault][0x6] = std::bind(&Chip8::OP_6xkk, this);
    operations[kOperationsDefault][0x7] = std::bind(&Chip8::OP_7xkk, this);
}

void Chip8::SaveRom(const void *source, size_t size) {
    // 0x200 (512) Start of most Chip-8 programs
    std::memcpy(memory.data() + kStartAddress, source, size);
}

void Chip8::Reset() {
    // Clear out rom data from memory
    std::memset(memory.data() + kStartAddress, 0, memory.size() - kStartAddress);
    V = {0};
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

    // Increment PC before execution
    pc += 2;

    try {
        switch((opcode & 0xF000) >> 12) {
            case kOperations0:
                operations[kOperations0][(opcode & 0x000F)]();
                break;
            case kOperations8:
                //operations[kOperations8][(opcode & 0x000F)]();
                break;
            case kOperationsE:
                //operations[kOperationsE][(opcode & 0x000F)]();
                break;
            case kOperationsF:
                //operations[kOperationsF][(opcode & 0x00FF)]();
                break;
            default: {
                operations[kOperationsDefault][((opcode & 0xF000) >> 12)]();
            }
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n'
                  << "Failed to execute opcode: "
                  << std::hex << opcode << '\n';
    }

    // Decrement the delay timer if it's been set
    if (t_delay > 0) {
        --t_delay;
    }

    // Decrement the sound timer if it's been set
    if (t_sound > 0) {
        --t_sound;
    }
}

void Chip8::OP_00E0() {
    display.ClearScreen();
}

void Chip8::OP_00EE() {

}

void Chip8::OP_1nnn() {

}

void Chip8::OP_2nnn() {

}

void Chip8::OP_3xkk() {

}

void Chip8::OP_4xkk() {

}

void Chip8::OP_5xy0() {

}

void Chip8::OP_6xkk() {

}

void Chip8::OP_7xkk() {

}
