#pragma once 

#include <sdl/SDL.h>
#include <sdl/SDL_image.h>
#include <sdl/SDL_ttf.h>
#include <sdl/SDL_mixer.h>

#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>

static SDL_Window* window = NULL;
static SDL_Renderer* screen = NULL;      //SDL_Renderer thay cho SDL_Surface
static SDL_Event event;

static TTF_Font* font = NULL;      //khoi tao font 
static SDL_Color color_white = {255,255,255}; //mau trang

static double xchange = 1; //khoi tao x cho threat

const int SCREEN_WIDTH = 1230;
const int SCREEN_HEIGHT = 718;

const int RENDER_DRAWW_COLOR = 255;   // 255, 255, 255 == white

static Mix_Chunk* hittreasure = NULL;
static Mix_Chunk* museff = NULL;
static Mix_Chunk* hitbom = NULL;
static Mix_Chunk* clickchuot = NULL;
static Mix_Music* musicgame = NULL;
static Mix_Music* menu_music = NULL;

static int diemcao = 0;

bool checkCollision(SDL_Rect a, SDL_Rect b);








