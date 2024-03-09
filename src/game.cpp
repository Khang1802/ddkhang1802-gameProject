#include <header/game.h>
#include <header/texturemanager.h>
#include <iostream>
#include <sdl/SDL.h>
#include <sdl/SDL_image.h>

SDL_Texture *playertex;
SDL_Rect srcR, destR;

Game::Game()
{
}
Game::~Game(){};

void Game::init(const char* title, int x, int y, int w, int h, bool fullscreen)
{
       int flags = 0;
       if (fullscreen) flags = SDL_WINDOW_FULLSCREEN;
       if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
       {
            std::cout << "Init successfull" << std::endl; 
            window = SDL_CreateWindow(title, x, y, w, h, flags);
            if (window) 
            {
                std::cout << "window created" << std::endl;
            }
            renderer = SDL_CreateRenderer(window, -1, 0);
            if (renderer)
            {
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                std::cout << "renderer created" << std::endl;
            }
            isRunning = true;
       }
       else isRunning = false;
       SDL_Surface *surface = IMG_Load("res/knightimage.png");
       playertex = SDL_CreateTextureFromSurface(renderer, surface);
       SDL_FreeSurface(surface);
}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;
    default:
        break;
    }
}

void Game::update()
{
    cnt++;
    destR.h = 100;
    destR.w = 100;
    destR.x = cnt;
    std::cout << cnt << std::endl;
}

void Game::render()
{
    SDL_RenderClear(renderer);
    //put function here;
    SDL_RenderCopy(renderer, playertex, NULL, &destR);
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned" << std::endl;
}
