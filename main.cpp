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

    //target fps
    SetTargetFPS(60);

    //game loop
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(WHITE);
        Vector2 direction{};
        if(IsKeyDown(KEY_A)) direction.x -= 1.0; 
        if(IsKeyDown(KEY_D)) direction.x += 1.0;
        if(IsKeyDown(KEY_W)) direction.y -= 1.0;
        if(IsKeyDown(KEY_S)) direction.y += 1.0;

        if(Vector2Length(direction) != 0.0) mapPos = Vector2Subtract(mapPos, Vector2Normalize(direction));

        DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);

        EndDrawing();
    }
    UnloadTexture(map);
    CloseWindow();
}