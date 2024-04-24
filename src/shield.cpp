#include <header/shield.h>

Shield::Shield()
{
    rect.x = 0;
    rect.y = 0;
    rect.w = width;
    rect.h = height;
}

void Shield::creatShield(SDL_Renderer* screen, Shield &shield)
{
    shield.applyTexture(screen, rect.x, rect.y);
    rect.y += 1;
}

void Shield::setShieldpos(int &x)
{
    rect.x = x;
}   

void Shield::newShield()
{
    int x = rand() % 1230 + 1;
    rect.x = x;
    if (rect.x + width >= SCREEN_WIDTH)
    {
        rect.x -= width; 
    }
    rect.y = 0;
}

