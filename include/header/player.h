#pragma once
#include "sources.h"
#include "object.h"

class Player : public Object
{
public: 
    Player();
    ~Player();

    enum walkType
    {
        WALK_RIGHT = 0,
        WALK_LEFT = 1,
    };

    bool loadImg(std::string path, SDL_Renderer* screen);

    void showScreen(SDL_Renderer* des);

    void handleMove(SDL_Event event, SDL_Renderer* screen);

    void setclip();    //xu ly animation
private:
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
};