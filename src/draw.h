#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
// #include <SDL2/SDL_ttf.h>

#include "defs.h"
#include "structs.h"

#include "app.h"

void prepareScene(App *app);
void presentScene(App *app);
void renderFPS(App *app);