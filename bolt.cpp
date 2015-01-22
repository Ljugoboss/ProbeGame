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

std::vector<SDL_Texture*> Drawable<Bolt>::images = std::vector<SDL_Texture*>();
std::vector<std::vector<frame>> Drawable<Bolt>::frames = std::vector<std::vector<frame>>();
void Bolt::setup() {
	if (images.empty()) {
		parseXML("C:/Users/Twinmold/Documents/ProbeGame/bolt_animation.xml");
	}
}