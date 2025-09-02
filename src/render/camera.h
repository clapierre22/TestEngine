#ifndef CAMERA_H
#define CAMERA_h

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#include "base/defs.h"
#include "base/structs.h"

#include "math/delta.h"
#include "draw.h"

void initCamera(App *app);
void updateCamera(App *app);
void moveCamera(App *app, Position position);
void zoomCamera(App *app, float zoom);

#endif // CAMERA_H