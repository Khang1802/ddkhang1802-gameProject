#include <header/game.h>
#include <sdl/SDL.h>
#include <sdl/SDL_image.h>

Game *game = nullptr;

int main(int argc, char* argv[])
{
   const int FPS = 60;
   const int frameDelay = 1000/FPS;
   Uint32 frameStart;
   int frameTime;

   game = new Game();
   game->init("Knights'adventure", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 600, false);    // co the can chinh lai window trong tuong lai
   while (game->running())
   {
         frameStart = SDL_GetTicks();

         game->handleEvents();
         game->update();
         game->render();

         frameTime = SDL_GetTicks()-frameStart;
         if (frameDelay > frameTime)      //Duy tri su muot ma cho game
         {
            SDL_Delay(frameDelay-frameTime);
         }

   }
   game->clean();
   return 0;
}
