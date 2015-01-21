#ifndef BOLT_H
#define BOLT_H

#include "actor.h"
#include "level.h"

class Bolt : public Actor {
private:
	int lifetime;
	int round;
public:
	Bolt(double x, double y, int id, std::shared_ptr<Level> l, int xDirection, int yDirection) : Actor(x, y, id, l) {
		lifetime = 8;
		round = 0;

		setMovingX(xDirection);
		setMovingY(yDirection);
		if (xDirection == 1) {
			setRotation(90);
		} else {
			setRotation(0);
		}
		image_height = 25;
		image_width = 25;
		image_path = "C:/Users/Twinmold/Documents/ProbeGame/bolt" + std::to_string(getRotation()) + ".bmp";
	}

	void act();
};

#endif