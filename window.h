//
// Created by Shlomi Nissan on 12/16/19.
//

#ifndef CHIP8_WINDOW_H
#define CHIP8_WINDOW_H

#include <SDL.h>

constexpr uint16_t kWidth = 640;
constexpr uint16_t kHeight = 480;

class Window {
public:
    Window(): window(nullptr), renderer(nullptr), tick(0), running(false) {}
    ~Window();

    bool Initialize();
    void PollEvents();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;

    uint32_t tick;
    bool running;
};


#endif //CHIP8_WINDOW_H
