#include "main.h"

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
    
    free(app.renderer);
    free(app.window);
    SDL_Quit();
    
    return 0;
}