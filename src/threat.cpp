#include <header/threat.h>

Threat::Threat(int x)
{
    rect.x = x;
    rect.y = 0;
    rect.w = width_threat;
    rect.h = height_threat;
}

void Threat::creatThreat(SDL_Renderer* renderer, Threat &threat, int x_val)
{
    threat.applyTexture(renderer, rect.x, rect.y);
    rect.y += x_val;
}

SDL_Rect Threat::getRect()
{
    return rect;
}