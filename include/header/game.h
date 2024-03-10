#pragma once

#include <iostream>
#include <sdl/SDL.h>
#include <sdl/SDL_image.h>



class Game
{
    public :
        Game();
        ~Game();
        void init(const char* title, int x, int y, int w, int h, bool fullscreen);
        void handleEvents();
        void update();
        void render();
        void clean();
        bool running() {return isRunning;}
    private:
        int tempx = 0;
        int tempy = 0;
        bool isRunning;
        SDL_Window *window;
        SDL_Renderer *renderer;
};

