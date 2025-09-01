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
    
    // Temp mouse values
    // uint32_t mouseX, mouseY;
    SDL_GetMouseState(&app->mouseX, &app->mouseY);

    uint32_t mouseButtons = SDL_GetMouseState(NULL, NULL);
    if (mouseButtons & SDL_BUTTON(SDL_BUTTON_LEFT)) {
        printf("Left Click @ %d, %d (x, y)\n", app->mouseX, app->mouseY);
    }
    if (mouseButtons & SDL_BUTTON(SDL_BUTTON_RIGHT)) {
        printf("Right Click @ %d, %d (x, y)\n", app->mouseX, app->mouseY);
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