#include <cmath>
#include <iostream>
#include <memory>
#include <string>

#ifndef MOVABLE_H
#define MOVABLE_H

class Level;

class Movable {
private:
	std::weak_ptr<Level> level;

	double x;
	double y;

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
	Movable(int start_x, int start_y, std::shared_ptr<Level> l) {
		level = l;
		max_speed = 400;

		x = start_x;
		y = start_y;

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

	double getX() const;
	double getY() const;

	double getMaxSpeed() const;

	double getAccX() const;
	double getAccY() const;

	double getDeaccX() const;
	double getDeaccY() const;

	void setMovingX(int value);
	void setMovingY(int value);

	int getMovingX();
	int getMovingY();

	std::shared_ptr<Level> get_level();
	const std::shared_ptr<Level> get_level() const;
};

#endif