#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>

static int SCREENWIDTH = 1000;
static int SCREENHEIGHT = 400;

static bool FULLSCREEN = false;

static const std::string BASEPATH = SDL_GetBasePath();
static const std::string RESOURCEPATH = BASEPATH + "Resources\\";