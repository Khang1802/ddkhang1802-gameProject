#include <header/threat.h>
#include <header/sources.h>

Threat::Threat(int x)
{
    rect.x = x;
    rect.y = 0;
    rect.w = width_threat;
    rect.h = height_threat;
}

void Threat::createThreat(SDL_Renderer* screen, Threat &threat, int threatchange, bool stop_threat)
{
    threat.applyTexture(screen, rect.x, rect.y);
    if (stop_threat == false)
    {
        rect.y += threatchange;
    }
}


SDL_Rect Threat::getRect()
{
    return rect;
}
