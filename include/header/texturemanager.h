#pragma once

#include "game.h"

class texturemanager
{
    public:
        static SDL_Texture *LoadTexture(const char *fileName, SDL_Renderer* ren);
};
