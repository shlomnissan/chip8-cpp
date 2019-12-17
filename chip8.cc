//
// Created by Shlomi Nissan on 12/17/19.
//

#include "chip8.h"

//region Public

Chip8::Chip8(): memory({0}),
                V({0}),
                display({0}),
                stack({0}),
                t_delay(0),
                t_sound(0),
                I(0),
                pc(0x200),
                sp(0) {

    // Store sprites data at the beginning of the memory
    std::memcpy(memory.data(), kSprites.data(), kSprites.size());
}

void Chip8::SaveRom(const void *source, size_t size) {
    // 0x200 (512) Start of most Chip-8 programs
    std::memcpy(memory.data() + 0x200, source, size);
}

void Chip8::Reset() {
    // Clear out rom data from memory
    std::memset(memory.data() + 0x200, 0, memory.size() - 0x200);

    V = {0};
    display = {0};
    stack = {0};
    I = 0;
    pc = 0x200;
    sp = 0;
    t_delay = 0;
    t_sound = 0;
}

//endregion

//region Private

void Chip8::UpdateDisplay() {

}

void Chip8::UpdateTimers() {

}

//endregion
