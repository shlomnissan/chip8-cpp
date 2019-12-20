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

constexpr int kOp1 = 0x1; // Default operations set
constexpr int kOp0 = 0x0;
constexpr int kOp8 = 0x8;
constexpr int kOpE = 0xE;
constexpr int kOpF = 0xF;

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

    BindOperations();
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
            case kOp0:
                operations[kOp0][(opcode & 0x000F)]();
                break;
            case kOp8:
                operations[kOp8][(opcode & 0x000F)]();
                break;
            case kOpE:
                operations[kOpE][(opcode & 0x000F)]();
                break;
            case kOpF:
                operations[kOpF][(opcode & 0x00FF)]();
                break;
            default: {
                operations[kOp1][((opcode & 0xF000) >> 12)]();
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

void Chip8::BindOperations() {
    using std::bind;

    operations[kOp0][0x00] = bind(&Chip8::OP_00E0, this);
    operations[kOp0][0x0E] = bind(&Chip8::OP_00EE, this);
    operations[kOp1][0x01] = bind(&Chip8::OP_1nnn, this);
    operations[kOp1][0x02] = bind(&Chip8::OP_2nnn, this);
    operations[kOp1][0x03] = bind(&Chip8::OP_3xkk, this);
    operations[kOp1][0x04] = bind(&Chip8::OP_4xkk, this);
    operations[kOp1][0x05] = bind(&Chip8::OP_5xy0, this);
    operations[kOp1][0x06] = bind(&Chip8::OP_6xkk, this);
    operations[kOp1][0x07] = bind(&Chip8::OP_7xkk, this);
    operations[kOp1][0x09] = bind(&Chip8::OP_9xy0, this);
    operations[kOp1][0x0A] = bind(&Chip8::OP_Annn, this);
    operations[kOp1][0x0B] = bind(&Chip8::OP_Bnnn, this);
    operations[kOp1][0x0C] = bind(&Chip8::OP_Cxkk, this);
    operations[kOp1][0x0D] = bind(&Chip8::OP_Dxyn, this);
    operations[kOp8][0x00] = bind(&Chip8::OP_8xy0, this);
    operations[kOp8][0x01] = bind(&Chip8::OP_8xy1, this);
    operations[kOp8][0x02] = bind(&Chip8::OP_8xy2, this);
    operations[kOp8][0x03] = bind(&Chip8::OP_8xy3, this);
    operations[kOp8][0x04] = bind(&Chip8::OP_8xy4, this);
    operations[kOp8][0x05] = bind(&Chip8::OP_8xy5, this);
    operations[kOp8][0x06] = bind(&Chip8::OP_8xy6, this);
    operations[kOp8][0x07] = bind(&Chip8::OP_8xy7, this);
    operations[kOp8][0x0E] = bind(&Chip8::OP_8xyE, this);
    operations[kOpE][0x01] = bind(&Chip8::OP_ExA1, this);
    operations[kOpE][0x0E] = bind(&Chip8::OP_Ex9E, this);
    operations[kOpF][0x07] = bind(&Chip8::OP_Fx07, this);
    operations[kOpF][0x0A] = bind(&Chip8::OP_Fx0A, this);
    operations[kOpF][0x15] = bind(&Chip8::OP_Fx15, this);
    operations[kOpF][0x18] = bind(&Chip8::OP_Fx18, this);
    operations[kOpF][0x1E] = bind(&Chip8::OP_Fx1E, this);
    operations[kOpF][0x29] = bind(&Chip8::OP_Fx29, this);
    operations[kOpF][0x33] = bind(&Chip8::OP_Fx33, this);
    operations[kOpF][0x55] = bind(&Chip8::OP_Fx55, this);
    operations[kOpF][0x65] = bind(&Chip8::OP_Fx65, this);
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

void Chip8::OP_8xy0() {

}

void Chip8::OP_8xy1() {

}

void Chip8::OP_8xy2() {

}

void Chip8::OP_8xy3() {

}

void Chip8::OP_8xy4() {

}

void Chip8::OP_8xy5() {

}

void Chip8::OP_8xy6() {

}

void Chip8::OP_8xy7() {

}

void Chip8::OP_8xyE() {

}

void Chip8::OP_9xy0() {

}

void Chip8::OP_Annn() {

}

void Chip8::OP_Bnnn() {

}

void Chip8::OP_Cxkk() {

}

void Chip8::OP_Dxyn() {

}

void Chip8::OP_Ex9E() {

}

void Chip8::OP_ExA1() {

}

void Chip8::OP_Fx07() {

}

void Chip8::OP_Fx0A() {

}

void Chip8::OP_Fx15() {

}

void Chip8::OP_Fx18() {

}

void Chip8::OP_Fx1E() {

}

void Chip8::OP_Fx29() {

}

void Chip8::OP_Fx33() {

}

void Chip8::OP_Fx55() {

}

void Chip8::OP_Fx65() {

}
