#pragma once
#include "raylib.h"

class Particle {
    Vector2 pos;
    Vector2 vel;
    float radius;

public:
    Particle(Vector2 pos , float radius ) {
        this->pos = pos;
        this->radius = radius;
    }

    Vector2 get_pos() {
        return pos;
    }

    void Draw() {
        DrawCircle(pos.x , pos.y, 4 , BLUE);
    }

};
