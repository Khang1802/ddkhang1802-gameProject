#pragma once

#include "object.h"
#include "sources.h"

#include <sdl/SDL.h>
#include <sdl/SDL_image.h>

class Treasure : public Object
{
    public:
        static const int width = 40;
        static const int height = 46;
        Treasure();
        void createTreasure(SDL_Renderer* screen, Treasure &treasure);

        void setInitialPos(int &x);

        void setPos();

        SDL_Rect getRect();   
    private:
        SDL_Rect rect;
};