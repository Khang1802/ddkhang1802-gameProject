#include <header/treasure.h>
#include <header/sources.h>

Treasure::Treasure()
{
    rect.x = 0;
    rect.y = 0;
    rect.w = width;
    rect.h = height;
}

void Treasure::createTreasure(SDL_Renderer* screen, Treasure &treasure)
{
    treasure.applyTexture(screen, rect.x, rect.y);
    if (rect.y <= 560)
    {
        rect.y += 2;        //roi tu do hehe
    }
}

SDL_Rect Treasure::getRect()
{
    return rect;
}

void Treasure::setInitialPos(int &x)
{
    rect.x = x;
}

void Treasure::setPos()
{
    int x = rand() % (1230-width);
    rect.x = x;
    if (rect.x + width >= SCREEN_WIDTH)
    {
        rect.x -= width; //dich lai treasure neu no bi tran ra man hinh(treasure.width = 40)
    }
    rect.y = 0;

}