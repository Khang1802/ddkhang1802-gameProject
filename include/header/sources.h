#pragma once 

#include <sdl/SDL.h>
#include <sdl/SDL_image.h>
#include <stdio.h>
#include <vector>
#include <header/threat.h>
#include <iostream>

static SDL_Window* window = NULL;
static SDL_Renderer* screen = NULL;      //SDL_Renderer thay cho SDL_Surface
static SDL_Event event;

static double xchange = 1; //khoi tao gia tri dung chung

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 717;


const int RENDER_DRAWW_COLOR = 255;   // 255, 255, 255 == white

