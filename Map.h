#pragma once
#include "SDL.h"


class Map {
protected:

	SDL_Rect src, dest;


	SDL_Texture* map1;
	SDL_Texture* map2;

	SDL_Rect SrcMap, DestMap1, DestMap2;

	int origin_x;
	int origin_y;
	
	
	Uint64 frameStart;
	int frameTime;
	int contor;


public:
	Map();
	~Map();

	void Render();
	void Update();

	//void DrawMap();
	void MoveRight();
	void MoveLeft();
	void MoveUp();
	void MoveDown();
};