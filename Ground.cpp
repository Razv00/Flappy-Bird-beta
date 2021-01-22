#include "Ground.h"


Ground::Ground() {
	ground = TextureManager::LoadTexture("assets/ground.png");
	ground1 = TextureManager::LoadTexture("assets/ground.png");

	SrcGround.x = 0;
	SrcGround.y = 0;
	SrcGround.w = 800;
	SrcGround.h = 20;

	DestGround.x = 0;
	DestGround.y = 600;
	DestGround.w = 800;
	DestGround.h = 20;

	DestGround1.x = 800;
	DestGround1.y = 600;
	DestGround1.w = 800;
	DestGround1.h = 20;

	
}




void Ground::Render() {
	TextureManager::Draw(ground, SrcGround, DestGround);
	TextureManager::Draw(ground1, SrcGround, DestGround1);
}

void Ground::Update() {
	if (DestGround.x + DestGround.w < 0) {
		DestGround.x += 1600;

	}
	else  {
		DestGround.x -= 4;
	
	}
	if (DestGround1.x + DestGround1.w < 0) {
		DestGround1.x += 1600;
	}
	else
		DestGround1.x -= 4;
		

}

bool Ground::CheckCollision(SDL_Rect birdRect) {

	/*if (birdRect.x + birdRect.w > DestTurn1.x && birdRect.x <= DestTurn1.x + DestTurn1.w && birdRect.y <=DestTurn1.y) {
	std::cout << "Am intrat in turnul 1 cu coltul 2" << std::endl;
	isStarted = true;
	}

	else if (birdRect.x + birdRect.w > DestTurn2.x && birdRect.x <= DestTurn2.x + DestTurn2.w && birdRect.y >= DestTurn2.y) {
	std::cout << "Am intrat in turnul 2 " << std::endl;
	isStarted = true;
	}*/

	if (SDL_HasIntersection(&birdRect, &DestGround)) {
		std::cout << "intersectie pamant 1" << std::endl;
		return true;
	}
	if (SDL_HasIntersection(&birdRect, &DestGround1)) {
		std::cout << "intersectie pamant 2" << std::endl;
		return true;
	}

	return false;
}