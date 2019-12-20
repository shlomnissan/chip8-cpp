//
// Created by Shlomi Nissan on 12/17/19.
//

#ifndef CHIP8_CHIP8_H
#define CHIP8_CHIP8_H

#include <array>
#include <unordered_map>
#include <functional>

#include "display.h"

class Chip8 {
public:
    Chip8();

    void SaveRom(const void* source, size_t size);
    void Reset();
    void Cycle();
private:
    using operations_set = std::unordered_map<uint8_t, std::function<void(void)>>;

    std::array<uint8_t, 0x1000> memory;
    std::array<uint8_t, 0x10> V;
    std::array<uint16_t, 0x10> stack;

    std::unordered_map<uint8_t, operations_set> operations;
    Display display;

    uint8_t t_delay;
    uint8_t t_sound;
    uint16_t I;
    uint16_t pc;
    uint16_t sp;
    uint16_t opcode;

    const std::array<uint8_t , 0x10> kKeyMap {
        0x78, // X
        0x31, // 1
        0x32, // 2
        0x33, // 3
        0x71, // Q
        0x77, // W
        0x65, // E
        0x61, // A
        0x73, // S
        0x64, // D
        0x7a, // Z
        0x63, // C
        0x34, // 4
        0x72, // R
        0x66, // F
        0x76, // V
    };

    // CLS
    void OP_00E0();

    // RET
    void OP_00EE();

    // JP address
    void OP_1nnn();

    // CALL address
    void OP_2nnn();

    // SE Vx, byte
    void OP_3xkk();

    // SNE Vx, byte
    void OP_4xkk();

    // SE Vx, Vy
    void OP_5xy0();

    // LD Vx, byte
    void OP_6xkk();

    // ADD Vx, byte
    void OP_7xkk();
};


#endif //CHIP8_CHIP8_H
