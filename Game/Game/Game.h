#pragma once
#include "GameStateManager.h"

class Game
{
private:
	bool running;
	GameStateManager* gsm;
public:
	Game();
	virtual ~Game();

	void loop();
};

