#include "TurnRosu.h"
#include <iostream>
TurnRosu::TurnRosu() {

}

TurnRosu::TurnRosu(int nr):Turn(nr) {
	turn1 = TextureManager::LoadTexture("assets/patrat-rosu.png");
	turn2 = TextureManager::LoadTexture("assets/patrat-rosu.png");
	
}

TurnRosu::~TurnRosu() {}