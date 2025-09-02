#include "app.h"

void initSDL(App *app) {
    if (SDL_Init(SDL_INIT_VIDEO) < false) {
        fprintf(stderr, "Could not initialize SDL: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    app->running = true;

    app->window = SDL_CreateWindow(
        "Test Engine",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN
    );
    
    if (!app->window) {
        fprintf(stderr, "Could not create window: %s\n", SDL_GetError());
        SDL_Quit();
        exit(EXIT_FAILURE);
    }

    app->renderer = SDL_CreateRenderer(app->window, -1, SDL_RENDERER_ACCELERATED);
    if (!app->renderer) {
        fprintf(stderr, "Could not create renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(app->window);
        SDL_Quit();
        exit(EXIT_FAILURE);
    }
}

void initMouse(App *app) {
    Mouse mouse;
    memset(&mouse, 0, sizeof(Mouse));
    mouse.position.x = 0;
    mouse.position.y = 0;
    mouse.size.a = MOUSE_WIDTH;
    mouse.size.b = MOUSE_HEIGHT;
    app->mouse = mouse;
}

void initApp(App *app) {
    initSDL(app);
    initMouse(app);
    app->running = true;
    app->fps = 0;
    app->lastTime = 0;
    app->deltaTime = 0.0f;
}

void updateApp(App *app) {
    getDeltaTime(&app->lastTime, &app->deltaTime);
    getFPS(&app->fps, &app->deltaTime);
}