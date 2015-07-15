#pragma once
#include "header_loader.h"
#include "SDLInitializer.h"
#include <vector>

class IGameState;

class GameStateManager
{
private:
	bool running;
	std::vector<IGameState*> states;

	SDLInitializer* sdlInitializer;

	//SDL_Rect rectBackground;
	//SDL_Texture* textBackground;
public:
	GameStateManager();
	virtual ~GameStateManager();
	
	void init(const char* title, int width, int height, bool fullscreen);
	void update(double delta);
	void handleEvents();
	void draw();

	void changeGameState(IGameState* gameState);
	void pushGameState(IGameState* gameState);
	void popGameState();

	void quitGame();

	bool getRunning();
	SDLInitializer* getSDLI();
};

