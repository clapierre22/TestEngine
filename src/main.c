#include "main.h"

// TODO:
// Cleanup function
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

    // atexit(cleanup);
    app.running = TRUE;

    while (app.running) {
        prepareScene(&app);
        doInput();
        presentScene(&app);
        SDL_Delay(DELAY);
    }
    
    cleanup(&app);

    return 0;
}