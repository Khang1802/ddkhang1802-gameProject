#include <stdio.h>
#include <iostream>
#include <sdl/SDL.h>
#include <sdl/SDL_image.h>

#include <header/sources.h>
#include <header/object.h>
#include <header/player.h>

Object background;

bool initSDL()
{
    bool flag = true;
    int frame = SDL_Init(SDL_INIT_VIDEO);
    if (frame < 0) return false;
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    window = SDL_CreateWindow("Knights'adventure", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) flag = false;
    else
    {
        screen = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if (screen == NULL)
        {
            flag = false;
        }
        else 
        {
            SDL_SetRenderDrawColor(screen, RENDER_DRAWW_COLOR, RENDER_DRAWW_COLOR, RENDER_DRAWW_COLOR, RENDER_DRAWW_COLOR);
            int markflag = IMG_INIT_PNG;
            if (!IMG_Init(markflag) && markflag)
            {
                flag = false;
            }
        }
    }
    return flag;
}

bool loadBackground()
{
    bool bgimage = background.loadTexture("res/background1.png", screen);
    if (bgimage == false)
    {
        return false;
    }
    return true;
}

void close()
{
    background.clean();
    SDL_DestroyRenderer(screen);
    screen = NULL;
    SDL_DestroyWindow(window);
    window = NULL;
    IMG_Quit();
    SDL_Quit();
}

int main(int argc, char* argv[])
{
    if (initSDL() != true) return -1;           //khoi tao cua so 
    if (loadBackground() != true) return -1;      //goi background

    Player p_player;
    p_player.loadTexture("res/newsizeknight.png", screen);
    bool is_quit = false;

    p_player.setVal(0);

    while (!is_quit)
    {
        while (SDL_PollEvent(&event) != 0)
        {
            if (event.type == SDL_QUIT)
            {
                is_quit = true;
            }
            p_player.handleInputAction(event);
            p_player.handleMove();

            SDL_RenderClear(screen);        //xoa -> nap -> in anh
            background.applyTexture(screen, NULL, NULL);   //NULL, NULL de in ra toan man hinh
            p_player.renderPlayer(screen, p_player);
            SDL_Delay(10);
            
        }
        
        
        


        SDL_RenderPresent(screen);
    }


    close();
   return 0;
}



