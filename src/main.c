#include "main.h"

// TODO:
// Delta time for frame rate independence
// FPS counter
// Input handling
// Basic renderering
// Camera
// Entities

int main(int argc, char* argv[]) {
	printf("Good Build Compile\n");

    // Init App
    App app;
    memset(&app, 0, sizeof(App));
    initSDL(&app);

    // Timer 
    Uint32 lastTime = 0;
    float deltaTime = 0.0f;

    while (app.running) {
        getDeltaTime(&lastTime, &deltaTime);
        prepareScene(&app);
        doInput();
        presentScene(&app);
        SDL_Delay(DELAY);
    }
    
    cleanup(&app);

    return 0;
}