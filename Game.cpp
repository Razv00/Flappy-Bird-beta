#include "Game.h"

using namespace std;


Game::Game() {
	srand(static_cast<unsigned int>(time(NULL)));
	
}

Game::~Game() {}

void Game::Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	
	
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}
	
	
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		cout << "Sistem initializat" << endl;

		window = SDL_CreateWindow(title,SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		TextureManager::renderer = SDL_CreateRenderer(window, -1, 0);

		if (window) {
			cout << "Fereastra creata" << endl;
		}

		if (TextureManager::renderer) {
			SDL_SetRenderDrawColor(TextureManager::renderer, 255, 0, 0, 255);
			cout << " Render creat" << endl;
		}

		isRunning = 1;
	}
	else
		isRunning = 0;
	 
	
	
	pasare = new Bird("assets/pasare.png", 50, 350);
	turn = new TurnRosu(0);
	turn1 = new Turn(1);
	turn2 = new TurnRosu(2);
	ground = new Ground();
	map = new Map();
	
	
	
}

void Game::HandleEvents() {
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		switch (event.type)
		{
		case SDL_QUIT:
			isRunning = 0;
			break;

		case SDL_KEYDOWN:
		
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				isRunning = 0;
				break;
			case SDLK_LEFT:
				
				map->MoveLeft();
				break;
			case SDLK_RIGHT:
				
				
				break;
			case SDLK_UP:
				
				map->MoveUp();
				break;
			case SDLK_DOWN:
				map->MoveDown();
				break;
			case SDLK_SPACE:
				
				
				break;
			default:
				break;
			}
			break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym) {
			case SDLK_SPACE:
				if (!pasare->IsDead()) {
					pasare->StartJump(0.1);
					
				}
				break;
			}
			
			break;

		case SDL_MOUSEBUTTONUP:
			cout << "Ati ridicat mouse-ul" << endl;
			break;
		
		default:
			
			break;
		}
	}
	
	
}


void Game::Update() {
	
	pasare->UpdateBird();

	if (!pasare->IsDead()) {

		turn->Scor(pasare->GetDestRect());
		points += turn->GetPoints();


		turn1->Scor(pasare->GetDestRect());
		points += turn1->GetPoints();

		turn2->Scor(pasare->GetDestRect());
		points += turn2->GetPoints();

		HighScoreFile();

		turn->Update();
		turn1->Update();
		turn2->Update();
		ground->Update();
		map->Update();


		if (turn->CheckCollision(pasare->GetDestRect()) || ground->CheckCollision(pasare->GetDestRect()))
			pasare->Kill();
		if (turn1->CheckCollision(pasare->GetDestRect()) || ground->CheckCollision(pasare->GetDestRect()))
			pasare->Kill();
		if (turn2->CheckCollision(pasare->GetDestRect()) || ground->CheckCollision(pasare->GetDestRect()))
			pasare->Kill();
		
	}
	

	cout << points << endl;
	

}

void Game::Render() {

	SDL_RenderClear(TextureManager::renderer);
	map->Render();
	
	pasare->Render();
	
	turn->Render();
	turn1->Render();
	turn2->Render();
	ground->Render();

	

	SDL_RenderPresent(TextureManager::renderer);

}

void Game::Clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(TextureManager::renderer);
	SDL_Quit();
	cout << "Final de joc" << endl;
}


void Game::HighScoreFile() {
	std::ifstream readFile;
	readFile.open("assets/Highscore.txt");
	if (readFile.is_open()) {
		while (!readFile.eof()) {
			readFile >> HighScore;
		}
	}
	readFile.close();

	std::ofstream writeFile("assets/Highscore.txt");

	if (writeFile.is_open()) {
		if (points > HighScore)
			HighScore = points;

		writeFile << HighScore;
	}
	writeFile.close();
}