#pragma once

#include "object.h"
#include "player.h"
#include "sources.h"

class Shield : public Object
{
    public:
        Shield();
        static const int width = 60;
        static const int height = 74;
        void creatShield(SDL_Renderer* screen, Shield &shield);

        SDL_Rect getRect() {return rect;}

        void setShieldpos(int &x);
        void newShield();
        void shieldrect(const int& x, const int& y) {rect.x = x; rect.y = y;}

    private:
    SDL_Rect rect;


};

