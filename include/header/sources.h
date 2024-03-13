#pragma once 

#include <sdl/SDL.h>
#include <sdl/SDL_image.h>
#include <stdio.h>
#include <iostream>

static SDL_Window* window = NULL;
static SDL_Renderer* screen = NULL;
static SDL_Event event;

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 640;
const int SCREEN_BPP = 32;

const int COLOR_KEY_R = 167;
const int COLOR_KEY_G = 175;      //transparency background mau xam
const int COLOR_KEY_B = 180;
const int RENDER_DRAWW_COLOR = 255;

typedef struct Input
{
    int left;
    int right;
    int up;
    int down;
    int jump;
};
