#ifndef ACTOR_H
#define ACTOR_H

#include "movable.h"
#include "sdl/SDL.h"

class Actor : public virtual Movable {
private:
public:
	int actor_id;

	Actor(double x, double y, int id, std::shared_ptr<Level> l) { 
		init(x, y, l);
		actor_id = id;
	}

	virtual void act() = 0;
};

#endif