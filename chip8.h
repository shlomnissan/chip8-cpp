//
// Created by Shlomi Nissan on 12/17/19.
//

#ifndef CHIP8_CHIP8_H
#define CHIP8_CHIP8_H

#include <array>

class Chip8 {
public:
    Chip8();

    void SaveRom(const void* source, size_t size);
    void Reset();
private:
    /*
     * Memory Map:
     *
     * +---------------+= 0xFFF (4095) End of Chip-8 RAM
     * |               |
     * |               |
     * |               |
     * |               |
     * |               |
     * | 0x200 to 0xFFF|
     * |     Chip-8    |
     * | Program / Data|
     * |     Space     |
     * |               |
     * |               |
     * |               |
     * +- - - - - - - -+= 0x600 (1536) Start of ETI 660 Chip-8 programs
     * |               |
     * |               |
     * |               |
     * +---------------+= 0x200 (512) Start of most Chip-8 programs
     * | 0x000 to 0x1FF|
     * | Reserved for  |
     * |  interpreter  |
     * +---------------+= 0x000 (0) Start of Chip-8 RAM
     */
    std::array<uint8_t, 0x1000> memory;
    std::array<uint8_t, 0x10> V;
    std::array<uint8_t, 0x800> display;
    std::array<uint16_t, 0x10> stack;

    uint8_t t_delay;
    uint8_t t_sound;

    uint16_t I;
    uint16_t pc;
    uint16_t sp;

    const std::array<uint8_t, 0x50> kSprites {
            0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
            0x20, 0x60, 0x20, 0x20, 0x70, // 1
            0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
            0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
            0x90, 0x90, 0xF0, 0x10, 0x10, // 4
            0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
            0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
            0xF0, 0x10, 0x20, 0x40, 0x40, // 7
            0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
            0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
            0xF0, 0x90, 0xF0, 0x90, 0x90, // A
            0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
            0xF0, 0x80, 0x80, 0x80, 0xF0, // C
            0xE0, 0x90, 0x90, 0x90, 0xE0, // D
            0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
            0xF0, 0x80, 0xF0, 0x80, 0x80  // F
    };

    /*
     * Keyboard Mapping:
     *
     * ------------------------------------------------
     * |   Chip 8 Keyboard    |      PC Keyboard      |
     * ------------------------------------------------
     * |   1    2    3    C   |    1    2    3    4   |
     * |   4    5    6    D   |    Q    W    E    R   |
     * |   7    8    9    E   |    A    S    D    F   |
     * |   A    0    B    F   |    Z    X    C    V   |
     * ------------------------------------------------
     */
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

    void UpdateDisplay();
    void UpdateTimers();
};


#endif //CHIP8_CHIP8_H
