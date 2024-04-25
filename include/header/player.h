#pragma once

#include "sources.h"
#include "object.h"


class Player : public Object
{
public: 
   
   static const int width = 98;            //se dung lai de check va cham voi vat the
   static const int height = 91;

    Player();
    ~Player();

    void setvalue_x(int x);
    void handleInputAction(SDL_Event &event);
    void handleMove();
    SDL_Rect getRect();           //dua get rct vao object
    void renderPlayer(SDL_Renderer* screen, Player& player);

private:
  
   int x_val;
   SDL_Rect rect;
};