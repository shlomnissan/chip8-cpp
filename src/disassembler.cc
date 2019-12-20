//
// Created by Shlomi Nissan on 12/20/19.
//

#include "disassembler.h"

void Disassembler::OP_00E0() {
    c8.display.ClearScreen();
}

void Disassembler::OP_00EE() {
    c8.sp--;
    c8.pc = c8.stack[c8.sp];
}

void Disassembler::OP_1nnn() {
    uint16_t address = c8.opcode & 0x0FFFu;
    c8.pc = address;
}

void Disassembler::OP_2nnn() {

}

void Disassembler::OP_3xkk() {

}

void Disassembler::OP_4xkk() {

}

void Disassembler::OP_5xy0() {

}

void Disassembler::OP_6xkk() {

}

void Disassembler::OP_7xkk() {

}

void Disassembler::OP_8xy0() {

}

void Disassembler::OP_8xy1() {

}

void Disassembler::OP_8xy2() {

}

void Disassembler::OP_8xy3() {

}

void Disassembler::OP_8xy4() {

}

void Disassembler::OP_8xy5() {

}

void Disassembler::OP_8xy6() {

}

void Disassembler::OP_8xy7() {

}

void Disassembler::OP_8xyE() {

}

void Disassembler::OP_9xy0() {

}

void Disassembler::OP_Annn() {

}

void Disassembler::OP_Bnnn() {

}

void Disassembler::OP_Cxkk() {

}

void Disassembler::OP_Dxyn() {

}

void Disassembler::OP_Ex9E() {

}

void Disassembler::OP_ExA1() {

}

void Disassembler::OP_Fx07() {

}

void Disassembler::OP_Fx0A() {

}

void Disassembler::OP_Fx15() {

}

void Disassembler::OP_Fx18() {

}

void Disassembler::OP_Fx1E() {

}

void Disassembler::OP_Fx29() {

}

void Disassembler::OP_Fx33() {

}

void Disassembler::OP_Fx55() {

}

void Disassembler::OP_Fx65() {

}

