#pragma once

#include <sdl/SDL.h>
#include <sdl/SDL_image.h>

class Object
{
public:
    Object();
    ~Object();
    virtual bool loadTexture(std::string path, SDL_Renderer* screen);         //cac ham con co the override 
    void renderTexture(SDL_Renderer* renderer, const SDL_Rect* clip = NULL);
    void setRect(const int &x,const int &y) 
    {
        rect.x = x;
        rect.y = y;
    }
    SDL_Rect getRect() {return rect;}
    SDL_Texture* getObject() {return object;}
    void clean();
protected: //giup ham ke thua thuoc tinh
    SDL_Rect rect;     
    SDL_Texture* object;
};

