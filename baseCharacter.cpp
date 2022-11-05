#include "baseCharacter.h"

baseCharacter::baseCharacter()
{
}

void baseCharacter::undoMovement(){
    worldPos = worldPosLastFrame;
}

Rectangle baseCharacter::GetCollisionRec(){
    return Rectangle{
        screenPos.x,
        screenPos.y,
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
    // draw character
    Rectangle source{frame * width, 0.f, rightLeft * width, height};
    Rectangle dest{screenPos.x, screenPos.y, scale * width, scale * height};
    DrawTexturePro(texture, source, dest, Vector2{}, 0.f, WHITE);
}