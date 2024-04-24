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
#include <header/explosion.h>
#include <header/shield.h>
#include <header/effectshield.h>



Object background;
Player p_player;

int x_threat = rand()%1230 + 1;
Threat t_threat(x_threat);

std::vector<Threat> threat_Collection;

Treasure treasure;

Life life;

//Font
Object Score;
//highscore;
Object kiluc;

//Time
Object Time;

//Clock
Clocktime clocktime;

//menu
Object menu;

//endgame
Object muclucgame;

//explosion
Explosion explosion;

//shield
Shield shield;

//effect shield;
Effectshield effectshield;

//prototype
bool initSDL();
bool loadBackground();   
void close();
int showMenu(Object& anhmenu);
int endMenu(Object& anhmucluc);
    

void recordfile(int highscore)
{
    std::ofstream outfile("highscore.txt", std::ofstream::out|std::ofstream::trunc);
    outfile << highscore;
    outfile.close();
}

int main(int argc, char* argv[])
{   
    srand(time(0));   //sinh seed ngau nhien
    
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
    if (effectshield.loadTexture("res/Shield.png", screen) != true)
    {
        std::cout << "load effectshield failed !" << IMG_GetError() << std::endl;
    }

    //------------------------------------------------------

    if (p_player.loadTexture("res/newsizeknight.png", screen) != true)
    {
        std::cout << "Load player failed!" << IMG_GetError() << std::endl;
    }

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
    if (shield.loadTexture("res/shieldicon.png", screen) != true)
    {
        std::cout << "load shield failed !" << IMG_GetError() << std:: endl;
    }
    
    //------------------------------------------------------
    //load music
    musicgame = Mix_LoadMUS("res/MysticalForest1.wav");
    if (musicgame == NULL)
    {
        std::cout << "musicgame failed !" << Mix_GetError() << std::endl;
    }
    menu_music = Mix_LoadMUS("res/cybercity.wav");
    if (menu_music == NULL)
    {
        std::cout << "musicmenu failed !" << Mix_GetError() << std::endl;

    }
    hittreasure = Mix_LoadWAV("res/hitcoin.wav");
    if (hittreasure == NULL)
    {
        std::cout << "sound effect failed !" << Mix_GetError() << std::endl;
    }
    museff = Mix_LoadWAV("res/hitclock.wav");
    if (museff == NULL)
    {
        std::cout << "sound effect failed !" << Mix_GetError() << std::endl;
    }
    hitbom = Mix_LoadWAV("res/hitbom.wav");
    if (hitbom == NULL)
    {
        std::cout << "sound effect failed !" << Mix_GetError() << std::endl;
    }
    clickchuot = Mix_LoadWAV("res/clickchuot.wav");
    if (clickchuot == NULL)
    {
        std::cout << "sound effect failed !" << Mix_GetError() << std::endl;
    }
    //-----------------------------------------------------
    //load vu no
    if (explosion.loadTexture("res/explimage.png", screen) != true)
    {
        std::cout << "load explosion failed !" << IMG_GetError() << std::endl;
    }
    explosion.setclip();
    //-----------------------------------------------------

    //----------------------------------------------------
    int menugame = showMenu(menu); //show menu 1 lan duy nhat

while (true) //vong lap phu o ngoai thiet lap cac trang thai ve ban dau de restart game
{    

    p_player.setvalue_x(0);

    int time_count = 0;  //phu trach ve time san sinh ra threat 

    xchange = 1; //do thay doi ve toc do cua threat

    bool is_quit = false;

    int count_treasure = 0;

    //---------------
    int shield_pos = rand()%1230+1;
    shield.setShieldpos(shield_pos);
    bool is_shield = false;
    int temp_shield = 0;
    int tgshield = 0;
    //----------------

    int treasure_xval = rand()%1230+1;
    treasure.setInitialPos(treasure_xval);

    int clock_xval = rand()%1230+1;
    clocktime.setClockPos(clock_xval);

   int life_count = 0;
    //load font
    
    font = TTF_OpenFont("res/DungeonFont.ttf", 45);
    life.initLife(screen, life);

   bool stop_threat = false;
   
   bool clock_exist = false;

   int tgngungdong = 0; //co the dung chung cho clocktime va shield

   int index_threat = 100; //respawn threat

   bool gamequit = true;

   int temp_treasure = 0;

   bool shield_effect = false;

   //int endgame = 0;

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
               
                
                if (!Time.loadTtf("Time : " + std::to_string(time_count/60), screen, font, color_white))
                {
                    std::cout << "load time failed " << std::endl;
                }

                if (!kiluc.loadTtf("Best score : " + std::to_string(diemcao), screen, font, color_white))
                {
                    std::cout << "load best score failed " << std::endl;
                }
                
            }

            std::cout << xchange << "   ";
            if (time_count % 1000 == 0 && time_count > 0) 
            {
                    xchange += 0.65;     //tang toc do cho threat
                
            }
            std::cout << index_threat << "   ";
            
            if (time_count % 700 == 0 && time_count > 0)
            {
                if (index_threat >= 40)
                {
                    index_threat -= 5;
                }
            }
            //-----------------------------

            //-----------------------------
            if (time_count % index_threat == 0)     //lam moi threat (can nhac ve do kho cho game)
            {
                if (stop_threat == false)
                {
                     int num_threat = rand()%1230 + 1;
                    
                     while (num_threat >= SCREEN_WIDTH - 50)  
                     {
                         num_threat = rand()%1230 + 1;
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
                temp_treasure += 5;
                temp_shield += 5;
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
            //render ki luc
            kiluc.applyTexture(screen, 10, 50);
            //render time
            Time.applyTexture(screen, SCREEN_WIDTH/2-60, 0);
            //render treasure
            treasure.createTreasure(screen, treasure);
            //clocktime
            if (temp_treasure >= 35 && clock_exist == false)
            {
                clock_exist = true;
                temp_treasure = 0;
            }

            if (clock_exist)
            {
                clocktime.createClock(screen, clocktime);
            }
            //shield function
            if (temp_shield >= 60 && is_shield == false)
            {
                is_shield = true;
                temp_shield = 0;
            }

            if (is_shield && shield_effect == false)
            {
                shield.creatShield(screen, shield);
            }
            
            SDL_Delay(10);
            
            time_count += 1;         //tinh thoi gian

            // check va cham
            for (int i = 0; i < threat_Collection.size(); i++)
            {
                if (checkCollision(threat_Collection[i].getRect(), p_player.getRect()))
                {
                    if (shield_effect == false)
                    {
                        //neu trung bom thi diem tich luy de lay buff se bi reset ve 0;
                        temp_treasure = 0;
                        temp_shield = 0;
                        //---------------------------------
                        if (count_treasure > diemcao)
                            {
                                 diemcao = count_treasure;
                                 recordfile(diemcao);
                            }
                        if (life_count == 2)
                        {
                             is_quit = true;
                        }
                         threat_Collection.clear();   //reset cac threat;
                         treasure.setPos();
                         clocktime.setNewPos();
                         shield.newShield();
                         life_count++;
                         life.decreaseLife();
                         Mix_PlayChannel(-1, hitbom, 0);
                         for (int ex = 0; ex < 5; ex++)
                         {
                             int expos_x = p_player.getRect().x + (p_player.getRect().w)/2 - 95; //dua vu no ve sat voi player
                             int expos_y = p_player.getRect().y + (p_player.getRect().h)/2 - 95;

                              explosion.setframe(ex);
                              explosion.setRect(expos_x, expos_y);
                              explosion.showexplosion(screen, explosion);
                              SDL_Delay(100);
                              SDL_RenderPresent(screen);
                         }
                    }
                    else  //neu dang co shield
                    {
                        threat_Collection.erase(threat_Collection.begin()+i, threat_Collection.begin()+i+1);
                        shield_effect = false;
                        Mix_PlayChannel(-1, museff, 0);
                        SDL_RenderPresent(screen);
                    }

                }
            }

            if (shield_effect == false)
            {
                tgshield = 0;
            }
            if (shield_effect == true)
            {
                if (tgshield >= 2100)
                {
                    shield_effect = false;
                    Mix_PlayChannel(-1, museff, 0);
                }
                tgshield++;
            }


            if (stop_threat == false)
            {
                tgngungdong = 0;
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
                Mix_PlayChannel(-1, museff, 0);
                clocktime.setNewPos();
                clock_exist = false;
            }
            
            if (clocktime.getRect().y >= 718)
            {
                clocktime.setNewPos();       
                clock_exist = false;
            }

            if (checkCollision(shield.getRect(), p_player.getRect()))
            {
                Mix_PlayChannel(-1, museff, 0);
                shield.newShield();
                shield_effect = true;
                is_shield = false;
            }
        
            if (shield_effect)
            {
                effectshield.creatEffect(screen, effectshield, p_player);
            }

            if (shield.getRect().y >= 718)
            {
                shield.newShield();
                is_shield = false;
            }
            
            SDL_RenderPresent(screen);
            std::cout << xchange << "   ";
        }
            is_quit = false;
            
            int endgame = endMenu(muclucgame);
            while (!is_quit)
            {
                while (SDL_PollEvent(&event))
                {
                    if (event.type == SDL_QUIT || endgame == 0)
                    {
                        is_quit = true;
                        //std::cout << "Da thoat hoac da restart thanh cong" << std::endl;
                        break;
                    } 
                    if (endgame == 1) //exit da ok
                    {
                        //std::cout << "Da exit thanh cong" << std::endl;
                        close();
                    }
                SDL_RenderPresent(screen);
                
                }
            
            }    
            
    }
    close();
    return 0;
}
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
///////////////////////////////////////////////////////
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

bool loadBackground()        
{
    if (!background.loadTexture("res/background.png", screen))
    {
        return false;
    }
    return true;
}



void close()
{   //nhung doi tuong sinh ra tu object se free bang ham clean()
    SDL_DestroyRenderer(screen);
    screen = NULL;
    SDL_DestroyWindow(window);
    window = NULL;
    background.clean();
    p_player.clean();
    t_threat.clean();
    clocktime.clean();
    treasure.clean();
    life.clean();
    explosion.clean();
    shield.clean();
    effectshield.clean();
    kiluc.clean();

    for (int i = 0; i < threat_Collection.size(); i++)
    {
        threat_Collection[i].clean();
    }

    TTF_CloseFont(font);

    Mix_FreeMusic(menu_music);
    Mix_FreeMusic(musicgame);

    Mix_FreeChunk(clickchuot);
    Mix_FreeChunk(hitbom);
    Mix_FreeChunk(hittreasure);
    Mix_FreeChunk(museff);

    menu_music = NULL;
    musicgame = NULL;
    clickchuot = NULL;
    hitbom = NULL;
    hittreasure = NULL;
    museff = NULL;

    TTF_Quit();  //free font
    IMG_Quit();
    Mix_Quit();
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
        
        if (Mix_PlayingMusic() == 0)
        {
            Mix_PlayMusic(menu_music, -1);
        }
        
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
                    Mix_PlayChannel(-1, clickchuot, 0);
                    x = event_menu.motion.x;
                    y = event_menu.motion.y;
                    if (x >= menu_pos.x && x <= menu_pos.x+menu_pos.w && y >= menu_pos.y && y <= menu_pos.y+menu_pos.h)
                    {
                        Mix_HaltMusic();
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

int endMenu(Object& anhmucluc)
{
    if (!anhmucluc.loadTexture("res/mucluc.png", screen))
    {
        std::cout << "muc luc load failed!" << std::endl;
    }
    SDL_Rect mucluc_pos[2];
    mucluc_pos[0] = {SCREEN_WIDTH-773,SCREEN_HEIGHT-541,338,84}; //restart
    mucluc_pos[1] = {SCREEN_WIDTH-720, SCREEN_HEIGHT-324,243,81}; //exit
    int x, y;
    SDL_Event event_mucluc;
    while (true)
    {
        if (Mix_PlayingMusic() == 0)
        {
            Mix_PlayMusic(menu_music, -1);
        }
        anhmucluc.applyTexture(screen, 0, 0);
        while (SDL_PollEvent(&event_mucluc))
        {
            switch(event_mucluc.type)
            {
                case SDL_QUIT:
                    close();
                    break;
                case SDL_MOUSEBUTTONDOWN:
                {
                    Mix_PlayChannel(-1, clickchuot, 0);
                    x = event_mucluc.motion.x;
                    y = event_mucluc.motion.y;
                    for (int i = 0; i < 2; i++)
                    {
                        if (x >= mucluc_pos[i].x && x <= mucluc_pos[i].x+mucluc_pos[i].w && y >= mucluc_pos[i].y && y <= mucluc_pos[i].y + mucluc_pos[i].h)
                        {
                            Mix_HaltMusic();
                            return i;
                        }
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