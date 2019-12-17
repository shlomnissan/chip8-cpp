//
// Created by Shlomi Nissan on 12/16/19.
//

#include <fstream>
#include <vector>

#include "emulator.h"

bool Emulator::Boot() {
    return true;
}

bool Emulator::LoadRom(const string& kFile) {
    std::ifstream rom (kFile);
    if (!rom) return false;

    rom.seekg(0, std::ios::end);
    const int kSize = rom.tellg();
    rom.seekg(0, std::ios::beg);

    // Read rom data into a temporary buffer
    std::vector<char> buffer;
    buffer.reserve(kSize);
    buffer.insert(buffer.begin(),
            std::istreambuf_iterator<char>(rom),
            std::istreambuf_iterator<char>());

    // TODO: insert to memory

    return true;
}

void Emulator::Start() {

}