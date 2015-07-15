#include "PlayState.h"
#include <iostream>


PlayState PlayState::m_PlayState;

PlayState::PlayState()
{
}

void PlayState::init(GameStateManager* gsm)
{
	this->gsm = gsm;

	//Set background rect variables
	this->rectBackground.x = 0;
	this->rectBackground.y = 0;
	this->rectBackground.w = SCREENWIDTH;
	this->rectBackground.h = SCREENHEIGHT;
	//Set background image
	this->textBackground = IMG_LoadTexture(this->gsm->getSDLI()->getRenderer(), (RESOURCEPATH + "play_background.png").c_str());
}

void PlayState::handleEvents(SDL_Event mainEvent)
{
	switch (mainEvent.type)
	{
	case SDL_KEYDOWN:
		switch (mainEvent.key.keysym.sym)
		{
		default:
			break;
		}
		break;
	default:
		break;
	}
}

void PlayState::draw()
{
	//Draw background
	this->gsm->getSDLI()->drawTexture(textBackground, &rectBackground, NULL);
}

void PlayState::update(double dt)
{
}

void PlayState::pause()
{
}

void PlayState::resume()
{
}

void PlayState::cleanup()
{
}

PlayState::~PlayState()
{
}
