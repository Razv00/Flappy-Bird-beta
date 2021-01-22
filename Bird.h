#pragma once
#include "GameObject.h"


class Bird : public GameObject {
protected:

	float velocity;
	float acceleration;
	float gravity;
	
	float ypos2;
	float inaltime;

	//int centre;//centrul cercului pasarii
	float radius;
	bool isDead;


public:
	Bird(const char* texturesheet, int x, int y);

	void Draw();

	//void Draw();
	void StartJump(float time);
	

	void UpdateBird();
	void SetJump1() {
		jump = 1;
	}

	void SetJump0() {
		jump = 0;
	}
	
	SDL_Rect GetDestRect() {
		return destRect;
	}
	bool IsDead(){
		return isDead;
	}
	void Kill() {
		isDead = true;
	}
	
	
};