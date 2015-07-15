#pragma once
#include "Header_loader.h"

class SDLInitializer
{
private:
	SDL_Window* window;
	SDL_Renderer* renderer;

public:
	SDLInitializer();
	virtual ~SDLInitializer();

	void init(const char* title, int width, int height, bool fullscreen);
	void drawTexture(SDL_Texture* texture, const SDL_Rect* destRect, SDL_Rect* crop);
	void drawScreen();
	void clearScreen();

	SDL_Renderer* getRenderer();
	SDL_Window* getWindow();
};

