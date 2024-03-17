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
           void createThreat(SDL_Renderer* renderer, Threat& threat, int xchange); 
           
           SDL_Rect getRect();
    private:
           SDL_Rect rect;
};