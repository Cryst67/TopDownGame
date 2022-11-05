#include "baseCharacter.h"
#include "raymath.h"
baseCharacter::baseCharacter()
{
}

void baseCharacter::undoMovement(){
    worldPos = worldPosLastFrame;
}

Rectangle baseCharacter::GetCollisionRec(){
    return Rectangle{
        getScreenPos().x,
        getScreenPos().y,
        width * scale,
        height * scale
    };
}

void baseCharacter::tick(float deltaTime){
    worldPosLastFrame = worldPos;
    runningTime += deltaTime;
    if (runningTime >= updateTime)
    {
        frame++;
        runningTime = 0.f;
        if (frame > maxFrames)
            frame = 0;
    }
     if (Vector2Length(velocity) != 0.f)
    {
        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(velocity), speed));
        (velocity.x < 0.f) ? rightLeft = -1.f : rightLeft = 1.f;
        texture = run;
    }
    else
    {
        texture = idle;
    }
    velocity = {};
    // draw character
    Rectangle source{frame * width, 0.f, rightLeft * width, height};
    Rectangle dest{getScreenPos().x, getScreenPos().y, scale * width, scale * height};
    DrawTexturePro(texture, source, dest, Vector2{}, 0.f, WHITE);
}