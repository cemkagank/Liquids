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
    Engine.Populate(2000);
    

    while (!WindowShouldClose())
    {
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
            ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));
            Engine.Draw();
            if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
                Engine.show_density();
            }
            if(IsKeyPressed(KEY_KP_ADD)){
                Engine.smoothing_radius += 10;
            }
            if(IsKeyPressed(KEY_MINUS)) {
                Engine.smoothing_radius -= 10;
            }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}