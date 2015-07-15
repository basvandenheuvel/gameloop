#include "MenuState.h"
#include "PlayState.h"
#include <iostream>


MenuState MenuState::m_MenuState;

MenuState::MenuState()
{	
}

void MenuState::init(GameStateManager* gsm)
{
	this->gsm = gsm;
}

void MenuState::handleEvents(SDL_Event mainEvent)
{
	switch (mainEvent.type)
	{
	case SDL_KEYDOWN:
		switch (mainEvent.key.keysym.sym)
		{
		case SDLK_s:
			this->gsm->changeGameState(PlayState::Instance());
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

void MenuState::draw()
{
}

void MenuState::update(double dt)
{
}

void MenuState::pause()
{
}

void MenuState::resume()
{
}

void MenuState::cleanup()
{
}


MenuState::~MenuState()
{
}
