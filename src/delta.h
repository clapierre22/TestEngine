#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#include "defs.h"
#include "structs.h"

void getDeltaTime(uint32_t *lastTime, float *deltaTime);
void getFPS(uint32_t *fps, float *deltaTime);