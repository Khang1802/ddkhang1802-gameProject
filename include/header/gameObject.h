#pragma once

#include "game.h"

class GameObject 
{
    private:
        int xpos, ypos;
        SDL_Texture* objTexture;
        SDL_Rect srcRect, destRect;
        SDL_Renderer* renderer;


    public: 
        GameObject(const char* texturesheet, SDL_Renderer* ren);
        
};