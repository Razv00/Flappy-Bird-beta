#include <iostream>
#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* texture) {
	SDL_Surface* tmpSurface = IMG_Load(texture);
	try {
		if (tmpSurface)
			std::cout << "Imagini deschise" << std::endl;
		else
			throw(tmpSurface);
	}
	catch (SDL_Surface* image) {
		std::printf("IMG_Load: %s\n", IMG_GetError());
		

	}	
		// handle error
	SDL_Texture* tex = SDL_CreateTextureFromSurface(TextureManager::renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);

	return tex;
}


void TextureManager::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest) {
	if (tex != nullptr) {
		SDL_RenderCopy(TextureManager::renderer, tex, &src, &dest);
	}
	
	
}