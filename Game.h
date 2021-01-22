#pragma once
#include <SDL.h>
#include "SDL_image.h"
#include <iostream>
#include "GameObject.h"
#include "TextureManager.h"
#include "Bird.h"
#include "Ground.h"
#include "Turn.h"
#include "Map.h"
#include "TurnRosu.h"
#include "Score.h"
#include <chrono>
#include <fstream>


class Game {
protected:
	int contor = 0;
	bool isRunning;
	SDL_Window* window;
	SDL_Texture* textura;
	
	int points = 0;
	int HighScore = 0;
	bool isStarted;
	
	Map* map;
	Bird* pasare;
	TurnRosu* turn;
	Turn* turn1;
	TurnRosu* turn2;
	Ground* ground;
	
	

public:
	
	Game();
	~Game();
	
	void Init(const char* title, int xpos, int ypos , int width, int height, bool fullscreen);

	void HandleEvents();
	void Update();
	void Render();
	void Clean();

	bool Running() {
		return isRunning;
	}
	
	void HighScoreFile();


};