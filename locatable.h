#ifndef LOCATABLE_H
#define LOCATABLE_H

#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include "QuadTree\QuadTree.h"

class Level;

class Locatable : public QuadTreeOccupant {
private:
	std::weak_ptr<Level> level;

	std::vector<Vec2f> polygon;

	float width;
	float height;

	float x;
	float y;

	float size;

	int rotation;

public:
	static int sign(float i);
	static float length(float a, float b);
	static float distance(Vec2f A, Vec2f B);

	Locatable() {
	}

	void init(float start_x, float start_y, std::shared_ptr<Level> l) {
		level = l;

		x = start_x;
		y = start_y;

		rotation = 0;

		polygon = std::vector<Vec2f>();
		width = 0;
		height = 0;

		aabb.SetCenter(Vec2f(x, y));
		aabb.SetDims(Vec2f(width, height));
		UpdateTreeStatus();
	}

	virtual bool collision(QuadTreeOccupant& object) const;

	virtual void setPolygon(std::vector<Vec2f> points);

	virtual Polygon getPolygon() const;

	virtual float getX() const;
	virtual float getY() const;

	virtual void setX(float value);
	virtual void setY(float value);

	virtual float getWidth() const {
		return width;
	}
	virtual float getHeight() const {
		return height;
	}

	virtual int getRotation() const;
	virtual void setRotation(int value);

	std::shared_ptr<Level> getLevel();
	const std::shared_ptr<Level> getLevel() const;
};

#endif
