#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include "ability.h"

class Player : public Character, public Drawable<Player> {
private:
	std::vector<std::shared_ptr<Ability>> abilities;
	int float_duration;
	int time;
	int height_index;
	std::vector<int> height_modifiers;
public:
	Player(double x, double y, int id, std::shared_ptr<Level> l) : Character(x, y, id, l) {
		height_modifiers = std::vector<int>({0, -1, -2, -3, -2, -1, 0, 1, 2, 3, 2, 1});
		float_duration = 100;
		height_index = 0;
		time = 0;

		image_height = 73;
		image_width = 73;

		setState(0);
		setRotation(0);
		setup();
		abilities = std::vector<std::shared_ptr<Ability>>();
	}

	double getY() const;
	void setY(double value);

	void addAbility();
	void useAbility();

	void act();

	void setup();
};

#endif