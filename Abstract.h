#pragma once
#include "Game.h"

class Abstract : public Game {
public:
	virtual void Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) = 0;

	virtual void HandleEvents() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Clean() = 0;
	
};