#include "player.h"
#include "level.h"
#include "blaster.h"

Player::Player(float x, float y, std::shared_ptr<Level> l) : Character(x, y, l), drawable(l->getRenderer(), l->FPS, "C:/Users/Twinmold/Documents/ProbeGame/probe_animation.xml") {
	height_modifiers = std::vector<int>({ 0, -1, -2, -3, -2, -1, 0, 1, 2, 3, 2, 1 });
	float_duration = 100;
	height_index = 0;
	time = 0;

	abilities = std::vector<std::shared_ptr<Ability>>();

	std::vector<Vec2f> polygon({ Vec2f(-36.5, -36.5), Vec2f(-36.5, 36.5), Vec2f(36.5, 36.5), Vec2f(36.5, -36.5) });
	setPolygon(polygon);
}

void Player::act() {
	if (getMovingX() == 1) {
		drawable.setState(0);
		setRotation(0);
	} else if (getMovingX() == -1) {
		drawable.setState(1);
		setRotation(180);
	}

	accelerate();
	move();

	time++;
	if (time >= float_duration / (1000 / getLevel()->FPS)) {
		height_index = (height_index + 1) % height_modifiers.size();
		time = 0;
	}

	for (std::shared_ptr<Ability> ability : abilities)  {
		ability->run();
	}
	drawable.draw(getX(), getY());


	auto points = getPolygon().outer();
	for (Point polygon : points) {
		SDL_Rect source;
		source.x = polygon.x() - 10;
		source.y = polygon.y() - 10;
		source.w = 20;
		source.h = 20;
		// Part of the screen we want to draw the sprite to
		SDL_SetRenderDrawColor(getLevel()->getRenderer(), 0, 0, 0, 255);
		SDL_RenderDrawRect(getLevel()->getRenderer(),
			&source);
	}
}

void Player::addAbility() {
	abilities.push_back(std::make_shared<Blaster>(Blaster(this, getLevel())));
}
void Player::useAbility() {
	abilities[0]->use();
}

float Player::getY() const {
	return Movable::getY() + height_modifiers[height_index];
}

void Player::setY(float value) {
	Movable::setY(value - height_modifiers[height_index]);
}
