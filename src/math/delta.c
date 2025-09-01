#include "delta.h"

void getDeltaTime(uint32_t *lastTime, float *deltaTime) {
    uint32_t currTime = SDL_GetTicks();
    
    if (*lastTime == 0) {
        *lastTime = currTime;  // First frame initialization
        *deltaTime = 0.0f;
        return;
    }
    
    *deltaTime = (currTime - *lastTime) / 1000.0f;
    *lastTime = currTime;
}

void getFPS(uint32_t *fps, float *deltaTime) {
    if (*deltaTime > 0.0f) {
        *fps = (uint32_t)(1.0f / *deltaTime);
    }
}