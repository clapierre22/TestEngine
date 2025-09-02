#include "main.h"

// TODO:
// Camera
// Entities
// Map
// UI
// Textures and Sprites
// Audio

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
        presentScene(&app);
        SDL_Delay(DELAY);
    }
    
    clean(&app);

    return 0;
}