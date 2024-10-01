#pragma once
#include "raylib.h"
#include <vector>
#include "Particle.hpp"
#include "UIController.hpp"
#include "time.h"
#pragma endregion

class ParticleController
{
private:
    
    std::vector<Particle> arr;
    std::vector<float> densities;
    UIController UI;

    float magnitude(Vector2 p1, Vector2 p2)
    {
        return std::sqrt(std::pow((p1.x - p2.x), 2) + std::pow((p1.y - p2.y), 2));
    }

    float smoothing_kernel(float radius, float dist)
    {
        float volume = PI * std::pow(radius, 8) / 4;
        float val = std::max(0.0f, radius * radius - dist * dist);
        return val * val * val / volume;
    }

    float calculate_density(Vector2 point)
    {
        float density = 0;
        const float mass = 1000;

        for (Particle p : arr)
        {
            float dist = magnitude(point, p.get_pos());
            if (dist > smoothing_radius)
                continue;
            else
            {
                float inf = smoothing_kernel(smoothing_radius, dist);
                density += mass * inf;
            }
        }
        return density;
    }

public:


    float smoothing_radius = 50;
    float threshold = 0.8;
    ParticleController()
    {
        SetRandomSeed(time(NULL));
    }

    

    void Reset()
    {
        arr.clear();
        densities.clear();
        Populate(1000);
    }

    void Populate(int n)
    {
        for (int i = 0; i < n; i++)
        {
            arr.push_back(Particle(Vector2{(float)GetRandomValue(8, 1912), (float)GetRandomValue(8, 1072)}, 4));
        }

        //for (Particle p : arr)
        //{
        //    densities.push_back(calculate_density(p.get_pos()));
        //}

        for (int i = 0; i < 1920; i += 10)
        {
            for (int j = 0; j < 1080; j += 10)
            {
                Vector2 pos = {i, j};
                densities.push_back(calculate_density(pos));
            }
        }

    }


    
    void Draw()
    {
       for (int i = 0; i < arr.size(); i++)
       {
           //arr[i].Draw();
           
           if (densities[i] > threshold) {

            DrawCircleV(arr[i].get_pos(), 20, Fade(BLUE, 0.01 * densities[i] * densities[i]));
           }
           
       }
       UI.show_fps();
       UI.draw_variables(smoothing_radius);
    }

    void Update()
    {
        for (int i = 0; i < arr.size(); i++)
        {
            densities[i] = calculate_density(arr[i].get_pos());
        }
    }

    void show_density()
    {
        Vector2 pos = GetMousePosition();
        float dent = calculate_density(pos);
        DrawCircleLinesV(pos, smoothing_radius, RAYWHITE);
        DrawText(TextFormat("%f", dent), pos.x, pos.y - 80, 20, GREEN);
    }
};
