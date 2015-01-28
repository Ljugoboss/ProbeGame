#ifndef BLASTER_H
#define BLASTER_H

#include "ability.h"
#include "sdl/SDL.h"
#include "bolt.h"
#include "drawable.h"

class Blaster : public Ability {
private:
	Drawable<Blaster> drawable;
public:
	Blaster(Actor * player, std::shared_ptr<Level> l);

	void use();

	void run();

	virtual double getX() const { return Ability::getX(); }
	virtual double getY() const { return Ability::getY(); }
};

#endif