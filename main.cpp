#include "raylib.h"
#include "raymath.h"

int main(){
    // window initialization
    const int windowWidth = 384;
    const int windowHeight = 384;
    InitWindow(windowWidth, windowHeight, "Top-Down Game");

    // load textures
    Texture2D map = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
    Vector2 mapPos{0.f, 0.0f};
    Texture2D knight =  LoadTexture("characters/knight_idle_spritesheet.png");
    Vector2 knightPos{
        (float)windowWidth/2.0f - 4.0f * (0.5f * (float)knight.width/6.0f),
        (float)windowHeight/2.0f - 4.0f * (0.5f * (float)knight.height)
    };
    
    // character speed
    float speed{4.0f};

    //target fps
    SetTargetFPS(60);

    //game loop
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(WHITE);
        Vector2 direction{};
        if(IsKeyDown(KEY_A)) direction.x -= 1.f; 
        if(IsKeyDown(KEY_D)) direction.x += 1.f;
        if(IsKeyDown(KEY_W)) direction.y -= 1.f;
        if(IsKeyDown(KEY_S)) direction.y += 1.f;

        if(Vector2Length(direction) != 0.f) mapPos = Vector2Subtract(mapPos, Vector2Scale(Vector2Normalize(direction), speed));

        //draw map
        DrawTextureEx(map, mapPos, 0.f, 4.f, WHITE);

        //draw character
        Rectangle source{0.f, 0.f, (float)knight.width/6.f, (float)knight.height};
        Rectangle dest{knightPos.x, knightPos.y, 4.f * knight.width/6.f, 4.f * (float)knight.height};
        DrawTexturePro(knight, source, dest, Vector2{}, 0.f, WHITE);

        EndDrawing();
    }
    UnloadTexture(map);
    CloseWindow();
}