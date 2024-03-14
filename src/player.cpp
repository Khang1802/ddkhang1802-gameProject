
#include <header/player.h>

/*
Player::Player()
{
    frame = 0;
    x_pos = 360;
    y_pos = 120;
    x_val = 0;
    y_val = 0;
    width_frame = 0;
    height_frame = 0;
    status = -1;
    input_type.left = 0;
    input_type.right = 0;
    input_type.jump = 0;
    input_type.up = 0;
    input_type.down = 0;
}

Player::~Player(){}

bool Player::loadImg(std::string path, SDL_Renderer* renderer)
{
    bool image = Object::loadTexture(path, screen);
    if (image == true)
    {
        width_frame = rect.w/8;      //kich thuoc chinh xac cua 1 frame 
        height_frame = rect.h;
    }
    return image;
}

void Player::setclip()        //xu ly animation
{
    if (width_frame > 0 && height_frame > 0)
    {
        frame_clip[0].x = 0;      
        frame_clip[0].y = 0;            //bien x thay doi de in ra tung anh
        frame_clip[0].w = width_frame;
        frame_clip[0].h = height_frame;


        frame_clip[1].x = width_frame;      
        frame_clip[1].y = 0;
        frame_clip[1].w = width_frame;
        frame_clip[1].h = height_frame;

        frame_clip[2].x = 2*width_frame;      
        frame_clip[2].y = 0;
        frame_clip[2].w = width_frame;
        frame_clip[2].h = height_frame;

        frame_clip[3].x = 3*width_frame;      
        frame_clip[3].y = 0;
        frame_clip[3].w = width_frame;
        frame_clip[3].h = height_frame;

        frame_clip[4].x = 4*width_frame;      
        frame_clip[4].y = 0;
        frame_clip[4].w = width_frame;
        frame_clip[4].h = height_frame;

        frame_clip[5].x = 5*width_frame;      
        frame_clip[5].y = 0;
        frame_clip[5].w = width_frame;
        frame_clip[5].h = height_frame;

        frame_clip[6].x = 6*width_frame;      
        frame_clip[6].y = 0;
        frame_clip[6].w = width_frame;
        frame_clip[6].h = height_frame;

        frame_clip[7].x = 7*width_frame;      
        frame_clip[7].y = 0;
        frame_clip[7].w = width_frame;
        frame_clip[7].h = height_frame;
    }
}

void Player::showScreen(SDL_Renderer* des)      //2 trang thai quay trai hoac phai 
{
    /*
    if (status == WALK_LEFT)
    {
        loadImg("res/turnleft.jpg", des);
    }

    else 
    {   
        loadImg("res/turnright.jpg", des);
    }
    if (input_type.left == 1 || input_type.right == 1)
    {
        frame++;
    }
    else 
    {
        frame = 0;   //dang dung yen;
    }
    if (frame >= 8) 
    {
        frame = 0;
    }

    rect.x = x_pos;   //vi tri hien thi nhan vat
    rect.y = y_pos;

    SDL_Rect* current_clip = &frame_clip[frame];

    SDL_Rect renderQuad = {rect.x, rect.y, width_frame, height_frame};   //toa do 

    SDL_RenderCopy(des, object, current_clip, &renderQuad);
}

void Player::handleMove(SDL_Event event, SDL_Renderer* screen)
{
    /*
    if (event.type == SDL_KEYDOWN)
    {
        switch (event.key.keysym.sym)
        {
            case SDLK_RIGHT:
            {
                status = WALK_RIGHT;
                input_type.right = 1;
                input_type.left = 0;
                
            }
                break;
            case SDLK_LEFT:
            {
                status = WALK_LEFT;
                input_type.left = 1;
                input_type.right = 0;
            }
                break;
            default :
                break;
        }
    }
    else if (event.type == SDL_KEYUP)
    {
        switch (event.key.keysym.sym)
        {
            case SDLK_RIGHT:
            {

                input_type.right = 0;
            }
                break;
            case SDLK_LEFT:
            {
                
                input_type.left = 0;
            }
                break;
        }
    }
    
}
*/

Player::Player()
{
    x_val = 0;
   // rect = {0, 450, width, height};
    rect.x = 0;
    rect.y = 450;
    rect.w = width; 
    rect.h = height;
}

SDL_Rect Player::getRect()
{
    return rect;
}

void Player::handleInputAction(SDL_Event &event)
{
    if (event.type == SDL_KEYDOWN && event.key.repeat == 0)    //luc nhan phim
    {
        switch (event.key.keysym.sym)
        {
            case SDLK_RIGHT:
                x_val += 50;
                break;
            case SDLK_LEFT:
                x_val -= 50;
                break;
            default:
                break;
        }
    }
    else if (event.type == SDL_KEYUP && event.key.repeat == 0)       //luc nha phim thi phai tru di gia tri
    {
        switch (event.key.keysym.sym)
        {
            case SDLK_RIGHT:
                x_val -= 50;
                break;
            case SDLK_LEFT:
                x_val += 50;
                break;
            default:
                break;
        }
    }
}

void Player::renderPlayer(SDL_Renderer* renderer, Object &player)
{
    player.applyTexture(renderer, rect.x, rect.y);
}

void Player::handleMove()
{
    rect.x += x_val;
    //can chinh sua
}

void Player::setVal(int x)
{
    x_val = x;
}