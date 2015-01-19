#include "actor.h"

#ifndef CHARACTER_H
#define CHARACTER_H

class Character : public Actor {
private:
public:
	Character() {
	}

	virtual void action() {}
};

#endif