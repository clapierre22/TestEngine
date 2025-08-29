#include "input.h"

void doInput(App *app) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT: {
                exit(0);
                break;
            }
            case SDL_KEYDOWN: {
                // TODO: Handle single button presses here (i.e., actions)
                break;
            }
        }
    }

    const uint8_t *state = SDL_GetKeyboardState(NULL);

    if (state[SDL_SCANCODE_W]) {
        printf("W\n");
    }
    if (state[SDL_SCANCODE_S]) {
        printf("S\n");
    }
    if (state[SDL_SCANCODE_A]) {
        printf("A\n");
    }
    if (state[SDL_SCANCODE_D]) {
        printf("D\n");
    }
}