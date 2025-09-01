#ifndef STRUCTS_H
#define STRUCTS_H

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

typedef struct {
    int running;
    SDL_Renderer *renderer;
    SDL_Window *window;
    uint32_t fps;
    uint32_t lastTime;
    float deltaTime;
    int mouseX, mouseY; // SDL Uses int type for mouse x,y
} App;

#endif // STRUCTS_H