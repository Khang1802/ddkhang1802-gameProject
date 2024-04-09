#include <header/sources.h>
#include <header/explosion.h>

Explosion::Explosion()
{

}

void Explosion::setclip()
{
    exp_clip[0].x = 0;
    exp_clip[0].y = 0;
    exp_clip[0].w = width;
    exp_clip[0].h = height;

    exp_clip[1].x = width;
    exp_clip[1].y = 0;
    exp_clip[1].w = width;
    exp_clip[1].h = height;

    exp_clip[2].x = 2*width;
    exp_clip[2].y = 0;
    exp_clip[2].w = width;
    exp_clip[2].h = height;

    exp_clip[3].x = 3*width;
    exp_clip[3].y = 0;
    exp_clip[3].w = width;
    exp_clip[3].h = height;

    exp_clip[4].x = 4*width;
    exp_clip[4].y = 0;
    exp_clip[4].w = width;
    exp_clip[4].h = height;
}

void Explosion::showexplosion(SDL_Renderer* screen, Explosion &explosion)
{
    if (frame >= 5)
    {
        frame = 0;
    }
    explosion.applyTexture(screen, rect.x, rect.y, &exp_clip[frame]);
}
