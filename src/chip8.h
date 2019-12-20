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

    void BindOperations();

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

    // LD Vx, Vy
    void OP_8xy0();

    // OR Vx, Vy
    void OP_8xy1();

    // AND Vx, Vy
    void OP_8xy2();

    // XOR Vx, Vy
    void OP_8xy3();

    // ADD Vx, Vy
    void OP_8xy4();

    // SUB Vx, Vy
    void OP_8xy5();

    // SHR Vx
    void OP_8xy6();

    // SUBN Vx, Vy
    void OP_8xy7();

    // SHL Vx
    void OP_8xyE();

    // SNE Vx, Vy
    void OP_9xy0();

    // LD I, address
    void OP_Annn();

    // JP V0, address
    void OP_Bnnn();

    // RND Vx, byte
    void OP_Cxkk();

    // DRW Vx, Vy, height
    void OP_Dxyn();

    // SKP Vx
    void OP_Ex9E();

    // SKNP Vx
    void OP_ExA1();

    // LD Vx, DT
    void OP_Fx07();

    // LD Vx, K
    void OP_Fx0A();

    // LD DT, Vx
    void OP_Fx15();

    // LD ST, Vx
    void OP_Fx18();

    // ADD I, Vx
    void OP_Fx1E();

    // LD F, Vx
    void OP_Fx29();

    // LD B, Vx
    void OP_Fx33();

    // LD [I], Vx
    void OP_Fx55();

    // LD Vx, [I]
    void OP_Fx65();
};


#endif //CHIP8_CHIP8_H
