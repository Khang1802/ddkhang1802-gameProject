#pragma once

#include <sdl/SDL.h>
#include <sdl/SDL_image.h>
#include <sdl/SDL_ttf.h>

#include <stdlib.h>
#include <iostream>   //de dung std::string

#include <header/sources.h>

class Object
{
public:
    Object();
    ~Object();
    bool loadTexture(std::string path, SDL_Renderer* screen);       

    //font
    bool loadTtf(std::string path, SDL_Renderer* screen, TTF_Font* font, SDL_Color color);

    void applyTexture(SDL_Renderer* renderer, int x, int y, SDL_Rect* clip = NULL);
    void setRect(const int &x,const int &y)      // can xem xet them
    {
        rect.x = x;
        rect.y = y;
    }
    
    SDL_Texture* getObject() {return object;}
    void clean();
private: 
    SDL_Rect rect;     
    SDL_Texture* object;
};

