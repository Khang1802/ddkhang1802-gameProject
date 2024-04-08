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
#include <header/life.h>
#include <header/clocktime.h>

Object background;
Player p_player;

int x_threat = rand()%1230 + 1;
Threat t_threat(x_threat);

std::vector<Threat> threat_Collection;

Treasure treasure;

Life life;

//Font
Object Score;

//Time
Object Time;

//Clock
Clocktime clocktime;

//menu
Object menu;

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
                 
                 if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)  //audio se chinh sau
                 {
                    std::cout << "Mixer initialize failed !" << std::endl;
                    flag = false;
                 }
                 
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
{   //nhung doi tuong sinh ra tu object se free bang ham clean()
    background.clean();
    SDL_DestroyRenderer(screen);
    screen = NULL;
    SDL_DestroyWindow(window);
    window = NULL;
    p_player.clean();
    t_threat.clean();

    for (int i = 0; i < threat_Collection.size(); i++)
    {
        threat_Collection[i].clean();
    }

    TTF_CloseFont(font);
    
    TTF_Quit();  //free font
    IMG_Quit();
    SDL_Quit();
}

int showMenu(Object& anhmenu)
{
    if (!anhmenu.loadTexture("res/menu.png", screen))
    {
        std::cout << "cannot load menugame" << std::endl;
    }
    SDL_Rect menu_pos = {745,330,343,47};
    int x, y;
    SDL_Event event_menu;
    while (true)
    {
        anhmenu.applyTexture(screen, 0, 0);
        while (SDL_PollEvent(&event_menu))
        {
            switch(event_menu.type)
            {
                case SDL_QUIT:
                    close();
                    break;
                case SDL_MOUSEBUTTONDOWN:
                {
                    x = event_menu.motion.x;
                    y = event_menu.motion.y;
                    if (x >=745 && x <= 745+343 && y >= 330 && y <= 330+47)
                    {
                        return 0;
                    }
                    break;
                }
                default:
                    break;

            }
        }
        SDL_RenderPresent(screen);
    }
    return 1;
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
    //-----------------------------------------------------

    life.initLife(screen, life);

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
    
    if (clocktime.loadTexture("res/timeclock.png", screen) != true)
    {
        std::cout << "load clock failed !" << IMG_GetError() << std::endl;
    }

    //------------------------------------------------------
    //load font
    
    font = TTF_OpenFont("res/DungeonFont.ttf", 45);
    
    //------------------------------------------------------
    musicgame = Mix_LoadMUS("res/MysticalForest1.wav");
    if (musicgame == NULL)
    {
        std::cout << "musicgame failed !" << Mix_GetError() << std::endl;
    }
    hittreasure = Mix_LoadWAV("res/hitcoin.wav");
    if (hittreasure == NULL)
    {
        std::cout << "sound effect failed !" << Mix_GetError() << std::endl;
    }
    clocksound = Mix_LoadWAV("res/hitclock.wav");
    if (clocksound == NULL)
    {
        std::cout << "sound effect failed !" << Mix_GetError() << std::endl;
    }
    hitbom = Mix_LoadWAV("res/hitbom.wav");
    if (hitbom == NULL)
    {
        std::cout << "sound effect failed !" << Mix_GetError() << std::endl;
    }
    //-----------------------------------------------------
    int time_count = 0;  //phu trach ve time san sinh ra threat 

    bool is_quit = false;

    int count_treasure = 0;
    
    int treasure_xval = rand()%1230+1;
    treasure.setInitialPos(treasure_xval);

    int clock_xval = rand()%1230+1;
    clocktime.setClockPos(clock_xval);

   int life_count = 0;

    //new function
   bool stop_threat = false;
   //bool clock_exist = false;

   bool clock_exist = false;

   int tgngungdong = 0;

   int menugame = showMenu(menu);
   if (menugame == 1)
   {
      is_quit = true;
   }
    is_quit = false;
    while (!is_quit)
    {
        if (Mix_PlayingMusic() == 0)
        {
            Mix_PlayMusic(musicgame, -1);
        }

        while (SDL_PollEvent(&event) != 0)
        {
            if (event.type == SDL_QUIT)
            {
                is_quit = true;
            }
            p_player.handleInputAction(event);
            p_player.handleMove();
        }

            //get time
            Uint32 time_val = SDL_GetTicks()/1000;

            if (font == NULL)
             {
               std::cout << "load font failed" << TTF_GetError() << std::endl;
            }
            else 
            {
                if (!Score.loadTtf("Score : " + std::to_string(count_treasure), screen, font, color_white))
                {
                    std::cout << "load score failed " << std::endl;
                }
                //Lay time_count khong kha thi vi tinh theo ms cua chuong trinh
                
                if (!Time.loadTtf("Time : " + std::to_string(time_val), screen, font, color_white))
                {
                    std::cout << "load time failed " << std::endl;
                }
                
            }

            

            if (count_treasure % 30 == 0 && count_treasure > 0) 
            {
                xchange += 0.005;     //tang toc do cho threat
            }

            if (time_count % 100 == 0)     //lam moi threat (can nhac ve do kho cho game)
            {
                if (stop_threat == false)
                {
                     int num_threat = rand()&1230+1;
                
                     while (num_threat >= SCREEN_WIDTH - 50)  //khong de threat tran ra man hinh
                     {
                         num_threat = rand()%1230+1;
                     }
                
                     threat_Collection.push_back(num_threat);
                }
            }
           


            SDL_RenderClear(screen);        //xoa -> nap -> in anh
            //render background
            background.applyTexture(screen, 0, 0);   //NULL, NULL de in ra toan man hinh (neu gan NULL se co warning -> fixed -> 0, 0)
            
            //render life
            life.createLife(screen, life);

            
            if (checkCollision(p_player.getRect(), treasure.getRect()))
            {
                treasure.setPos();
                Mix_PlayChannel(-1, hittreasure, 0);
                count_treasure += 5;
            }
            
            //render threat
             for (int i = 0; i < threat_Collection.size(); i++)
            {
                threat_Collection[i].createThreat(screen, t_threat, xchange, stop_threat);
            }
            //render player
            p_player.renderPlayer(screen, p_player);
            //render score
            Score.applyTexture(screen, 10, 0);
            //render time
            Time.applyTexture(screen, SCREEN_WIDTH/2-60, 0);
            //render treasure
            treasure.createTreasure(screen, treasure);
            //clocktime
            if (count_treasure % 35 == 0 && count_treasure > 0 && clock_exist == false)
            {
                clock_exist = true;
            }

            if (clock_exist)
            {
                
                clocktime.createClock(screen, clocktime);
            }

            SDL_Delay(10);


            
            time_count += 1;         //tinh thoi gian

            // check va cham
            for (int i = 0; i < threat_Collection.size(); i++)
            {
                if (checkCollision(threat_Collection[i].getRect(), p_player.getRect()))
                {
                    //sau khi bi trung threat=> clear het threat
                    if (life_count == 2)
                    {
                        is_quit = true;
                    }
                    threat_Collection.clear();   //reset cac threat;
                    treasure.setPos();
                    //SDL_RenderClear(screen);     can nhac them
                    life_count++;
                    life.decreaseLife();
                    Mix_PlayChannel(-1, hitbom, 0);

                }
            }

            if (stop_threat == false)
            {
                tgngungdong = 1;
            }

            if (stop_threat == true)
            {
                if (tgngungdong >= 300)
                {
                    stop_threat = false;
                }
                tgngungdong++;
            }

            if (checkCollision(clocktime.getRect(), p_player.getRect()))
            {
                //tinh nang ngung dong thoi gian trong vong 3s;
                stop_threat = true;
                Mix_PlayChannel(-1, clocksound, 0);
                clocktime.setNewPos();
                clock_exist = false;
            }
            std::cout<<clocktime.gettoadoy() << std::endl;
            if (clocktime.gettoadoy() >= 718)
            {
                clocktime.setNewPos();
                clock_exist = false;
            }
            

            SDL_RenderPresent(screen);
        
    }


    close();
   return 0;
}



