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
	Player(float x, float y, std::shared_ptr<Level> l);

	float getY() const;
	void setY(float value);

	void addAbility();
	void useAbility();

	void act();
};

#endif