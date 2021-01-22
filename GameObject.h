#pragma once
#include "SDL.h"

class GameObject {
protected:
	float xpos;
	float ypos;
	//float velocity;
	//float acceleration;
	//float gravity;
	float fElapsedTime;
	bool jump;
	
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	
	

public:
	GameObject() {};
	GameObject(const char* texturesheet,int x,int y);
	~GameObject() {};

	virtual void Update();
	virtual void Render();
	void HandleEvents();
	
	void MoveRight();
	void MoveLeft();
	void MoveUp();
	void MoveDowm();

	int GetPOsX();
	int GetPOsY();

	void Exit();

	void Tick();
	



};