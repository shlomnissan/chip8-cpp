//
// Created by Shlomi Nissan on 12/16/19.
//

#include "window.h"
#include "display.h"

Window::~Window() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

bool Window::Initialize() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        return false;
    }

    Display& display = Display::Instance();

    SDL_CreateWindowAndRenderer(display.width() * display.scale(),
                                display.height() * display.scale(),
                                0,
                                &window,
                                &renderer);
    if (window == nullptr || renderer == nullptr) return false;
    SDL_SetWindowTitle(window, "Chip-8 Emulator");

    running = true;
    return true;
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

void Window::RegulateFrameRate(uint32_t tick) {
    const auto kOffset  = SDL_GetTicks() - tick;
    if (kDelay > kOffset) {
        SDL_Delay(kDelay - kOffset);
    }
}
