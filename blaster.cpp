#include "blaster.h"
#include "level.h"

Blaster::Blaster(Actor * player, std::shared_ptr<Level> l) : Ability(player, l), drawable(l->getRenderer(), l->FPS, "C:/Users/Twinmold/Documents/ProbeGame/blaster_animation.xml") {
}

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
		drawable.setState(0);
		setRotation(0);
	} else if (getHolder()->getRotation() == 180) {
		drawable.setState(1);
		setRotation(180);
	}

	drawable.draw(getX(), getY());
}