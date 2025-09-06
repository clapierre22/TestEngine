#include "draw.h"

// Mouse state colors lookup table
const Color mouse_state_colors[] = {
    [MOUSE_DEFAULT] = {255, 255, 255, 255},
    [MOUSE_HOVER] = {0, 0, 255, 255},
    [MOUSE_CLICK_L] = {0, 255, 0, 255},
    [MOUSE_CLICK_R] = {255, 0, 0, 255},
    [MOUSE_INACTIVE] = {0, 0, 0, 255}
};

void prepareScene(App *app) {
    SDL_SetRenderDrawColor(app->renderer, 96, 128, 255, 255);
    SDL_RenderClear(app->renderer);
    renderMouse(app);
    // for (int i = 0; i < app->entityCount; i++) renderEntity(app, &entities[i]); NEXT TODO
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

void renderMouse(App *app) { // Mouse always rendered last (on top), and at fixed scale
    SDL_Rect mouseRect = {
        app->mouse.position.x - MOUSE_WIDTH / 2,
        app->mouse.position.y - MOUSE_HEIGHT / 2,
        MOUSE_HEIGHT,
        MOUSE_WIDTH
    };

    // When change to sprite, same logic but with the sprite mapping
    SDL_SetRenderDrawColor(
        app->renderer, 
        mouse_state_colors[app->mouse.state].r,
        mouse_state_colors[app->mouse.state].g,
        mouse_state_colors[app->mouse.state].b,
        mouse_state_colors[app->mouse.state].a
    );

    SDL_RenderFillRect(app->renderer, &mouseRect);
}

void renderEntity(App *app, Entity *entity) {
    if (
        !entity 
        || entity->type == ENTITY_TYPE_NONE
        // || !withinCamera(&app->camera, entity) TODO
    ) return;

    entity->screenPos.x = WORLD_TO_SCREEN_X(&app->camera, entity->position.x);
    entity->screenPos.y = WORLD_TO_SCREEN_Y(&app->camera, entity->position.y);
    entity->screenSize.a = WORLD_TO_SCREEN_W(&app->camera, entity->size.a);
    entity->screenSize.b = WORLD_TO_SCREEN_H(&app->camera, entity->size.b);

    entity->screenHitbox.x = entity->screenPos.x;
    entity->screenHitbox.y = entity->screenPos.y;
    entity->screenHitbox.w = entity->screenSize.a;
    entity->screenHitbox.h = entity->screenSize.b;

    SDL_SetRenderDrawColor(app->renderer, 255, 255, 0, 255); // Yellow for entities
    SDL_RenderFillRect(app->renderer, &entity->screenHitbox);
}