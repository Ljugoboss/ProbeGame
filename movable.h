#ifndef MOVABLE_H
#define MOVABLE_H

#include <cmath>
#include <iostream>
#include <memory>
#include <string>

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

	int rotation;

	double de_accx;
	double de_accy;

	double max_speed;

	double weight;

	int movingX;
	int movingY;

	int sign(double i);
	double length(double a, double b);

public:
	Movable() {
	}

	void init(double start_x, double start_y, std::shared_ptr<Level> l) {
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

		rotation = 0;
	}

	virtual void move();

	virtual void accelerate();

	double getX() const;
	double getY() const;

	void setX(double value);
	void setY(double value);

	double getMaxSpeed() const;

	double getAccX() const;
	double getAccY() const;

	double getDeaccX() const;
	double getDeaccY() const;

	void setMovingX(int value);
	void setMovingY(int value);

	int getMovingX() const;
	int getMovingY() const;

	int getRotation() const;
	void setRotation(int value);

	std::shared_ptr<Level> getLevel();
	const std::shared_ptr<Level> getLevel() const;
};

#endif