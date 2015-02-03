#include "bolt.h"
#include "level.h"

Bolt::Bolt(float x, float y, std::shared_ptr<Level> l, int xDirection, int yDirection) : Movable(x, y, l), drawable(l->getRenderer(), l->FPS, "C:/Users/Twinmold/Documents/ProbeGame/bolt_animation.xml") {
	lifetime = 8;
	round = 0;
	max_speed = 600;
	accx = 600;
	accy = 600;

	setMovingX(xDirection);
	setMovingY(yDirection);
	if (xDirection != 0) {
		drawable.setState(1);
		setRotation(90);
	}
	else {
		drawable.setState(0);
		setRotation(0);
	}

	std::vector<Vec2f> polygon({ Vec2f(0, 0) });
	setPolygon(polygon);
}

void Bolt::act() {
	if (round >= lifetime * getLevel()->FPS / 3) {
		getLevel()->destroyActor(actor_id);
	} else {
		accelerate();
		move();
		drawable.draw(getX(), getY());
		round++;
	}
	auto points = getPolygon().outer();
	for (Point polygon : points) {
		SDL_Rect source;
		source.x = polygon.x() - 2;
		source.y = polygon.y() - 2;
		source.w = 4;
		source.h = 4;
		// Part of the screen we want to draw the sprite to
		SDL_SetRenderDrawColor(getLevel()->getRenderer(), 0, 0, 0, 255);
		SDL_RenderDrawRect(getLevel()->getRenderer(),
			&source);
	}
}