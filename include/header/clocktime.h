
#pragma once

#include "sources.h"
#include "object.h"

#include <sdl/SDL.h>
#include <sdl/SDL_image.h>

class Clocktime : public Object
{
    public:
        static const int width = 50;
        static const int height = 57;
        Clocktime();
        
        void createClock(SDL_Renderer* screen, Clocktime& clocktime);

        void setClockPos(int &x);

        void setNewPos();

        SDL_Rect getRect(){ return rect;}

        int gettoadoy(){return rect.y;}
    private:
        SDL_Rect rect;
};
