#include "locatable.h"

double Locatable::getX() const {
	return x;
}
double Locatable::getY() const {
	return y;
}

void Locatable::setX(double value) {
	x = value;
}
void Locatable::setY(double value) {
	y = value;
}

int Locatable::getRotation() const {
	return rotation;
}

void Locatable::setRotation(int value) {
	rotation = value;
}

const std::shared_ptr<Level>Locatable::getLevel() const {
	return level.lock();
}

std::shared_ptr<Level> Locatable::getLevel() {
	return level.lock();
}