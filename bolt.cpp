#include "bolt.h"
#include "level.h"

void Bolt::act() {
	if (round >= lifetime * getLevel()->FPS / 3) {
		getLevel()->destroyActor(actor_id);
	} else {
		accelerate();
		move();
		draw();
		round++;
	}
}