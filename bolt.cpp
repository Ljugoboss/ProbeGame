#include "bolt.h"
#include "level.h"

void Bolt::act() {
	if (round >= lifetime * getLevel()->FPS / 3) {
		getLevel()->destroyActor(actor_id);
	} else {
		accelerate();
		move();
		draw();
		round++;
	}
}

std::vector<std::vector<SDL_Texture*>> Drawable<Bolt>::animations = std::vector<std::vector<SDL_Texture*>>();
void Bolt::setup() {
	if (animations.empty()) {
		std::vector<SDL_Texture*> animation = std::vector<SDL_Texture*>();
		std::cout << "bitmap created for bolt" << std::endl;
		SDL_Texture * bitmap = createBitmap("C:/Users/Twinmold/Documents/ProbeGame/bolt" + std::to_string(getRotation()) + ".bmp");
		animation.push_back(bitmap);
		animations.push_back(animation);
	}
}