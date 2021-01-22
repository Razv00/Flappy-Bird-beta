#include "Map.h"
#include "TextureManager.h"
#include "Turn.h"



Map::Map() {
	map1 = TextureManager::LoadTexture("assets/padure.png");
	map2 = TextureManager::LoadTexture("assets/padure.png");

	SrcMap.x = 0;
	SrcMap.y = 0;
	SrcMap.w = 800;
	SrcMap.h = 620;

	DestMap1.x = 0;
	DestMap1.y = 0;
	DestMap1.w = 800;
	DestMap1.h = 620;

	DestMap2.x = 800;
	DestMap2.y = 0;
	DestMap2.w = 800;
	DestMap2.h = 620;


	//LoadMap(map_0);

	src.x = src.y = 0;
	src.w = dest.w = 64;
	src.h = dest.h = 64;

	dest.x = dest.y = 0;

	origin_x = 0;

	origin_y = 0;
	
	frameStart = SDL_GetTicks();

	contor = 0;
}

Map::~Map() {

}

void Map::Render() {
	TextureManager::Draw(map1, SrcMap,DestMap1);
	TextureManager::Draw(map1, SrcMap, DestMap2);

}

void Map::Update() {
	if (DestMap1.x + DestMap1.w < 0) {
		DestMap1.x += 1600;

	}
	else {
		DestMap1.x -= 4;

	}
	if (DestMap2.x + DestMap2.w < 0) {
		DestMap2.x += 1600;
	}
	else
		DestMap2.x -= 4;

}


/*id Map::DrawMap() {
	
	int type = 0;
	SDL_Rect src_chr,dest_chr;
	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 25; ++j) {
			//type = map[i][j];

			

			dest.x = j * 64 + origin_x;
			dest.y = i * 64 + origin_y;

			
			TextureManager::Draw(map_texture[i][j], src, dest);
			
		}
	}

	frameTime = SDL_GetTicks() - frameStart;
	
	if (50 < frameTime) {
		frameStart = SDL_GetTicks();
		if (contor == 4)
			contor = -1;
		contor++;
	}

	src_chr.x = 150*contor;	
	src_chr.y = 0;
	src_chr.w = 150;
	src_chr.h = 190;
	
	dest_chr.x = (800 - 150) / 2;
	dest_chr.y = (640 - 190) / 2;
	dest_chr.w = 150;
	dest_chr.h = 190;
	
	TextureManager::Draw(map, src_chr, dest_chr);

	




		//SDL_Delay(200 - frameTime);

}
*/
void Map::MoveRight() {
	origin_x -= 4;
}
void Map::MoveLeft() {
	origin_x += 10;
}

void Map::MoveUp() {
	origin_y += 10;
}

void Map::MoveDown() {
	origin_y -= 10;
}