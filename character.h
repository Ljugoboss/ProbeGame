#ifndef CHARACTER_H
#define CHARACTER_H

#include "actor.h"

class Character : public Actor {
private:
public:
	Character(double x, double y, int id, std::shared_ptr<Level> l) : Actor(x, y, id, l) {
	}
};

#endif