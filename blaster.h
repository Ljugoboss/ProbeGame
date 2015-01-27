#ifndef BLASTER_H
#define BLASTER_H

#include "drawable.h"
#include "ability.h"
#include "sdl/SDL.h"
#include "bolt.h"

class Blaster : public Ability, public Drawable<Blaster> {
private:
public:
	using Ability::getX;
	using Ability::getY;

	Blaster(Actor * player, std::shared_ptr<Level> l) : Ability(player, l) {
		image_width = 20;
		image_height = 15;
		setup();
	}

	void use();

	void run();

	void setup();

	virtual double getX() const { return Ability::getX(); }
	virtual double getY() const { return Ability::getY(); }
};

#endif