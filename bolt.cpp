#include "bolt.h"
#include "level.h"

Bolt::Bolt(double x, double y, int id, std::shared_ptr<Level> l, int xDirection, int yDirection) : Movable(x, y, id, l), drawable(l->getRenderer(), l->FPS, "C:/Users/Twinmold/Documents/ProbeGame/bolt_animation.xml") {
	lifetime = 8;
	round = 0;

	setMovingX(xDirection);
	setMovingY(yDirection);
	if (xDirection != 0) {
		drawable.setState(1);
		setRotation(90);
	}
	else {
		drawable.setState(0);
		setRotation(0);
	}
}

void Bolt::act() {
	if (round >= lifetime * getLevel()->FPS / 3) {
		getLevel()->destroyActor(actor_id);
	} else {
		accelerate();
		move();
		drawable.draw(getX(), getY());
		round++;
	}
}