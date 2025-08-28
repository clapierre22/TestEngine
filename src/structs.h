#ifndef STRUCTS_H
#define STRUCTS_H

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

typedef struct {
    int running;
    SDL_Renderer *renderer;
    SDL_Window *window;
} App;

#endif // STRUCTS_H