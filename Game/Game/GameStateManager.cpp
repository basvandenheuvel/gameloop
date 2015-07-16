#include "GameStateManager.h"
#include "IGameState.h"
#include "SDLInitializer.h"
#include "MenuState.h"
#include <iostream>


GameStateManager::GameStateManager()
{
}

void GameStateManager::init(const char* title, int width, int height, bool fullscreen)
{
	this->sdlInitializer = new SDLInitializer();
	this->sdlInitializer->init(title, width, height, fullscreen);
	
	//Set menustate
	this->changeGameState(MenuState::Instance());

	this->running = true;
	this->showFps = false;

	//this->rectBackground.x = 100;
	//this->rectBackground.y = 100;
	//this->rectBackground.w = 100;
	//this->rectBackground.h = 100;
	//this->textBackground = IMG_LoadTexture(this->sdlInitializer->getRenderer(), (RESOURCEPATH + "person.jpg").c_str());
}

//Default loop methods
void GameStateManager::handleEvents()
{
	SDL_Event mainEvent;

	while (SDL_PollEvent(&mainEvent))
	{
		switch (mainEvent.type)
		{
		case SDL_QUIT:
			this->quitGame();
			break;
		case SDL_KEYDOWN:
			switch (mainEvent.key.keysym.sym)
			{
			case SDLK_TAB:
				//TODO: toggle show fps
				this->showFps = !this->showFps;
				break;
			default:
				this->states.back()->handleEvents(mainEvent);
				break;
			}
			break;
		//case SDL_KEYUP:
		//	states.back()->handleEvents(mainEvent);
		//	break;
		default:
			this->states.back()->handleEvents(mainEvent);
			break;
		}
	}
}

void GameStateManager::update(double delta)
{	
	this->states.back()->update(delta);
}

void GameStateManager::draw()
{
	//Clear screen
	this->sdlInitializer->clearScreen();
	
	//TEMP
	//this->sdlInitializer->drawTexture(this->textBackground, &this->rectBackground, NULL);

	//Draw current state
	this->states.back()->draw();


	//Draw fps if requested
	if (this->showFps)
	{
		this->sdlInitializer->drawText(std::string("FPS: " + std::to_string(this->fps)), 5, 5, 60, 26, 18, 128, 128, 128);
	}

	//Draw screen
	this->sdlInitializer->drawScreen();
}


//Handle states
void GameStateManager::changeGameState(IGameState* gameState)
{
	while (!this->states.empty()) {
		this->states.back()->cleanup();
		this->states.pop_back();
	}

	this->states.push_back(gameState);
	this->states.back()->init(this);
}

void GameStateManager::pushGameState(IGameState* gameState) 
{
	if (!this->states.empty()) {
		this->states.back()->pause();
	}

	this->states.push_back(gameState);
	this->states.back()->init(this);
}

void GameStateManager::popGameState() 
{
	if (!this->states.empty()) {
		this->states.back()->cleanup();
		this->states.pop_back();
	}

	if (!this->states.empty()) {
		this->states.back()->resume();
	}
}

//Helpers
void GameStateManager::quitGame()
{
	this->running = false;
}

bool GameStateManager::getRunning()
{
	return this->running;
}

SDLInitializer* GameStateManager::getSDLI()
{
	return this->sdlInitializer;
}


void GameStateManager::setFps(int fps)
{
	this->fps = fps;
}

int GameStateManager::getFps()
{
	return this->fps;
}


GameStateManager::~GameStateManager()
{
	//While there are states on the stack, clean them up
	while (!this->states.empty()) {
		//Peek at top state and clean that state
		this->states.back()->cleanup();

		//Remove top state
		this->states.pop_back();
	}

	delete this->sdlInitializer;
}
