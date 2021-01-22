#pragma once
#include "SDL.h"
#include "SDL_image.h"

class TextureManager {
protected:
	
public:
	static SDL_Renderer* renderer;
	static SDL_Texture* LoadTexture(const char* texture);
	
	static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
};