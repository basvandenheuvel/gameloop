#pragma once
#include "GameStateManager.h"

class Game
{
private:
	GameStateManager* gsm;
public:
	Game();
	virtual ~Game();

	void loop();
};

