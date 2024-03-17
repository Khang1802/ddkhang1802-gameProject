#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
#include <sdl/SDL.h>
#include <sdl/SDL_image.h>

#include <header/sources.h>
#include <header/object.h>
#include <header/player.h>
#include <header/threat.h>

Object background;
Player p_player;

int x_threat = rand()%1200 + 1;
Threat t_threat(x_threat);

std::vector<Threat> threat_Collection;

bool initSDL()
{
    bool flag = true;
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "SDL initialize failed !" << std::endl;
        flag = false; 
    }
    else 
    {
         window = SDL_CreateWindow("Knight's adventure", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
         if (window == NULL) 
         {
            std::cout << "window initialize failed !" << std::endl;
            flag = false;
         }
         else
         {
             screen = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
             if (screen == NULL)
             {
                std::cout << "Screen initialize failed !" << std::endl;
                flag = false;
             }
            else 
            {
                 SDL_SetRenderDrawColor(screen, RENDER_DRAWW_COLOR, RENDER_DRAWW_COLOR, RENDER_DRAWW_COLOR, RENDER_DRAWW_COLOR);
                 int markflag = IMG_INIT_PNG;
                 if (!IMG_Init(markflag) && markflag)
                 {
                    std::cout << "SDL_Image initialize failed !" << std::endl;
                    flag = false;
                 }
            }
         }
    }
    return flag;
}

bool loadBackground()        // co the cai tien 
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
    p_player.clean();
    t_threat.clean();
    IMG_Quit();
    SDL_Quit();
}

int main(int argc, char* argv[])
{   
    srand(time(0));   //sinh threat tai vi tri ngau nhien
    
    if (initSDL() != true) std::cout << "Initilize failed" << std::endl;           //khoi tao cua so 
    if (loadBackground() != true) std::cout << "Background failed" << std::endl;      //goi background


    if (p_player.loadTexture("res/newsizeknight.png", screen) != true)
    {
        std::cout << "Load player failed!" << std::endl;
    }

    p_player.setvalue_x(0);

    
    if (t_threat.loadTexture("res/threat2.png", screen) != true)
    {
        std::cout << "Load threat failed!" << std::endl;
    }

    int time_count = 0;

    bool is_quit = false;

    
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
        }
            if (time_count % 10 == 0) 
            {
                xchange += 0.025;     //tang toc do cho threat
            }
            if (time_count % 50 == 0)
            {
                int num_threat = rand()%1200+1;
                threat_Collection.push_back(num_threat);
            }
            for (int i = 0; i < threat_Collection.size(); i++)
            {
                threat_Collection[i].createThreat(screen, t_threat, xchange);
            }
            SDL_RenderClear(screen);        //xoa -> nap -> in anh
            background.applyTexture(screen, 0, 0);   //NULL, NULL de in ra toan man hinh (neu gan NULL se co warning -> fixed -> 0, 0)
            p_player.renderPlayer(screen, p_player);
            
            //t_threat.createThreat(screen, t_threat, xchange);

             for (int i = 0; i < threat_Collection.size(); i++)
            {
                threat_Collection[i].createThreat(screen, t_threat, xchange);
            }
            
            SDL_Delay(10);

            time_count += 1;

            SDL_RenderPresent(screen);
            
        
    }


    close();
   return 0;
}



