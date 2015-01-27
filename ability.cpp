#include "ability.h"

double Ability::getX() const {
	int modifier = modifierR;
	if (getHolder()->getRotation() == 180) {
		modifier = modifierL;
	}
	return (getHolder()->getX() + modifier);
}

double Ability::getY() const {
	return (getHolder()->getY() + modifierY);
}

Actor * Ability::getHolder() {
	return holder;
}

const Actor * Ability::getHolder() const {
	return holder;
}

