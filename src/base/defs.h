#ifndef DEFS_H
#define DEFS_H

#include "structs.h"

// Base
#define TRUE 1 // Remove these, stdbool.h is used
#define FALSE 0
#define DELAY 16 // ~60FPS

// Screen
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define FPS_TEXT_MAX 64

// Colors
#define COLOR_TRANSPARENT (Color){0, 0, 0, 0}
#define COLOR_WHITE (Color){255, 255, 255, 255}
#define COLOR_BLACK (Color){0, 0, 0, 255}
#define COLOR_RED (Color){255, 0, 0, 255}
#define COLOR_GREEN (Color){0, 255, 0, 255}
#define COLOR_BLUE (Color){0, 0, 255, 255}

// Mouse
#define MOUSE_WIDTH 10
#define MOUSE_HEIGHT 10

static const Color mouse_state_colors[] = {
    [MOUSE_DEFAULT] = COLOR_WHITE,
    [MOUSE_HOVER] = COLOR_BLUE,
    [MOUSE_CLICK_L] = COLOR_GREEN,
    [MOUSE_CLICK_R] = COLOR_RED,
    [MOUSE_INACTIVE] = COLOR_BLACK
};

#endif // DEFS_H