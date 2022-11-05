#ifndef CHARACTER_H
#define CHARACTER_H

#include "raylib.h"
#include "baseCharacter.h"

class Character : public baseCharacter
{

public:
    Character(int winWidth, int winHeight);
    virtual void tick(float deltaTime) override;
    Vector2 getScreenPos() override;
    float getHealth() const {return health;}
    Rectangle getWeaponCollisionRec() { return WeaponCollisionRec; }
    void takeDamage(float damage);
private:
    int windowWidth{};
    int windowHeight{};
    Texture2D weapon{LoadTexture("characters/weapon_sword.png")};
    Rectangle WeaponCollisionRec{};
    float health{100.f};
};

#endif // CHARACTER_H