#include "character.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player : public Character {
private:
public:
	Player(int x, int y, std::shared_ptr<Level> l) : Character(x, y, l) { 
		image_path = "C:/Users/Twinmold/Documents/ProbeGame/ProbeMain.bmp"; 
	}

	void act();
};

#endif