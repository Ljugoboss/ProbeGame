#ifndef ACTOR_H
#define ACTOR_H

#include "locatable.h"
#include "sdl/SDL.h"

class Actor : public Locatable {
private:
public:
	int actor_id;

	Actor(float x, float y, std::shared_ptr<Level> l) { 
		init(x, y, l);
	}

	virtual void act() = 0;
};

#endif