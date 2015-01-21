#include "movable.h"
#include "level.h"

int Movable::sign(double i) {
	if (i > 0) { return 1; }
	if (i < 0) { return -1; }
	return 0;
}

double Movable::length(double a, double b) {
	return sqrt(pow(a, 2) + pow(b, 2));
}

void Movable::move () {
	int checkX = sign(velx);
	int checkY = sign(vely);
	double distance = length(velx, vely);
	if (!(distance == 0)) {
		x += (int) (velx * (velx / distance) * checkX);
		y += (int) (vely * (vely / distance) * checkY);
	}
}

void Movable::accelerate() {
	int checkX = sign(velx);
	if (movingX != checkX) {
		velx -= checkX * getDeaccX();
		if (sign(velx) != checkX) {
			velx = 0;
		}
	}

	int checkY = sign(vely);
	if (movingY != checkY) {
		vely -= checkY * getDeaccY();
		if (sign(vely) != checkY) {
			vely = 0;
		}
	}

	velx += getAccX() * movingX;
	vely += getAccY() * movingY;

	if (abs(velx) > getMaxSpeed()) {
		velx = getMaxSpeed() * movingX;
	}
	if (abs(vely) > getMaxSpeed()) {
		vely = getMaxSpeed() * movingY;
	}
}

double Movable::getX() const {
	return x;
}
double Movable::getY() const {
	return y;
}

void Movable::setX(double value) {
	x = value;
}
void Movable::setY(double value) {
	y = value;
}

double Movable::getMaxSpeed() const {
	return max_speed / getLevel()->FPS;
}

double Movable::getAccX() const {
	return accx / getLevel()->FPS;
}
double Movable::getAccY() const {
	return accy / getLevel()->FPS;
}

double Movable::getDeaccX() const {
	return de_accx / getLevel()->FPS;
}
double Movable::getDeaccY() const {
	return de_accy / getLevel()->FPS;
}

void Movable::setMovingX(int value) {
	movingX = value;
	if (movingX < -1) {
		movingX = -1;
	} else if (movingX > 1) {
		movingX = 1;
	}
}

void Movable::setMovingY(int value) {
	movingY = value;
	if (movingY < -1) {
		movingY = -1;
	} else if (movingY > 1) {
		movingY = 1;
	}
}

int Movable::getRotation() const {
	return rotation;
}

void Movable::setRotation(int value) {
	rotation = value;
}

int Movable::getMovingX() const {
	return movingX;
}
int Movable::getMovingY() const {
	return movingY;
}

const std::shared_ptr<Level> Movable::getLevel() const {
	return level.lock();
}

std::shared_ptr<Level> Movable::getLevel() {
	return level.lock();
}