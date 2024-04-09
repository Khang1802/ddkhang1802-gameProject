#pragma once

#include "object.h"
#include "sources.h"

class Explosion : public Object
{
    public:
        Explosion();
        static const int width = 184;
        static const int height = 173;
        void setclip();
        void setframe(const int& fr) {frame = fr;}
        void showexplosion(SDL_Renderer* screen, Explosion& explosion);
        void setRect(const int& x, const int& y) {rect.x = x; rect.y = y;}


    private:
        int frame;
        SDL_Rect rect;
        SDL_Rect exp_clip[5];

};