#include "draw.h"

void prepareScene(App *app) {
    SDL_SetRenderDrawColor(app->renderer, 96, 128, 255, 255);
    SDL_RenderClear(app->renderer);
    renderMouse(app);
}

void presentScene(App *app) {
    SDL_RenderPresent(app->renderer);
    renderFPS(app);
}

void renderFPS(App *app) {
    // Placeholder function until TTF is integrated
    char fpsText[FPS_TEXT_MAX];
    snprintf(fpsText, sizeof(fpsText), "FPS: %d", app->fps);
    SDL_SetWindowTitle(app->window, fpsText);
}

void renderMouse(App *app) {
    SDL_Rect mouseRect = {
        app->mouse.position.x - MOUSE_WIDTH / 2,
        app->mouse.position.y - MOUSE_HEIGHT / 2,
        MOUSE_HEIGHT,
        MOUSE_WIDTH
    };

    SDL_SetRenderDrawColor(
        app->renderer, 
        mouse_state_colors[app->mouse.state].r,
        mouse_state_colors[app->mouse.state].g,
        mouse_state_colors[app->mouse.state].b,
        mouse_state_colors[app->mouse.state].a
    );

    SDL_RenderFillRect(app->renderer, &mouseRect);
}