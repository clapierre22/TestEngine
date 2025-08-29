#include "main.h"

// TODO:
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
    initApp(&app);

    while (app.running) {
        updateApp(&app);
        prepareScene(&app);
        doInput(&app);
        presentScene(&app); // Error: FPS = 0
        SDL_Delay(DELAY);
    }
    
    clean(&app);

    return 0;
}