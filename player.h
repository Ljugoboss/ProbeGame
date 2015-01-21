#include "character.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player : public Character {
private:
public:
	Player(double x, double y, int id, std::shared_ptr<Level> l) : Character(x, y, id, l) {
		image_height = 61;
		image_width = 61;
		image_path = "C:/Users/Twinmold/Documents/ProbeGame/ProbeMain.bmp"; 
	}

	void act();
};

#endif