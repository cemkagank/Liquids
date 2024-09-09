#pragma once
#include "raylib.h"
#include <vector>
#include "Particle.hpp"
#include "time.h"

class ParticleController
{
private:
    std::vector<Particle> arr; 
public:
    float smoothing_radius = 50;
    ParticleController() {
        SetRandomSeed(time(NULL));
    }
   
    void Populate(int n) {
        for (int i = 0; i < n; i++) {
            arr.push_back(Particle( Vector2{ (float)GetRandomValue(8,1912), (float)GetRandomValue(8,1072) } ,4));
        }
    } 

    void Draw() {
        for (Particle i: arr) {
            i.Draw();
        }
    }

    float magnitude(Vector2 p1 , Vector2 p2) {
        return std::sqrt(std::pow((p1.x - p2.x) , 2) + std::pow((p1.y - p2.y),  2));
    }


    float smoothing_kernel(float radius, float dist) {
        float volume = PI * std::pow(radius,8) / 4;
        float val = std::max(0.0f,radius * radius - dist * dist);
        return val * val * val / volume;
    }

    float calculate_density(Vector2 point) {
        float density = 0;
        const float mass = 1000;

        for (Particle p : arr) {
            float dist = magnitude(point , p.get_pos());
            if (dist > smoothing_radius)
                continue;
            else {
            float inf = smoothing_kernel(smoothing_radius, dist);
            density += mass * inf;
            }

        }
        return density;

    }

    void show_density() {
        Vector2 pos = GetMousePosition();
        float dent = calculate_density(pos);
        DrawCircleLinesV(pos,smoothing_radius,RAYWHITE);
        DrawText(TextFormat("%f", dent),pos.x , pos.y - 80, 20,GREEN);
    }



};
