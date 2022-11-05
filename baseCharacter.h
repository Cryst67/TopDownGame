#ifndef BASECHARACTER_H
#define BASECHARACTER_H

#include "raylib.h"

class baseCharacter{
    public:
    baseCharacter();
    Vector2 getWorldPos() { return worldPos; }
    void undoMovement();
    Rectangle GetCollisionRec();
    virtual void tick(float deltaTime);
    protected:
    Texture2D texture{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D idle{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D run{LoadTexture("characters/knight_run_spritesheet.png")};
    Vector2 screenPos{};
    Vector2 worldPos{};
    Vector2 worldPosLastFrame{};
    float rightLeft{1.f};
    float runningTime{};
    int frame{};
    int maxFrames{6};
    float updateTime{1.f / 12.f};
    float speed{4.f};
    float width{};
    float height{};
    float scale{4.0f};
    private:
};

#endif // BASECHARACTER_H