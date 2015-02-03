#include "locatable.h"
#include <boost/geometry.hpp>
#include <boost/geometry/algorithms/within.hpp>

int Locatable::sign(float i) {
	if (i > 0) { return 1; }
	if (i < 0) { return -1; }
	return 0;
}

float Locatable::length(float a, float b) {
	return sqrt(pow(a, 2) + pow(b, 2));
}

float Locatable::distance(Vec2f A, Vec2f B) {
	return length(A.x - B.x, A.y - B.y);
}

bool Locatable::collision(QuadTreeOccupant& object) const {
	Polygon this_poly = getPolygon();
	Polygon other_poly = object.getPolygon();
	auto this_points = this_poly.outer();
	for (auto it : this_points){
		if (boost::geometry::within(it, other_poly)) {
			return true;
		}
	}

	auto other_points = other_poly.outer();
	for (auto it : other_points){
		if (boost::geometry::within(it, this_poly)) {
			return true;
		}
	}
	return false;
}

void Locatable::setPolygon(std::vector<Vec2f> points) {
	float lowX = 0;
	float highX = 0;
	float lowY = 0;
	float highY = 0;
	for (auto point : points) {
		if (point.x < lowX) lowX = point.x;
		if (point.x > highX) highX = point.x;
		if (point.y < lowY) lowY = point.y;
		if (point.y > highY) highY = point.y;
	}
	width = highX - lowX;
	height = highY - lowY;
	aabb.SetDims(Vec2f(width, height));
	UpdateTreeStatus();
	polygon = points;
}

Polygon Locatable::getPolygon() const {
	Polygon ret;
	for (unsigned int i = 0; i < polygon.size(); ++i) {
		Point p(polygon[i].x + getX(), polygon[i].y + getY());
		boost::geometry::append(ret, p);
	}
	return ret;
}

float Locatable::getX() const {
	return x;
}
float Locatable::getY() const {
	return y;
}

void Locatable::setX(float value) {
	x = value;
	aabb.SetCenter(Vec2f(x, y));
	aabb.SetDims(Vec2f(width, height));
	UpdateTreeStatus();
}
void Locatable::setY(float value) {
	y = value;
	aabb.SetCenter(Vec2f(x, y));
	aabb.SetDims(Vec2f(width, height));
	UpdateTreeStatus();
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