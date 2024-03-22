#pragma once 

#include <sdl/SDL.h>
#include <sdl/SDL_image.h>
#include <sdl/SDL_ttf.h>
#include <sdl/SDL_mixer.h>

#include <stdio.h>
#include <vector>
#include <iostream>

static SDL_Window* window = NULL;
static SDL_Renderer* screen = NULL;      //SDL_Renderer thay cho SDL_Surface
static SDL_Event event;

static TTF_Font* font = NULL;      //khoi tao font 
static SDL_Color color = {255,255,255}; //mau trang

static double xchange = 1; //khoi tao x cho threat

const int SCREEN_WIDTH = 1225;
const int SCREEN_HEIGHT = 717;

const int RENDER_DRAWW_COLOR = 255;   // 255, 255, 255 == white

bool checkCollision(SDL_Rect a, SDL_Rect b);
