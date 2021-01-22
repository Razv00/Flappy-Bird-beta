#pragma once
#include "Turn.h"
#include "GameObject.h"
#include "TextureManager.h"

//aceasta e o clasa dedicata designului turnurilor care poate fi modificata cu orice

class TurnRosu : public Turn {
protected:

public:
	TurnRosu();
	TurnRosu(int nr);
	~TurnRosu();
	
};
