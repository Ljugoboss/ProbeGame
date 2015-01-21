#ifndef ACTOR_H
#define ACTOR_H

#include "movable.h"
#include "sdl/SDL.h"

class Actor : public Movable {
private:
public:
	int actor_id;

	/*
	using Movable::move;
	using Movable::accelerate;
	using Movable::getX;
	using Movable::getY;
	*/

	std::string image_path = "";

	int image_width;
	int image_height;

	Actor(double x, double y, int id, std::shared_ptr<Level> l) : Movable(x, y, l) { 
		actor_id = id;
	}

	virtual void act() = 0;

	void draw();
};

#endif