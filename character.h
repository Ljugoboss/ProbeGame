#ifndef CHARACTER_H
#define CHARACTER_H

#include "movable.h"

class Character : public Movable {
private:
public:
	Character(float x, float y, std::shared_ptr<Level> l) : Movable(x, y, l) {
	}
};

#endif