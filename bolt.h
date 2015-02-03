#ifndef BOLT_H
#define BOLT_H

#include "actor.h"
#include "level.h"
#include "drawable.h"

class Bolt : public Movable {
private:
	int lifetime;
	int round;

	Drawable<Bolt> drawable;
public:
	Bolt(float x, float y, std::shared_ptr<Level> l, int xDirection, int yDirection);

	void act();
};

#endif