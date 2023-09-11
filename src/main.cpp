#include "SDL.h"

int main() {
    if (SDL_InitSubSystem(SDL_InitFlags::SDL_INIT_VIDEO) != 0) {
        SDL_LogCritical(SDL_LOG_CATEGORY_APPLICATION, "SDL_InitSubSystem failed: %s", SDL_GetError());
        return 1;
    }

    int width = 640, height = 480;

    auto window = SDL_CreateWindow("Hello World!", width, height, 
        SDL_WindowFlags::SDL_WINDOW_RESIZABLE
    );

    bool running = true;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EventType::SDL_EVENT_QUIT) {
                running = false;
            }
        }
    }

    SDL_Log("%s", "Hello World!");

    SDL_QuitSubSystem(SDL_INIT_VIDEO);
    return 0;
}
