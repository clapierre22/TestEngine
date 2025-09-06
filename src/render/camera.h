#ifndef CAMERA_H
#define CAMERA_H

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#include "base/defs.h"
#include "base/structs.h"

#include "math/delta.h"
#include "math/world.h"

#include "draw.h"

void initCamera(App *app);
void moveCamera(App *app, WorldPoint position);
void zoomCamera(App *app, float zoom);
void setCameraMode(App *app, CameraMode mode);
void handleCameraInput(App *app);
void updateCamera(App *app);

// Macros
#define WORLD_TO_SCREEN_X(cam, wx) ((int)((wx - (cam)->x) * (cam)->zoom + (cam)->half_width))
#define WORLD_TO_SCREEN_Y(cam, wy) ((int)((wy - (cam)->y) * (cam)->zoom + (cam)->half_height))
#define WORLD_TO_SCREEN_W(cam, w) ((int)((w) * (cam)->zoom))
#define WORLD_TO_SCREEN_H(cam, h) ((int)((h) * (cam)->zoom))

#define WORLD_TO_SCREEN_RECT(cam, wx, wy, w, h) { \
    (int)((wx - (cam)->x) * (cam)->zoom + (cam)->half_width), \
    (int)((wy - (cam)->y) * (cam)->zoom + (cam)->half_height), \
    (int)((w) * (cam)->zoom), \
    (int)((h) * (cam)->zoom) \
}

#define SCREEN_TO_WORLD_X(cam, sx) (((sx) - (cam)->half_width) * (cam)->inv_zoom + (cam)->x)
#define SCREEN_TO_WORLD_Y(cam, sy) (((sy) - (cam)->half_height) * (cam)->inv_zoom + (cam)->y)

#endif // CAMERA_H