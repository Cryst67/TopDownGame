#include "raylib.h"

class Prop{
    public:
    Prop(Vector2, Texture2D);
    void render(Vector2);
    Rectangle GetCollisionRec(Vector2);
    private:
    Vector2 worldPos{};
    Texture2D texture{};
    float scale{4.f};
};