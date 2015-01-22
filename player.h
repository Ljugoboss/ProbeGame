#include "character.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player : public Character, public Drawable<Player> {
private:
public:
	Player(double x, double y, int id, std::shared_ptr<Level> l) : Character(x, y, id, l) {
		image_height = 70;
		image_width = 70;
		setState(0);
		setRotation(0);
		setup();
	}

	void act();

	void setup();
};

#endif