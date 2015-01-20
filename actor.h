#include "movable.h"
#include "sdl/SDL.h"

#ifndef ACTOR_H
#define ACTOR_H

class Actor : public Movable {
private:
public:
	const char * image_path = "";
	/*
	using Movable::move;
	using Movable::accelerate;
	using Movable::getX;
	using Movable::getY;
	*/

	Actor(int x, int y, std::shared_ptr<Level> l) : Movable(x, y, l) { }

	virtual void act() = 0;

	void draw(SDL_Renderer* renderer);
};

#endif