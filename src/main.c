#include "main.h"

// TODO:
// Camera (Lookup best practices)
// // Camera w2vec and vec2w functions <<
// // Camera bounds
// // Render Map Object 
// // WASD Move Camera
// // General rendering scripts for camera
// Entities
// // Collisions
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
// // // Texture/texture atlas editor?
// // Sprite handling
// // Sprite animations
// Audio

int main(int argc, char* argv[]) {
	printf("Good Build Compile\n");

    // Init App
    App app;
    memset(&app, 0, sizeof(App)); // Maybe change when spawning entities, or have their own memory
    initApp(&app);

    while (app.running) {
        updateApp(&app);
        SDL_Delay(DELAY);
    }
    
    clean(&app);

    return 0;
}