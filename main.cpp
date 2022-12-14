#include "raylib.h"
#include "raymath.h"
#include "character.h"
#include "prop.h"
#include "enemy.h"
#include <string>

int main()
{
    // window initialization
    const int windowWidth = 384;
    const int windowHeight = 384;
    InitWindow(windowWidth, windowHeight, "Top-Down Game");
    Texture2D map = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
    Vector2 mapPos{0.f, 0.0f};
    const float mapScale = 4.0f;
    
    Character knight{windowWidth, windowHeight};
    SetTargetFPS(60);
    Enemy goblin{Vector2{0.f, 0.f}, LoadTexture("characters/goblin_idle_spritesheet.png"), LoadTexture("characters/goblin_run_spritesheet.png")};
    Enemy slime{
        Vector2{800.f, 300.f},
        LoadTexture("characters/slime_idle_spritesheet.png"), LoadTexture("characters/slime_run_spritesheet.png")
    };

    Enemy* enemies[]{
        &goblin, &slime
    };
    for(auto enemy: enemies){
        enemy->setTarget(&knight);
    }
    Prop props[2]{
        Prop{Vector2{600.f, 300.f}, LoadTexture("nature_tileset/Rock.png")},
        Prop{Vector2{400.f, 500.f}, LoadTexture("nature_tileset/Log.png")}
    };
    // game loop
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        mapPos = Vector2Scale(knight.getWorldPos(), -1.f);

        DrawTextureEx(map, mapPos, 0.f, 4.f, WHITE);

        for(auto prop: props){
            prop.render(knight.getWorldPos());
        }

        if(!knight.getAlive()){
            DrawText("Game Over!", 55.f, 45.f, 40, RED);
            EndDrawing();
            continue;
        }else{
            std::string knightHealth = "Health: ";
            knightHealth.append(std::to_string(knight.getHealth()),0,5);
            DrawText(knightHealth.c_str(), 55.f, 45.f, 40, RED);
        }

        knight.tick(GetFrameTime());
        if(knight.getWorldPos().x < 0.f ||
           knight.getWorldPos().y < 0.f ||
           knight.getWorldPos().x + windowWidth > map.width * mapScale||
           knight.getWorldPos().y + windowHeight > map.height * mapScale)
           {
            knight.undoMovement();
           }

        for(auto prop : props) if(CheckCollisionRecs(prop.GetCollisionRec(knight.getWorldPos()), knight.GetCollisionRec())) knight.undoMovement(); 
        for(auto enemy : enemies){
            enemy->tick(GetFrameTime());
        }

        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){for(auto enemy: enemies){if(CheckCollisionRecs(enemy->GetCollisionRec(), knight.getWeaponCollisionRec())) enemy->setAlive(false);}}
        EndDrawing();
    }
    UnloadTexture(map);
    CloseWindow();
}
