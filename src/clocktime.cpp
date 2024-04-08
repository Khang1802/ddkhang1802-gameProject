
#include <header/clocktime.h>

Clocktime::Clocktime()
{
    rect.x = 0;
    rect.y = 0;
    rect.w = width;
    rect.h = height;
}

void Clocktime::createClock(SDL_Renderer* screen, Clocktime& clocktime)
{
    clocktime.applyTexture(screen, rect.x, rect.y);
    rect.y += 1;
}

void Clocktime::setClockPos(int &x)
{
    rect.x = x;
    if (rect.x + width > SCREEN_WIDTH)
    {
        rect.x -= 50;
    }
}
//can nhac ve setnewpos
void Clocktime::setNewPos()
{
    int x = rand() % 1230 + 1;
    rect.x = x;
    if (rect.x + width > SCREEN_WIDTH)
    {
        rect.x -= 50;
    }
    rect.y = 0;
}
