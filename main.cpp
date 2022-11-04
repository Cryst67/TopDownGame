#include "raylib.h"
#include "raymath.h"
#include "character.h"

int main()
{
    // window initialization
    const int windowWidth = 384;
    const int windowHeight = 384;
    InitWindow(windowWidth, windowHeight, "Top-Down Game");
    Texture2D map = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
    Vector2 mapPos{0.f, 0.0f};
    const float mapScale = 4.0f;
    
    Character knight;
    knight.setScreenPos(windowWidth, windowHeight);
    SetTargetFPS(160);

    // game loop
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        mapPos = Vector2Scale(knight.getWorldPos(), -1.f);

        DrawTextureEx(map, mapPos, 0.f, 4.f, WHITE);
        knight.tick(GetFrameTime());

        if(knight.getWorldPos().x < 0.f ||
           knight.getWorldPos().y < 0.f ||
           knight.getWorldPos().x + windowWidth > map.width * mapScale||
           knight.getWorldPos().y + windowHeight > map.height * mapScale)
           {
            knight.undoMovement();
           }

        EndDrawing();
    }
    UnloadTexture(map);
    CloseWindow();
}
