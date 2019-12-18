//
// Created by Shlomi Nissan on 12/16/19.
//

#ifndef CHIP8_WINDOW_H
#define CHIP8_WINDOW_H

#include <SDL.h>

class Window {
public:
    Window(): window(nullptr), renderer(nullptr), tick(0), running(false) {}
    ~Window();

    bool get_running() { return running; }
    uint32_t get_tick() { return SDL_GetTicks(); }

    bool Initialize();
    void PollEvents();
    void RegulateFrameRate(uint32_t tick);
private:
    SDL_Window* window;
    SDL_Renderer* renderer;

    uint32_t tick;
    bool running;

    // 1000ms / 60fps = 16.66 delay
    const float kDelay = 16.66f;

    const int kWidth = 640;
    const int kHeight = 480;
};


#endif //CHIP8_WINDOW_H
