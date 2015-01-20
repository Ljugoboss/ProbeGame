#include "actor.h"

#ifndef CHARACTER_H
#define CHARACTER_H

class Character : public Actor {
private:
public:
	Character(int x, int y, std::shared_ptr<Level> l) : Actor(x, y, l) {
	}
};

#endif