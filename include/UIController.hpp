#pragma once
#include "raylib.h"
#pragma endregion

class UIController
{
    int fps;

public:
    UIController() {}

    void show_fps()
    {
        fps = GetFPS();
        DrawText(TextFormat("%i", fps), 20, 20, 20, GREEN);
    }

    void draw_variables(float smoothing_radius)
    {
        
        DrawText(TextFormat("Smoothing Radius: %.0f", smoothing_radius), 20, 60, 20, GREEN);
    }
};