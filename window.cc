//
// Created by Shlomi Nissan on 12/16/19.
//

#include "window.h"

Window::~Window() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

bool Window::Initialize() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        return false;
    }
    SDL_CreateWindowAndRenderer(kWidth, kHeight, 0, &window, &renderer);
    return !(nullptr == window || nullptr == renderer);
}

void Window::PollEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event) != 0) {
        if (event.type == SDL_QUIT) {
            running = false;
        }
        if (event.type == SDL_KEYDOWN) {
            // TODO: handle key press
        }
        if (event.type == SDL_KEYUP) {
            // TODO: handle key release
        }
    }
}