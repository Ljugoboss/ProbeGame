#include "player.h"
#include "level.h"
#include "blaster.h"

Player::Player(double x, double y, int id, std::shared_ptr<Level> l) : Character(x, y, id, l), drawable(l->getRenderer(), l->FPS, "C:/Users/Twinmold/Documents/ProbeGame/probe_animation.xml") {
	height_modifiers = std::vector<int>({ 0, -1, -2, -3, -2, -1, 0, 1, 2, 3, 2, 1 });
	float_duration = 100;
	height_index = 0;
	time = 0;

	abilities = std::vector<std::shared_ptr<Ability>>();
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
}

void Player::addAbility() {
	abilities.push_back(std::make_shared<Blaster>(Blaster(this, getLevel())));
}
void Player::useAbility() {
	abilities[0]->use();
}

double Player::getY() const {
	return Movable::getY() + height_modifiers[height_index];
}

void Player::setY(double value) {
	Movable::setY(value - height_modifiers[height_index]);
}
