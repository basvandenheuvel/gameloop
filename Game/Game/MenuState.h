#pragma once
#include "IGameState.h"
#include "GameStateManager.h"

class MenuState :
	public IGameState
{
public:
	MenuState();
	virtual ~MenuState();

	static MenuState m_MenuState;
	static MenuState* Instance() {
		return &m_MenuState;
	};

	void init(GameStateManager *gsm);
	
	void pause();
	void resume();
	void handleEvents(SDL_Event mainEvent);
	void update(double dt);
	void draw();
	void cleanup();
};

