#include "main.h"

// TODO:
// Camera
// // Render Map Object <<
// // WASD Move Camera
// // General rendering scripts for camera
// Entities
// // Fully implement entities
// // Entity logic
// // // Spawning
// // // Movement
// // // Death
// Map
// // Load Map from file
// // Map logic
// // Map editor
// UI
// // Map editor UI
// // In-game UI
// Textures and Sprites
// // Texture atlas
// // Sprite handling
// // Sprite animations
// Audio

int main(int argc, char* argv[]) {
	printf("Good Build Compile\n");

    // Init App
    App app;
    memset(&app, 0, sizeof(App));
    initApp(&app);

    while (app.running) {
        updateApp(&app);
        // prepareScene(&app);
        // doInput(&app);
        // presentScene(&app);
        SDL_Delay(DELAY);
    }
    
    clean(&app);

    return 0;
}