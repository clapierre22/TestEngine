#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
// #include <SDL2/SDL_ttf.h>

#include "base/defs.h"
#include "base/structs.h"

#include "app.h"

void prepareScene(App *app);
void presentScene(App *app);
void renderFPS(App *app);