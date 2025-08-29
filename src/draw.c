#include "draw.h"

void prepareScene(App *app) {
    SDL_SetRenderDrawColor(app->renderer, 96, 128, 255, 255);
    SDL_RenderClear(app->renderer);
}

void presentScene(App *app) {
    SDL_RenderPresent(app->renderer);
    renderFPS(app);
}

void renderFPS(App *app) {
    // Placeholder function until TTF is integrated
    char fpsText[64];
    snprintf(fpsText, sizeof(fpsText), "FPS: %d", app->fps);
    SDL_SetWindowTitle(app->window, fpsText);
}