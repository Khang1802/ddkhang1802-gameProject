#include <header/treasure.h>

Treasure::Treasure(int x)
{
    rect.x = x;
    rect.y = 0;
    rect.w = width;
    rect.h = height;
}

void Treasure::createTreasure(SDL_Renderer* renderer, Treasure &treasure)
{
    treasure.applyTexture(renderer, rect.x, rect.y);
    if (rect.y <= 560)
    {
        rect.y += 2;
    }
}

SDL_Rect Treasure::getRect()
{
    return rect;
}