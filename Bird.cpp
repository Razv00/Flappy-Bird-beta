#include <iostream>

#include "Bird.h"
#include "TextureManager.h"

Bird::Bird(const char* texturesheet, int x, int y) :GameObject(texturesheet,x,y) {
	velocity = 0;
	acceleration = 0;
	gravity = 250;
	inaltime = 0;
	ypos2 = 0;
	isDead = false;

}

void Bird::Draw() {

}

void Bird::StartJump(float time) {
	if (isDead)
		return;
	if (jump == false) {
		jump = true;
		acceleration = 0;
		velocity = -gravity / 4.0f;
		this->fElapsedTime = time;
		std::cout << "sari" << std::endl;
		inaltime = ypos;
		
		
	}

	if (acceleration > gravity)
		acceleration = gravity;
}
void Bird::UpdateBird() {
	
	if (jump == true && inaltime - ypos > 30 ) {
		jump = false;
		std::cout << "cobor"<<std::endl;
		acceleration += gravity*fElapsedTime;
	}

	velocity += acceleration *fElapsedTime;
	ypos += velocity*fElapsedTime;
	
	//std::cout << ypos << std::endl;
	
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = 64;
	srcRect.h = 64;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w;
	destRect.h = srcRect.h;

}

