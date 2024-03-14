#pragma once
#include "sources.h"
#include "object.h"

class Player : public Object
{
public: 
    /*
    Player();
    ~Player();
    

    bool loadImg(std::string path, SDL_Renderer* screen);

    void showScreen(SDL_Renderer* des);

    void handleMove(SDL_Event event, SDL_Renderer* screen);

    void setclip();    //xu ly animation
    */ 

   static const int width = 150;
   static const int height = 137;

    Player();

    void setVal(int x);
    void handleInputAction(SDL_Event &event);
    void handleMove();
    SDL_Rect getRect();
    void renderPlayer(SDL_Renderer* renderer, Object& player);

private:
    /*
    double x_val;
    double y_val;

    double x_pos;
    double y_pos;

    int width_frame;
    int height_frame;

    SDL_Rect frame_clip[8];   //8 anh

    Input input_type;   //bien luu trang thai cua char

    int frame;
    int status;
    */
   int x_val;
   SDL_Rect rect;
};