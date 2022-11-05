#include "raylib.h"
#include "character.h"
#include "baseCharacter.h"

class Enemy: public baseCharacter{
    public:
    Enemy(Vector2 pos, Texture2D idleTexture, Texture2D runTexture);
    virtual void tick(float deltaTime) override;
    void setTarget(Character* character){target = character;};
    Vector2 getScreenPos() override;
    private:
    Character* target;
    float DPS{10.f};
    float radius{25.f};
};