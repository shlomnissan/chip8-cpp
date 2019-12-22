//
// Created by Shlomi Nissan on 12/20/19.
//

#include "interpreter.h"

// Clear the screen
void Interpreter::OP_00E0() {
    c8.display.ClearScreen();
}

// Return from a subroutine
void Interpreter::OP_00EE() {
    c8.pc = c8.stack[c8.sp--];
}

// Jump to location nnn
void Interpreter::OP_1nnn() {
    uint16_t address = c8.opcode & 0x0FFFu;
    c8.pc = address;
}

// Call subroutine at nnn
void Interpreter::OP_2nnn() {
    uint16_t address = c8.opcode & 0x0FFFu;
    c8.stack[c8.sp++] = c8.pc;
    c8.pc = address;
}

// Skip next instruction of Vx == kk
void Interpreter::OP_3xkk() {
    uint8_t Vx = c8.opcode & 0x0F00u >> 8u;
    uint8_t byte = c8.opcode & 0x00FFu;
    if (c8.registers[Vx] == byte) {
        c8.pc += 2;
    }
}

// Skip next instruction if Vx != kk
void Interpreter::OP_4xkk() {
    uint8_t Vx = c8.opcode & 0x0F00u >> 8u;
    uint8_t byte = c8.opcode & 0x00FFu;
    if (c8.registers[Vx] != byte) {
        c8.pc += 2;
    }
}

// Skip next instruction if Vx = Vy
void Interpreter::OP_5xy0() {
    uint8_t Vx = c8.opcode & 0x0F00u >> 8u;
    uint8_t Vy = c8.opcode & 0x00F0u >> 4u;
    if (c8.registers[Vx] == c8.registers[Vy]) {
        c8.pc += 2;
    }
}

// Set Vx = kk
void Interpreter::OP_6xkk() {
    uint8_t Vx = c8.opcode & 0x0F00u >> 8u;
    uint8_t byte = c8.opcode & 0x00FFu;
    c8.registers[Vx] = byte;
}

// Set Vx = Vx + kk
void Interpreter::OP_7xkk() {
    uint8_t Vx = (c8.opcode & 0x0F00u) >> 8u;
    uint8_t byte = c8.opcode & 0x00FFu;
    c8.registers[Vx] += byte;
}

// Set Vx = Vy
void Interpreter::OP_8xy0() {
    uint8_t Vx = c8.opcode & 0x0F00u >> 8u;
    uint8_t Vy = c8.opcode & 0x00F0u >> 4u;
    c8.registers[Vx] = c8.registers[Vy];
}

void Interpreter::OP_8xy1() {

}

void Interpreter::OP_8xy2() {

}

void Interpreter::OP_8xy3() {

}

void Interpreter::OP_8xy4() {

}

void Interpreter::OP_8xy5() {

}

void Interpreter::OP_8xy6() {

}

void Interpreter::OP_8xy7() {

}

void Interpreter::OP_8xyE() {

}

void Interpreter::OP_9xy0() {

}

void Interpreter::OP_Annn() {

}

void Interpreter::OP_Bnnn() {

}

void Interpreter::OP_Cxkk() {

}

void Interpreter::OP_Dxyn() {

}

void Interpreter::OP_Ex9E() {

}

void Interpreter::OP_ExA1() {

}

void Interpreter::OP_Fx07() {

}

void Interpreter::OP_Fx0A() {

}

void Interpreter::OP_Fx15() {

}

void Interpreter::OP_Fx18() {

}

void Interpreter::OP_Fx1E() {

}

void Interpreter::OP_Fx29() {

}

void Interpreter::OP_Fx33() {

}

void Interpreter::OP_Fx55() {

}

void Interpreter::OP_Fx65() {

}

