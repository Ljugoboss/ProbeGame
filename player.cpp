#include "player.h"
#include "level.h"

void Player::act() {
	if (getMovingX() == 1) {
		setState(0);
		setRotation(0);
	} else if (getMovingX() == -1) {
		setState(1);
		setRotation(180);
	}
	accelerate();
	move();
	draw();
}


std::vector<SDL_Texture*> Drawable<Player>::images = std::vector<SDL_Texture*>();
std::vector<std::vector<frame>> Drawable<Player>::frames = std::vector<std::vector<frame>>();
void Player::setup() {
	if (images.empty()) {
		parseXML("C:/Users/Twinmold/Documents/ProbeGame/probe_animation.xml");
	}
}
