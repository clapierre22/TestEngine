#include "delta.h"

void getDeltaTime(Uint32 *lastTime, float *deltaTime) {
    Uint32 currTime = SDL_GetTicks();
    
    if (*lastTime == 0) {
        *lastTime = currTime;  // First frame initialization
        *deltaTime = 0.0f;
        return;
    }
    
    *deltaTime = (currTime - *lastTime) / 1000.0f;
    *lastTime = currTime;
}