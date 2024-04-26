#include <header/life.h>

Life::Life()
{
    number_life = 0;
}

Life::~Life()
{

}

void Life::addPos(const int& xpos)
{
    life_list.push_back(xpos);
}

void Life::createLife(SDL_Renderer* screen, Life& life)
{
    if (number_life == life_list.size())
    {
        for (int i = 0; i < life_list.size(); i++)
        {
            rect.x = life_list[i];
            rect.y = 20;  //cach mep tren  pixel;
            life.applyTexture(screen, rect.x, rect.y);
        }
    }
}

void Life::initLife(SDL_Renderer* screen, Life& life)
{
    life.loadTexture("res/heart.png", screen);
    number_life = 3;  //so mang = 3
    if (life_list.size() > 0)   //dam bao khi replay game
    {
        life_list.clear();
    }
    addPos(SCREEN_WIDTH-80);
    addPos(SCREEN_WIDTH-140);
    addPos(SCREEN_WIDTH-200);
}

void Life::decreaseLife()
{
    number_life--;
    life_list.pop_back();  //loai bo di xpos tai vi tri cuoi cung
}

bool Life::increaseLife()
{
    if (number_life < 3)
    {
        number_life++;
        if (life_list.size() == 1)
        {
            addPos(SCREEN_WIDTH-140);
            return true;
        }
        else if (life_list.size() == 2)
        {
            addPos(SCREEN_WIDTH-200);
            return true;
        }
    }
    return false;
}
