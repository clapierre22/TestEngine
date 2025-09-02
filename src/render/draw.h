#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
// #include <SDL2/SDL_ttf.h>

#include "base/defs.h"
#include "base/structs.h"

extern const Color mouse_state_colors[];
void prepareScene(App *app);
void presentScene(App *app);
void renderFPS(App *app);
void renderMouse(App *app);
void renderEntity(App *app, Entity *entity);