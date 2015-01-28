#ifndef CHARACTER_H
#define CHARACTER_H

#include "movable.h"

class Character : public Movable {
private:
public:
	Character(double x, double y, int id, std::shared_ptr<Level> l) : Movable(x, y, id, l) {
	}
};

#endif