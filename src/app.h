#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#include "base/defs.h"
#include "base/structs.h"

#include "math/delta.h"
#include "base/cleanup.h"
#include "render/draw.h"
#include "logic/input.h"

void initSDL(App *app);
void initApp(App *app);
void updateApp(App *app);
void renderApp(App *app);