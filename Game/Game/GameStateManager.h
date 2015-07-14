#pragma once
class GameStateManager
{
public:
	GameStateManager();
	virtual ~GameStateManager();

	void update(double delta);
};

