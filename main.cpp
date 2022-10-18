#include "raylib.h"
#include "raymath.h"

int main(){
    // window initialization
    const int windowWidth = 384;
    const int windowHeight = 384;
    InitWindow(windowWidth, windowHeight, "Top-Down Game");

    // load texture
    Texture2D map = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
    Vector2 mapPos = {0.0, 0.0};

    // character speed

    //target fps
    SetTargetFPS(60);

    //game loop
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(WHITE);
        
        DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);

        EndDrawing();
    }
    UnloadTexture(map);
    CloseWindow();
}