
#include <header/player.h>


Player::Player()
{
    x_val = 0;
   // rect = {0, 450, width, height};
    rect.x = 0;
    rect.y = 450;
    rect.w = width; 
    rect.h = height;
}

Player::~Player()
{
    clean();
}

SDL_Rect Player::getRect()  
{
    return rect;
}

void Player::handleInputAction(SDL_Event &event)
{
    if (event.type == SDL_KEYDOWN && event.key.repeat == 0)    //luc nhan phim
    {
        switch (event.key.keysym.sym)
        {
            case SDLK_RIGHT:
                x_val += 50;
                break;
            case SDLK_LEFT:
                x_val -= 50;
                break;
            default:
                break;
        }
    }
    else if (event.type == SDL_KEYUP && event.key.repeat == 0)       //luc nha phim thi phai tru di gia tri
    {
        switch (event.key.keysym.sym)
        {
            case SDLK_RIGHT:
                x_val -= 50;
                break;
            case SDLK_LEFT:
                x_val += 50;
                break;
            default:
                break;
        }
    }
}

void Player::renderPlayer(SDL_Renderer* renderer, Object &player)
{
    player.applyTexture(renderer, rect.x, rect.y);
}

void Player::handleMove()
{
    rect.x += x_val;
    //can chinh sua
    if (rect.x < 0 || rect.x + width > SCREEN_WIDTH)
        rect.x -= x_val;
}

void Player::setvalue_x(int x)
{
    x_val = x;
}