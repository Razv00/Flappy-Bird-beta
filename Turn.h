#pragma once
#include "SDL.h"
#include "GameObject.h"
#include "TextureManager.h"

class Turn :public GameObject {
protected:
	int isStarted;

	SDL_Texture* turn1;
	SDL_Texture* turn2;

	SDL_Rect SrcTurn, DestTurn1, DestTurn2;

	int scor;
	int scor_extras;
public:
	static SDL_Texture* turn;
	Turn();
	Turn(int nr);
	virtual ~Turn() {};
	virtual void Render();
	virtual void MoveTower();
	virtual void Update();
	virtual bool CheckCollision(SDL_Rect birdRect);
	void Scor(SDL_Rect birdRect);
	int GetPoints();

};