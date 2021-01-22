#include <iostream>

#include <SDL.h>
#include "Game.h"
#include "Turn.h"
#include "TextureManager.h"
#undef main

SDL_Texture* Turn::turn = 0;
SDL_Renderer* TextureManager::renderer = nullptr;
int main(int argc, const char* argv[]) {

	const int fps = 60;
	const int frameDelay = 1000 / fps;


	Uint64 frameStart;
	int frameTime;

	Game* game = nullptr;

	game = new Game();
	
	game->Init("Joc ", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 620, false);

	while (game->Running() ){
	
		frameStart = SDL_GetTicks();

		game->HandleEvents();
		game->Update();
		game->Render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
			SDL_Delay(frameDelay - frameTime);
		//SDL_Delay(1000);

	}
	game->Clean();

	system("Pause");
	return 0;

}



