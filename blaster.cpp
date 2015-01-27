#include "blaster.h"

void Blaster::use() {
	int xmod = 13;
	int ymod = 3;
	if (getHolder()->getRotation() == 0) {
		getLevel()->addActor(std::make_shared<Bolt>(Bolt(getX() + xmod, getY() + ymod, getLevel()->getCurrentId() + 1, getLevel(), 1, 0)));
	}
	else if (getHolder()->getRotation() == 180) {
		getLevel()->addActor(std::make_shared<Bolt>(Bolt(getX() - xmod, getY() + ymod, getLevel()->getCurrentId() + 1, getLevel(), -1, 0)));
	}
}

void Blaster::run() {
	if (getHolder()->getRotation() == 0) {
		setState(0);
		setRotation(0);
	} else if (getHolder()->getRotation() == 180) {
		setState(1);
		setRotation(180);
	}

	draw();
}

std::vector<SDL_Texture*> Drawable<Blaster>::images = std::vector<SDL_Texture*>();
std::vector<std::vector<frame>> Drawable<Blaster>::frames = std::vector<std::vector<frame>>();
void Blaster::setup() {
	if (images.empty()) {
		parseXML("C:/Users/Twinmold/Documents/ProbeGame/blaster_animation.xml");
	}
}