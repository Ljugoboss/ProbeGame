#ifndef MOVABLE_H
#define MOVABLE_H

#include "actor.h"
#include <cmath>
#include <iostream>
#include <memory>
#include <string>

class Movable : public Actor {
private:
	double velx;
	double vely;
	double accx;
	double accy;

	double de_accx;
	double de_accy;

	double max_speed;

	double weight;

	int movingX;
	int movingY;

	int sign(double i);
	double length(double a, double b);

public:
	Movable(double x, double y, int id, std::shared_ptr<Level> l) : Actor(x, y, id, l) {
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

	double getMaxSpeed() const;

	double getAccX() const;
	double getAccY() const;

	double getDeaccX() const;
	double getDeaccY() const;

	void setMovingX(int value);
	void setMovingY(int value);

	int getMovingX() const;
	int getMovingY() const;
};

#endif