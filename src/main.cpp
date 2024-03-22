#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>

#include <sdl/SDL.h>
#include <sdl/SDL_image.h>
#include <sdl/SDL_mixer.h>
#include <sdl/SDL_ttf.h>

#include <header/sources.h>
#include <header/object.h>
#include <header/player.h>
#include <header/threat.h>
#include <header/treasure.h>

Object background;
Player p_player;

int x_threat = rand()%1225 + 1;
Threat t_threat(x_threat);

std::vector<Threat> threat_Collection;

Treasure treasure;

//Font
Object Score;

bool initSDL()
{
    bool flag = true;
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "SDL initialize failed !" << SDL_GetError() << std::endl;
        flag = false; 
    }
    else 
    {
         window = SDL_CreateWindow("Knight's adventure", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
         if (window == NULL) 
         {
            std::cout << "window initialize failed !" << SDL_GetError() << std::endl;
            flag = false;
         }
         else
         {
             screen = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
             if (screen == NULL)
             {
                std::cout << "Screen initialize failed !" << SDL_GetError() << std::endl;
                flag = false;
             }
            else 
            {
                 SDL_SetRenderDrawColor(screen, RENDER_DRAWW_COLOR, RENDER_DRAWW_COLOR, RENDER_DRAWW_COLOR, RENDER_DRAWW_COLOR);
                 int markflag = IMG_INIT_PNG;
                 if (!IMG_Init(markflag) && markflag)
                 {
                    std::cout << "SDL_Image initialize failed !" << IMG_GetError() << std::endl;
                    flag = false;
                 }
                 //--------------------------------------------
                 if (TTF_Init() == -1)
                 {
                    std::cout << "SDL_ttf initialize failed !" << TTF_GetError() << std::endl;
                    flag = false;
                 }

                 //--------------------------------------------
                 /*
                 if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)  //audio se chinh sau
                 {
                    std::cout << "Mixer initialize failed !" << std::endl;
                    flag = false;
                 }
                 */
            }
         }
    }
    return flag;
}

bool loadBackground()        // co the cai tien 
{
    bool bgimage = background.loadTexture("res/background.png", screen);
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

    TTF_CloseFont(font);
    
    TTF_Quit();  //free font
    IMG_Quit();
    SDL_Quit();
}


int main(int argc, char* argv[])
{   
    srand(time(0));   //sinh threat tai vi tri ngau nhien
    
    if (initSDL() != true) 
    {
        std::cout << "Initilize failed" << std::endl;           //khoi tao cua so 
    }    

    //------------------------------------------------------

    if (loadBackground() != true) 
    {
        std::cout << "Background failed" << IMG_GetError() << std::endl;      //goi background
    }

    //------------------------------------------------------

    if (p_player.loadTexture("res/newsizeknight.png", screen) != true)
    {
        std::cout << "Load player failed!" << IMG_GetError() << std::endl;
    }

    p_player.setvalue_x(0);

    //------------------------------------------------------

    
    if (t_threat.loadTexture("res/bomb.png", screen) != true)
    {
        std::cout << "Load threat failed!" << IMG_GetError() << std::endl;
    }

    //------------------------------------------------------

    if (treasure.loadTexture("res/treasure.png", screen) != true)
    {
        std::cout << "load treasure failed !" << IMG_GetError() << std::endl;
    }

    //------------------------------------------------------
    //load font
    
    
    
    //------------------------------------------------------

    int time_count = 0;

    bool is_quit = false;

    int count_treasure = 0;
    
    int treasure_xval = rand()%1225+1;
    treasure.setInitialPos(treasure_xval);

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
            
            font = TTF_OpenFont("res/DungeonFont.ttf", 45);
            if (font == NULL)
             {
               std::cout << "load font failed" << TTF_GetError() << std::endl;
            }
            else 
            {
                if (!Score.loadTtf("Score : " + std::to_string(count_treasure), screen, font, color))
                {
                    std::cout << "load score failed " << std::endl;
                }
            }


            if (count_treasure % 50 == 0 && count_treasure > 0) 
            {
                xchange += 0.005;     //tang toc do cho threat
            }

            if (time_count % 150 == 0)     //lam moi threat (can nhac ve do kho cho game)
            {
                int num_threat = rand()%1200+1;
                threat_Collection.push_back(num_threat);
            }
           
            SDL_RenderClear(screen);        //xoa -> nap -> in anh
            background.applyTexture(screen, 0, 0);   //NULL, NULL de in ra toan man hinh (neu gan NULL se co warning -> fixed -> 0, 0)
            
            //se can them bien de luu tru treasure;
            if (checkCollision(p_player.getRect(), treasure.getRect()))
            {
                treasure.setPos();
                count_treasure += 5;
            }

             for (int i = 0; i < threat_Collection.size(); i++)
            {
                threat_Collection[i].createThreat(screen, t_threat, xchange);
            }
            
            p_player.renderPlayer(screen, p_player);
            Score.applyTexture(screen, 10, 0);
            treasure.createTreasure(screen, treasure);

            SDL_Delay(10);


            SDL_RenderPresent(screen);
            
            time_count += 1;         //tinh thoi gian

            // check va cham
            for (int i = 0; i < threat_Collection.size(); i++)
            {
                if (checkCollision(threat_Collection[i].getRect(), p_player.getRect()))
                {
                    is_quit = true;
                }
            }
        
    }

    std::cout << count_treasure;

    close();
   return 0;
}



