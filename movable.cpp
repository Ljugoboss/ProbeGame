#include "movable.h"
#include "level.h"

void Movable::move () {
	int checkX = sign(velx);
	int checkY = sign(vely);
	float distance = length(velx, vely);
	if (!(distance == 0)) {
		setX(getX() + (velx * (velx / distance) * checkX));
		setY(getY() + (vely * (vely / distance) * checkY));
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

float Movable::getMaxSpeed() const {
	return max_speed / getLevel()->FPS;
}

float Movable::getAccX() const {
	return accx / getLevel()->FPS;
}
float Movable::getAccY() const {
	return accy / getLevel()->FPS;
}

float Movable::getDeaccX() const {
	return de_accx / getLevel()->FPS;
}
float Movable::getDeaccY() const {
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

int Movable::getMovingX() const {
	return movingX;
}
int Movable::getMovingY() const {
	return movingY;
}