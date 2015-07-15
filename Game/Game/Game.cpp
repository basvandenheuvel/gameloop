#include "Game.h"
#include "header_loader.h"
#include <Windows.h>
#include <iostream>


Game::Game()
{
	this->gsm = new GameStateManager();
	this->gsm->init("Bermuda", SCREENWIDTH, SCREENHEIGHT, FULLSCREEN);

	this->loop();
}

void Game::loop()
{
	double TARGET_FPS = 60;
	double OPTIMAL_TIME = 1000 / TARGET_FPS;

	//Instantiate Large Integers
	LARGE_INTEGER frequency; // ticks per second
	LARGE_INTEGER previousTime, currentTime, afterLoopTime; // ticks
	//Set Frequency
	QueryPerformanceFrequency(&frequency);
	//Set Previous Time (for the first time)
	QueryPerformanceCounter(&previousTime);

	//Instantiate FPS variables and set to 0
	float lastFpsTime = 0;
	int fps = 0;
	int gameState = 0;
	while (this->gsm->getRunning()) {
		//Take current Time
		QueryPerformanceCounter(&currentTime);

		//Calculate difference (previousTime - currentTime)
		float updateLength = static_cast<float>((currentTime.QuadPart - previousTime.QuadPart) * 1000) / static_cast<float>(frequency.QuadPart);

		//Previous time = current time
		previousTime = currentTime;
		//Calculate delta
		double delta = updateLength / OPTIMAL_TIME;
		//Add time difference to lastFpsTime
		lastFpsTime += updateLength;
		//Increase FPS since one frame has passed
		fps++;


		//If lastFpsTime > 1000 ms, set FPS to 0 and start re-calculating
		if (lastFpsTime >= 1000) {
			std::cout << fps << std::endl;
			lastFpsTime = 0;
			fps = 0;
		}

		//Set the max on the delta
		if (delta > 4.0) { delta = 4.0; }

		//Handle vents
		//Update stuff
		//Draw stuff
		this->gsm->handleEvents();
		this->gsm->update(delta);
		this->gsm->draw();

		//Get time after loop
		QueryPerformanceCounter(&afterLoopTime);

		//Sleep if needed (if time took longer than optimal)
		if ((((previousTime.QuadPart - afterLoopTime.QuadPart) * 1000.0 / frequency.QuadPart) + OPTIMAL_TIME) > 0) {
			Sleep(static_cast<DWORD>((((previousTime.QuadPart - afterLoopTime.QuadPart) * 1000.0 / frequency.QuadPart) + OPTIMAL_TIME)));
		}
	}
}


Game::~Game()
{
}
