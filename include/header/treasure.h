#pragma once

#include "object.h"
#include <sdl/SDL.h>
#include <sdl/SDL_image.h>

class Treasure : public Object
{
    public:
        static const int width = 40;
        static const int height = 46;
        Treasure(int x);
        void createTreasure(SDL_Renderer* renderer, Treasure &treasure);



        SDL_Rect getRect();   
    private:
        SDL_Rect rect;
};