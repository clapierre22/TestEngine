#ifndef STRUCTS_H
#define STRUCTS_H

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <stdbool.h>

typedef struct {
    uint8_t r, g, b, a;
} Color;

typedef struct {
    float a, b;
} Vec2;

typedef struct {
    int x, y;
} Position;

typedef enum {
    MOUSE_DEFAULT,
    MOUSE_HOVER,
    MOUSE_CLICK_L,
    MOUSE_CLICK_R,
    MOUSE_INACTIVE
} MouseState;

typedef struct {
    Position position;
    Vec2 size;
    bool clickL, clickR, hover, inactive;
    MouseState state;
} Mouse;

typedef struct {
    EntityType type;
    char *id;
    Position position;
    Vec2 size;
} Entity;

typedef struct {
    int running;
    SDL_Renderer *renderer;
    SDL_Window *window;
    uint32_t fps;
    uint32_t lastTime;
    float deltaTime;
    // int mouseX, mouseY; // SDL Uses int type for mouse x,y
    Mouse mouse;
} App;

#endif // STRUCTS_H