#include "input.h"

void initMouse(App *app) {
    Mouse mouse;
    memset(&mouse, 0, sizeof(Mouse));
    mouse.position.x = 0;
    mouse.position.y = 0;
    mouse.size.a = MOUSE_WIDTH;
    mouse.size.b = MOUSE_HEIGHT;
    app->mouse = mouse;
}

void doInput(App *app) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_WINDOWEVENT: {
                if (event.window.event == SDL_WINDOWEVENT_ENTER) {
                    SDL_ShowCursor(SDL_DISABLE);
                }
                if (event.window.event == SDL_WINDOWEVENT_LEAVE) {
                    SDL_ShowCursor(SDL_ENABLE);
                }
                break;
            }
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
    
    SDL_GetMouseState(&app->mouse.position.x, &app->mouse.position.y);

    app->mouse.state = MOUSE_DEFAULT;

    uint32_t mouseButtons = SDL_GetMouseState(NULL, NULL);
    if (mouseButtons & SDL_BUTTON(SDL_BUTTON_LEFT)) {
        printf("Left Click @ %d, %d (x, y)\n", app->mouse.position.x, app->mouse.position.y);
        app->mouse.state = MOUSE_CLICK_L;
    }
    if (mouseButtons & SDL_BUTTON(SDL_BUTTON_RIGHT)) {
        printf("Right Click @ %d, %d (x, y)\n", app->mouse.position.x, app->mouse.position.y);
        app->mouse.state = MOUSE_CLICK_R;
    }

    const uint8_t *state = SDL_GetKeyboardState(NULL);

    if (state[SDL_SCANCODE_W]) {
        // printf("W\n");
        app->input.up -= (int)(CAMERA_MOVE_SPEED * app->deltaTime);
    }
    if (state[SDL_SCANCODE_S]) {
        // printf("S\n");
        app->input.down -= (int)(CAMERA_MOVE_SPEED * app->deltaTime);
    }
    if (state[SDL_SCANCODE_A]) {
        // printf("A\n");
        app->input.left -= (int)(CAMERA_MOVE_SPEED * app->deltaTime);
    }
    if (state[SDL_SCANCODE_D]) {
        // printf("D\n");
        app->input.right -= (int)(CAMERA_MOVE_SPEED * app->deltaTime);
    }

    if (state[SDL_SCANCODE_SPACE]) {
        zoomCamera(app, CAMERA_BASE_ZOOM);
        moveCamera(app, (WorldPoint){0.0f, 0.0f});
    }
}