#include <header/sources.h>
#include <header/object.h>

Object::Object()
{
    rect.x = 0;
    rect.y = 0;
    rect.w = 0;
    rect.h = 0;
    object = NULL;  //khoi tao
}

Object::~Object()
{
    clean();
}

bool Object::loadTexture(std::string path, SDL_Renderer* screen)
{
    SDL_Texture* newtexture = NULL;
    SDL_Surface* loadsurface = IMG_Load(path.c_str());
    if (loadsurface != NULL)
    {
       // SDL_SetColorKey(loadsurface, SDL_TRUE, SDL_MapRGB(loadsurface->format, COLOR_KEY_R, COLOR_KEY_G, COLOR_KEY_B));  //set ma mau khop voi background
        newtexture = SDL_CreateTextureFromSurface(screen, loadsurface);
        if (newtexture != NULL)
        {
            rect.w = loadsurface->w;     //lay kich thuoc tam anh
            rect.h = loadsurface->h;
        }
        SDL_FreeSurface(loadsurface);         //khong can nua
    }
    object = newtexture;
    return object != NULL;
}

void Object::applyTexture(SDL_Renderer* renderer, int x, int y, SDL_Rect* clip)
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    offset.w = rect.w;
    offset.h = rect.h;

    //can chinh sua them;
    SDL_RenderCopy(renderer, object, clip, &offset);
}

void Object::clean()
{
    if (object != NULL)
    {
        SDL_DestroyTexture(object);
        object = NULL;
        rect.w = 0;
        rect.h = 0;
    }
}


