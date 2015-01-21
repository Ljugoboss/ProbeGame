#include "player.h"
#include "level.h"

void Player::act() {
	accelerate();
	move();
	draw();
}


std::vector<std::vector<SDL_Texture*>> Drawable<Player>::animations = std::vector<std::vector<SDL_Texture*>>();
void Player::setup() {
	if (animations.empty()) {
		std::vector<SDL_Texture*> animation = std::vector<SDL_Texture*>();
		std::cout << "bitmap created for player" << std::endl;
		SDL_Texture * bitmap = createBitmap("C:/Users/Twinmold/Documents/ProbeGame/ProbeMain.bmp");
		for (int i = 0; i < getLevel()->FPS / 3; i++) {
			animation.push_back(bitmap);
		}
		bitmap = createBitmap("C:/Users/Twinmold/Documents/ProbeGame/ProbeMain1.bmp");
		for (int i = 0; i < getLevel()->FPS / 3; i++) {
			animation.push_back(bitmap);
		}
		bitmap = createBitmap("C:/Users/Twinmold/Documents/ProbeGame/ProbeMain2.bmp");
		for (int i = 0; i < getLevel()->FPS / 3; i++) {
			animation.push_back(bitmap);
		}
		bitmap = createBitmap("C:/Users/Twinmold/Documents/ProbeGame/ProbeMain1.bmp");
		for (int i = 0; i < getLevel()->FPS / 3; i++) {
			animation.push_back(bitmap);
		}
		bitmap = createBitmap("C:/Users/Twinmold/Documents/ProbeGame/ProbeMain.bmp");
		for (int i = 0; i < getLevel()->FPS / 3; i++) {
			animation.push_back(bitmap);
		}
		bitmap = createBitmap("C:/Users/Twinmold/Documents/ProbeGame/ProbeMain3.bmp");
		for (int i = 0; i < getLevel()->FPS / 3; i++) {
			animation.push_back(bitmap);
		}
		bitmap = createBitmap("C:/Users/Twinmold/Documents/ProbeGame/ProbeMain4.bmp");
		for (int i = 0; i < getLevel()->FPS / 3; i++) {
			animation.push_back(bitmap);
		}
		bitmap = createBitmap("C:/Users/Twinmold/Documents/ProbeGame/ProbeMain3.bmp");
		for (int i = 0; i < getLevel()->FPS / 3; i++) {
			animation.push_back(bitmap);
		}
		animations.push_back(animation);
	}
}
