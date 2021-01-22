#pragma once
#include <iostream>
#include "TextureManager.h"
#include "GameObject.h"


class Ground:public GameObject {
protected:
	SDL_Texture* ground;
	SDL_Texture* ground1;
	SDL_Rect SrcGround, DestGround,DestGround1;
	
public:
	Ground();
	~Ground();
	void Render();
	void Update();
	bool CheckCollision(SDL_Rect birdRect);
};