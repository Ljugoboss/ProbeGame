#ifndef ABILITY_H
#define ABILITY_H

#include "actor.h"
#include "movable.h"
#include "sdl/SDL.h"

class Ability : public virtual Locatable {
private:
	Actor * holder;
public:
	int modifierL;
	int modifierR;
	int modifierY;

	Ability(Actor * player, std::shared_ptr<Level> l) {
		holder = player;
		init(player->getX(), player->getY(), l);
		modifierL = -2;
		modifierR = 8;
		modifierY = 37;
	}

	virtual void use() = 0;

	virtual void run() = 0;

	virtual float getX() const;
	virtual float getY() const;

	Actor * getHolder();
	const Actor * getHolder() const;
};

#endif