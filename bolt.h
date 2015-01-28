#ifndef BOLT_H
#define BOLT_H

#include "actor.h"
#include "level.h"
#include "drawable.h"

class Bolt : public Movable, public Drawable<Bolt> {
private:
	int lifetime;
	int round;
public:
	Bolt(double x, double y, int id, std::shared_ptr<Level> l, int xDirection, int yDirection) : Movable(x, y, id, l) {
		lifetime = 8;
		round = 0;

		setMovingX(xDirection);
		setMovingY(yDirection);
		if (xDirection != 0) {
			state = 1;
			setRotation(90);
		} else {
			state = 0;
			setRotation(0);
		}
		image_height = 25;
		image_width = 25;
		setup();
	}

	void act();

	void setup();
};

#endif