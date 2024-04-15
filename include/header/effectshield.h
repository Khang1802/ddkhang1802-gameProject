#pragma once

#include "sources.h"
#include "object.h"
#include "shield.h"
#include "player.h"

class Effectshield : public Object
{
    public:
        Effectshield();
        static const int width = 120;
        static const int height = 120;
        void creatEffect(SDL_Renderer* screen, Effectshield& effectshield, Player& player);

    private:
        SDL_Rect rect;

};