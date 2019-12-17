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

    bool Initialize();
    void PollEvents();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;

    uint32_t tick;
    bool running;

    const int kWidth = 640;
    const int kHeight = 480;
};


#endif //CHIP8_WINDOW_H
