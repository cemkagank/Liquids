#pragma once 
#include "raylib.h"

class UIController {
    int fps;

public:
    UIController (){}

    void show_fps() {
        fps = GetFPS();
        DrawText(TextFormat("%i", fps),20,20, 20, RAYWHITE);
    }

};