#pragma once

#include "object.h"
#include "sources.h"
#include <sdl/SDL.h>
#include <sdl/SDL_image.h>

class Threat : public Object
{
    public:
           static const int width_threat = 120;
           static const int height_threat = 120;
           Threat(int x);
           void creatThreat(SDL_Renderer* renderer, Threat& threat, int x_val); 
           
           SDL_Rect getRect();
    private:
           SDL_Rect rect;
};