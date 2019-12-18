//
// Created by Shlomi Nissan on 12/16/19.
//

#ifndef CHIP8_EMULATOR_H
#define CHIP8_EMULATOR_H

#include <string>

#include "window.h"
#include "chip8.h"

using std::string;

class Emulator {
public:
    bool Boot();
    bool LoadRom(const string& kFile);
    void Start();

    Emulator(): window() {}
private:
    Window window;
    Chip8 chip8;
};


#endif //CHIP8_EMULATOR_H
