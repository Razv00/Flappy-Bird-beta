#include <iostream>

#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* texturesheet,int x,int y) {

	objTexture = NULL;
	objTexture = TextureManager::LoadTexture(texturesheet);


	xpos = x;
	ypos = y;


	fElapsedTime = 0;

	jump = 0;
}

void GameObject::Render() {
	SDL_RenderCopy(TextureManager::renderer, objTexture, &srcRect, &destRect);
	
}

void GameObject::Update() {
	destRect.x -= 4;
	
}
void GameObject::HandleEvents(){
	
	//auto oldTick = SDL_GetTicks();

	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		switch (event.type)
		{
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_LEFT:
				std::cout << "Stanga" << std::endl;
			
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}

	
}


void GameObject::MoveRight() {
	xpos -= 10;
}
void GameObject::MoveLeft() {
	xpos += 10;
}
void GameObject::MoveUp() {
	ypos -= 10;
}
void GameObject::MoveDowm() {
	ypos += 10;
}

int GameObject::GetPOsX() {
	return xpos;
}
int GameObject::GetPOsY() {
	return ypos;
}
