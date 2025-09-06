#include "camera.h"

void initCamera(App *app) {
    Camera camera;
    memset(&camera, 0, sizeof(Camera));
    camera.position.x = 0.0f;
    camera.position.y = 0.0f;
    camera.size.a = CAMERA_BASE_WIDTH;
    camera.size.b = CAMERA_BASE_HEIGHT;
    camera.zoom = CAMERA_BASE_ZOOM;
    camera.mode = CAMERA_MODE_FIXED;

    app->camera = camera;
}

void moveCamera(App *app, WorldPoint position) {
    app->camera.position = position;
}

void zoomCamera(App *app, float zoom) {
    app->camera.zoom = zoom;
    app->camera.invZoom = 1.0f / app->camera.zoom;
}

void setCameraMode(App *app, CameraMode mode) {
    app->camera.mode = mode;
}

void handleCameraInput(App *app) {
    // TODO
    app->camera.position.x += app->input.left + app->input.right;
    app->camera.position.y += app->input.up + app->input.down;

    if (app->input.a1) {
        app->camera.zoom += 0.1f;
        if (app->camera.zoom > 3.0f) app->camera.zoom = 3.0f; // Max zoom
    }
    if (app->input.a2) {
        app->camera.zoom -= 0.1f;
        if (app->camera.zoom < 0.5f) app->camera.zoom = 0.5f; // Min zoom
    }
}

void updateCamera(App *app) {
    // TODO
    app->camera.halfW = app->camera.size.a * 0.5f;
    app->camera.halfH = app->camera.size.b * 0.5f;
    app->camera.invZoom = 1.0f / app->camera.zoom;

    switch (app->camera.mode) {
        case CAMERA_MODE_FIXED:
            // No movement
            break;
        case CAMERA_MODE_FOLLOW:
            // Follow an entity (not implemented yet), direcly calls moveCamera
            // moveCamera(app, entity->position);
            break;
        case CAMERA_MODE_FREE:
            handleCameraInput(app);
            break;
        default:
            break;
    }
}