#include <iostream>
#include "Turn.h"
#include "TextureManager.h"

using namespace std;

Turn::Turn() {
	

	SrcTurn.x = 0;
	SrcTurn.y = 0;
	SrcTurn.w = 100;
	SrcTurn.h = 100;


	DestTurn1.x = 500;
	DestTurn1.y = 0;
	DestTurn1.w = 100;
	DestTurn1.h = 200;

	DestTurn2.x = 500;
	DestTurn2.y = 400;
	DestTurn2.w = 100;
	DestTurn2.h = 200;


	

}

Turn::Turn(int nr)  {
	
	turn1 = TextureManager::LoadTexture("assets/patrat.png");

	turn2 = TextureManager::LoadTexture("assets/patrat.png");

	SrcTurn.x = 0;
	SrcTurn.y = 0;
	SrcTurn.w = 100;	
	SrcTurn.h = 100;


	DestTurn1.x = 500 + nr*300 ;
	DestTurn1.y = 0;
	DestTurn1.w = 100;
	DestTurn1.h = 175;

	DestTurn2.x = DestTurn1.x;
	DestTurn2.y = 400;
	DestTurn2.w = 100;
	DestTurn2.h = 175;

	
	isStarted = true;
	scor = 0;
	scor_extras = 0;
}

void Turn::Render() {

	TextureManager::Draw(turn1, SrcTurn, DestTurn1);
	TextureManager::Draw(turn2, SrcTurn, DestTurn2);
	
}

void Turn::MoveTower() {
	DestTurn1.x -= 4;
	DestTurn2.x -= 4;
}

void Turn::Update() {
	
	if (DestTurn1.x + DestTurn1.w <= 0) {
		DestTurn1.y = rand()%200;
		DestTurn2.y = DestTurn1.y + 400;
		DestTurn1.x += 900;
		DestTurn2.x = DestTurn1.x;
		scor = 0;
		scor_extras = 0;

	}
	else {
		DestTurn1.x -= 4;
		DestTurn2.x -= 4;
	}
	
}


bool Turn::CheckCollision(SDL_Rect birdRect) {

	/*if (birdRect.x + birdRect.w > DestTurn1.x && birdRect.x <= DestTurn1.x + DestTurn1.w && birdRect.y <=DestTurn1.y) {
		std::cout << "Am intrat in turnul 1 cu coltul 2" << std::endl;
		isStarted = true;
	}
		
	else if (birdRect.x + birdRect.w > DestTurn2.x && birdRect.x <= DestTurn2.x + DestTurn2.w && birdRect.y >= DestTurn2.y) {
		std::cout << "Am intrat in turnul 2 " << std::endl;
		isStarted = true;
	}*/

	if (SDL_HasIntersection(&birdRect, &DestTurn1)) {
		std::cout << "intersectie 1" << std::endl;
		return true;
	}
	if (SDL_HasIntersection(&birdRect, &DestTurn2)) {
		std::cout << "intersectie 2" << std::endl;
		return true;
	}

	return false;
}


void Turn::Scor(SDL_Rect birdRect) {
	
		if (birdRect.x + birdRect.w > DestTurn1.x) {
			if (scor == 0) {
				scor = 1;
				scor_extras = 0;
			}
		}
	
	}
	
	

int Turn::GetPoints() {
	if (scor_extras == 0 && scor == 1) {
		scor_extras = 1;
		return 1;
	}
	return 0;
}