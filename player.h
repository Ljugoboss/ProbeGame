#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include "ability.h"
#include "drawable.h"

class Player : public Character {
private:
	std::vector<std::shared_ptr<Ability>> abilities;
	int float_duration;
	int time;
	int height_index;
	std::vector<int> height_modifiers;

	Drawable<Player> drawable;
public:
	Player(double x, double y, int id, std::shared_ptr<Level> l);

	double getY() const;
	void setY(double value);

	void addAbility();
	void useAbility();

	void act();
};

#endif