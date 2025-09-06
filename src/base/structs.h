#ifndef STRUCTS_H
#define STRUCTS_H

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <stdbool.h>

#include "defs.h"

typedef struct {
    uint8_t r, g, b, a;
} Color;

typedef struct {
    float a, b;
} Vec2;

typedef struct {
    int x, y;
} Position;

typedef struct {
    float x, y;
} WorldPoint;

typedef struct {
    int x, y;
} ScreenPoint;

typedef struct {
    int a, b;
} ScreenSize;

typedef struct {
    Position position;
    Vec2 size;
    bool clickL, clickR, hover, inactive;
    MouseState state;
} Mouse;

typedef struct {
    EntityType type;
    char *id;
    Position position; // Top left corner
    ScreenPoint screenPos;
    Vec2 size;
    ScreenSize screenSize;
    SDL_Rect hitbox;
    SDL_Rect screenHitbox;
} Entity;

typedef struct {
    Position position;
    Vec2 size;
    float halfW, halfH;
    float zoom, invZoom;
    CameraMode mode;
} Camera;

typedef struct {
    int up, down, left, right; // Movement
    bool a1, a2; // Action buttons
} Input;

typedef struct {
    int running;
    SDL_Renderer *renderer;
    SDL_Window *window;
    uint32_t fps;
    uint32_t lastTime;
    float deltaTime;
    Mouse mouse;
    Camera camera;
    Input input; // Stores next input for camera/player
    Entity *entities;
    int entityCount;
    int entityCap;
} App;

#endif // STRUCTS_H