#include "raylib.h"
#include "resource_dir.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include "ParticleController.hpp"

int main()
{
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI | FLAG_FULLSCREEN_MODE);
    InitWindow(1920, 1080, "Raylib");
    SearchAndSetResourceDir("resources");
    GuiLoadStyle("style_amber.rgs");
    SetTargetFPS(120);

    ParticleController Engine;
    Engine.Populate(1500);

    while (!WindowShouldClose())
    {
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(BLACK);
        Engine.Draw();
        Engine.Update();
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            Engine.show_density();
        }
        if (IsKeyPressed(KEY_KP_ADD))
        {
            Engine.smoothing_radius += 10;
        }
        if (IsKeyPressed(KEY_KP_SUBTRACT))
        {   
            if (Engine.smoothing_radius != 0)
                Engine.smoothing_radius -= 10;

        }
        if (IsKeyPressed(KEY_R))
        {
            Engine.Reset();
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
