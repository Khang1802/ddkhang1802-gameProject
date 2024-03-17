#pragma once
#include "sources.h"
#include "object.h"

class Player : public Object
{
public: 
   
   static const int width = 150;            //se dung lai de check va cham voi vat the
   static const int height = 137;

    Player();
    ~Player();

    void setvalue_x(int x);
    void handleInputAction(SDL_Event &event);
    void handleMove();
    SDL_Rect getRect();
    void renderPlayer(SDL_Renderer* renderer, Object& player);

private:
  
   int x_val;          //vi tri ban dau
   SDL_Rect rect;
};