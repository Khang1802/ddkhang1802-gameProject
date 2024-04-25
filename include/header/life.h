#pragma once

#include "sources.h"
#include "object.h"

class Life : public Object
{
    public:
        Life();
        ~Life();
        //void setNum(const int& num) {number_life = num;}
        void addPos(const int& xpos);
        void createLife(SDL_Renderer* screen, Life& life);
        void initLife(SDL_Renderer* screen, Life& life);


        void decreaseLife();
        
        //void increaseLife();

    private:
        int number_life;
        std::vector<int> life_list;
        SDL_Rect rect;
};