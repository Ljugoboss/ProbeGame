#ifndef MOVABLE_H
#define MOVABLE_H

#include "actor.h"
#include <cmath>
#include <iostream>
#include <memory>
#include <string>

class Movable : public Actor {
//private:
public:
	float velx;
	float vely;
	float accx;
	float accy;

	float de_accx;
	float de_accy;

	float max_speed;

	float weight;

	int movingX;
	int movingY;
//public:
	Movable(float x, float y, std::shared_ptr<Level> l) : Actor(x, y, l) {
		max_speed = 400;

		de_accx = 25;
		de_accy = 25;

		velx = 0;
		vely = 0;
		accx = 45;
		accy = 45;

		movingX = 0;
		movingY = 0;
	}

	virtual void move();

	virtual void accelerate();

	float getMaxSpeed() const;

	float getAccX() const;
	float getAccY() const;

	float getDeaccX() const;
	float getDeaccY() const;

	void setMovingX(int value);
	void setMovingY(int value);

	int getMovingX() const;
	int getMovingY() const;
};

#endif