#include "enemy.h"
#include "raymath.h"
Enemy::Enemy(Vector2 pos, Texture2D idleTexture, Texture2D runTexture){
    worldPos = pos;
    texture = idleTexture;
    idle = idleTexture;
    run = runTexture;
    width = texture.width/maxFrames;
    height = texture.height;
    speed = 3.5f;
}

void Enemy::tick(float deltaTime){
    if(!getAlive()) return;
    velocity = Vector2Subtract(target->getScreenPos(), getScreenPos());
    if(Vector2Length(velocity) < radius) velocity = {};
    baseCharacter::tick(deltaTime);
    if(CheckCollisionRecs(target->GetCollisionRec(), GetCollisionRec())) target->takeDamage(DPS * deltaTime);
}
                              

Vector2 Enemy::getScreenPos(){
    return Vector2Subtract(worldPos, target->getWorldPos());
}