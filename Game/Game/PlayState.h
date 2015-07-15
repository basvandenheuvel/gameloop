#pragma once
#include "Header_loader.h"
#include "IGameState.h"
#include "GameStateManager.h"

class PlayState :
	public IGameState
{
private:
	SDL_Rect rectBackground;
	SDL_Texture* textBackground;

public:
	PlayState();
	virtual ~PlayState();


	static PlayState m_PlayState;
	static PlayState* Instance() {
		return &m_PlayState;
	};

	void init(GameStateManager *gsm);

	void pause();
	void resume();
	void handleEvents(SDL_Event mainEvent);
	void update(double dt);
	void draw();
	void cleanup();
};

