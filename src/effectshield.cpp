#include <header/effectshield.h>

Effectshield::Effectshield()
{
    rect.x = 0;
    rect.y = 0;
    rect.w = width;
    rect.h = height;

}

void Effectshield::creatEffect(SDL_Renderer* screen, Effectshield& effectshield, Player& player)
{
    effectshield.applyTexture(screen, player.getRect().x-11, player.getRect().y-15);
}


