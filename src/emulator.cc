//
// Created by Shlomi Nissan on 12/16/19.
//

#include <fstream>
#include <vector>

#include "emulator.h"

bool Emulator::Boot() {
    return window.Initialize();
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

    chip8.SaveRom(buffer.data(), buffer.size());

    return true;
}

void Emulator::Start() {
    uint32_t tick = 0;

    while (window.get_running()) {
        tick = window.get_tick();
        window.PollEvents();

        display[1 + display.height()] = 1;

        chip8.Cycle();
        window.Draw(display);
        window.RegulateFrameRate(tick);
    }
}