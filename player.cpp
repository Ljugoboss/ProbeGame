#include "player.h"
#include "level.h"

void Player::act() {
	accelerate();
	move();
	draw();
}

