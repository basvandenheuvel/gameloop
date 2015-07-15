#include "SDLInitializer.h"

SDLInitializer::SDLInitializer()
{
}

void SDLInitializer::init(const char* title, int width, int height, bool fullscreen) 
{
	window = SDL_CreateWindow(
		title,
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		width,
		height,
		fullscreen
		);

	// Set icon
	//SDL_Surface *surface = IMG_Load((RESOURCEPATH + "WindowIco.png").c_str());
	//SDL_SetWindowIcon(window, surface);
	//SDL_FreeSurface(surface);

	renderer = SDL_CreateRenderer(window, -1, 0);
}

void SDLInitializer::drawTexture(SDL_Texture* texture, const SDL_Rect* destRect, SDL_Rect* crop)
{
	SDL_RenderCopy(renderer, texture, crop, destRect);
}

void SDLInitializer::drawScreen() 
{
	SDL_RenderPresent(renderer);
}

void SDLInitializer::clearScreen()
{
	SDL_RenderClear(renderer);
}

SDL_Window* SDLInitializer::getWindow() 
{
	return this->window;
}

SDL_Renderer* SDLInitializer::getRenderer() 
{
	return this->renderer;
}

SDLInitializer::~SDLInitializer()
{
	SDL_DestroyRenderer(this->renderer);
	SDL_DestroyWindow(this->window);
}
