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
    //clean();
    SDL_Texture* newtexture = NULL;
    SDL_Surface* loadsurface = IMG_Load(path.c_str());
    if (loadsurface != NULL)
    {
       // SDL_SetColorKey(loadsurface, SDL_TRUE, SDL_MapRGB(loadsurface->format, COLOR_KEY_R, COLOR_KEY_G, COLOR_KEY_B));  //set ma mau khop voi background
       //do da de anh xoa phong nen chua dung, neu thay loi se refact sau
        newtexture = SDL_CreateTextureFromSurface(screen, loadsurface);
        if (newtexture != NULL)
        {
            rect.w = loadsurface->w;     //lay kich thuoc tam anh
            rect.h = loadsurface->h;
        }
        SDL_FreeSurface(loadsurface);         //khong can toi surface nua
    }
    object = newtexture;
    return object != NULL;
}

void Object::applyTexture(SDL_Renderer* screen, int x, int y, SDL_Rect* clip)
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    offset.w = rect.w;
    offset.h = rect.h;

    if (clip != NULL)
    {
        offset.w = clip->w;
        offset.h = clip->h;
    }
    //can chinh sua them;
    SDL_RenderCopy(screen, object, clip, &offset);
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

bool Object::loadTtf(std::string path, SDL_Renderer* screen, TTF_Font* font, SDL_Color color)
{
    //clean();

    SDL_Surface* loadFont = TTF_RenderText_Solid(font, path.c_str(), color);
    if (loadFont == NULL)
    {
        std::cout << "Unable to render text !" << TTF_GetError() << std::endl;
    }
    else 
    {
        object = SDL_CreateTextureFromSurface(screen, loadFont);
        if (object == NULL)
        {
            std::cout << "Unable to create texture from rendered text !" << SDL_GetError() << std::endl;
        }
        else 
        {
            rect.w = loadFont->w;
            rect.h = loadFont->h;
        }

        //bo old surface di
        SDL_FreeSurface(loadFont);

    }

    return object != NULL;
}
