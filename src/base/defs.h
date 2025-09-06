#ifndef DEFS_H
#define DEFS_H

// #include "structs.h"

// Base
#define TRUE 1 // Remove these, stdbool.h is used
#define FALSE 0
#define DELAY 16 // ~60FPS

// Screen
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define FPS_TEXT_MAX 64

// Colors

// Mouse
#define MOUSE_WIDTH 10
#define MOUSE_HEIGHT 10

typedef enum {
    MOUSE_DEFAULT,
    MOUSE_HOVER,
    MOUSE_CLICK_L,
    MOUSE_CLICK_R,
    MOUSE_INACTIVE
} MouseState;

// Camera
#define CAMERA_BASE_X SCREEN_WIDTH / 2
#define CAMERA_BASE_Y SCREEN_HEIGHT / 2
#define CAMERA_BASE_WIDTH SCREEN_WIDTH
#define CAMERA_BASE_HEIGHT SCREEN_HEIGHT
#define CAMERA_BASE_ZOOM 1.0f

#define CAMERA_MOVE_SPEED 300.0f // Pixels per second

typedef enum {
    CAMERA_MODE_FIXED, // Static position
    CAMERA_MODE_FOLLOW, // Attach to entity position
    CAMERA_MODE_FREE // WASD directly controls camera
} CameraMode;

// Entity
typedef enum {
    // Default
    ENTITY_TYPE_NONE,
    // Players, NPCs
    ENTITY_TYPE_CHARACTER,
    // Projectiles
    ENTITY_TYPE_PROJECTILE,
    // Items
    ENTITY_TYPE_ITEM,
    // Text
    ENTITY_TYPE_LABEL,
    // Map Objects
    ENTITY_TYPE_MAP,
    // UI Elements
    ENTITY_TYPE_UI
} EntityType;

// Character
typedef enum {
    CHARACTER_TYPE_PLAYER, // User
    CHARACTER_TYPE_NPC, // Non-Player Character
    CHARACTER_TYPE_ENEMY, // Hostile NPC
    CHARACTER_TYPE_TEAM // Friendly NPC
} CharacterType;

// Projectile
typedef enum {
    PROJECTILE_TYPE_BULLET, // Fast, straight
    PROJECTILE_TYPE_LOB, // Slow, arced/lobbed
    PROJECTILE_TYPE_SPRAY, // Cone
    PROJECTILE_TYPE_BEAM, // Instant, piercing
    PROJECTILE_TYPE_AOE // Area of Effect
} ProjectileType;

// Item
typedef enum {
    ITEM_TYPE_CONSUMABLE, // Health, Mana, etc.
    ITEM_TYPE_EQUIPMENT, // Weapons, Armor, etc.
    ITEM_TYPE_KEY, // Keys for doors, chests, etc.
    ITEM_TYPE_MISC // Miscellaneous
} ItemType;

// Label
typedef enum {
    LABEL_TYPE_TOOLTIP, // Small, contextual
    LABEL_TYPE_DIALOGUE, // Speech bubbles, etc.
    LABEL_TYPE_TITLE, // Large, prominent
    LABEL_TYPE_SUBTITLE // Smaller than title
} LabelType;

// Map
typedef enum {
    MAP_TYPE_FLOOR, // Walkable
    MAP_TYPE_WALL, // Non-Walkable, Solid
    MAP_TYPE_LIQUID, // Water, Lava, etc.
    MAP_TYPE_DECOR, // Non-Solid, purely visual
    MAP_TYPE_HAZARD, // Damaging
    MAP_TYPE_EXIT, // Level Exit
    MAP_TYPE_LOGIC // Triggers, Spawns, etc.
} MapType;

// Map Logic
typedef enum {
    LOGIC_TYPE_TRIGGER, // Activate on condition
    LOGIC_TYPE_SPAWN // Spawn entities
} LogicType;

// UI
typedef enum {
    UI_TYPE_BUTTON, // Clickable
    UI_TYPE_PANEL, // Non-Clickable
    UI_TYPE_TEXT // Text Box
} UIType;

#endif // DEFS_H