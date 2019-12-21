//
// Created by Shlomi Nissan on 12/20/19.
//

#include "interpreter.h"

void Interpreter::OP_00E0() {
    c8.display.ClearScreen();
}

void Interpreter::OP_00EE() {
    c8.sp--;
    c8.pc = c8.stack[c8.sp];
}

void Interpreter::OP_1nnn() {
    uint16_t address = c8.opcode & 0x0FFFu;
    c8.pc = address;
}

void Interpreter::OP_2nnn() {

}

void Interpreter::OP_3xkk() {

}

void Interpreter::OP_4xkk() {

}

void Interpreter::OP_5xy0() {

}

void Interpreter::OP_6xkk() {

}

void Interpreter::OP_7xkk() {

}

void Interpreter::OP_8xy0() {

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

