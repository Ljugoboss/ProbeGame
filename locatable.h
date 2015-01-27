#ifndef LOCATABLE_H
#define LOCATABLE_H

#include <memory>

class Level;

class Locatable {
private:
	std::weak_ptr<Level> level;
public:
	double x;
	double y;

	int rotation;

	Locatable() {
	}

	void init(double start_x, double start_y, std::shared_ptr<Level> l) {
		level = l;

		x = start_x;
		y = start_y;
	}

	virtual double getX() const;
	virtual double getY() const;

	void setX(double value);
	void setY(double value);

	int getRotation() const;
	void setRotation(int value);

	std::shared_ptr<Level> getLevel();
	const std::shared_ptr<Level> getLevel() const;
};

#endif
