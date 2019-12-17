//
// Created by Shlomi Nissan on 12/16/19.
//

#ifndef CHIP8_EMULATOR_H
#define CHIP8_EMULATOR_H

#include <string>

using std::string;

class Emulator {
public:
    bool Boot();
    bool LoadRom(const string& kFile);
    void Start();
};


#endif //CHIP8_EMULATOR_H
