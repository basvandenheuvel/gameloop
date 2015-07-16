#pragma once
#include "Header_loader.h"
#include <SDL_ttf.h>

class SDLInitializer
{
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	TTF_Font* font;

public:
	SDLInitializer();
	virtual ~SDLInitializer();

	void init(const char* title, int width, int height, bool fullscreen);
	void drawTexture(SDL_Texture* texture, const SDL_Rect* destRect, SDL_Rect* crop);
	void drawScreen();
	void clearScreen();

	void drawText(std::string msg, int x, int y, int w, int h, int fontSize = -1, int r = 255, int g = 255, int b = 255);


	SDL_Renderer* getRenderer();
	SDL_Window* getWindow();
};

