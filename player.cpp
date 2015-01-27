#include "player.h"
#include "level.h"
#include "blaster.h"

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

	time++;
	if (time >= float_duration / (1000 / getLevel()->FPS)) {
		height_index = (height_index + 1) % height_modifiers.size();
		time = 0;
	}

	for (std::shared_ptr<Ability> ability : abilities)  {
		ability->run();
	}
	draw();
}

void Player::addAbility() {
	abilities.push_back(std::make_shared<Blaster>(Blaster(this, getLevel())));
}
void Player::useAbility() {
	abilities[0]->use();
}

double Player::getY() const {
	return Movable::getY() + height_modifiers[height_index];
}

std::vector<SDL_Texture*> Drawable<Player>::images = std::vector<SDL_Texture*>();
std::vector<std::vector<frame>> Drawable<Player>::frames = std::vector<std::vector<frame>>();
void Player::setup() {
	if (images.empty()) {
		parseXML("C:/Users/Twinmold/Documents/ProbeGame/probe_animation.xml");
	}
}
