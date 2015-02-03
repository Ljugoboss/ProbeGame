#ifndef CONSTRUCTS_H
#define CONSTRUCTS_H

#include <iostream>
#include <vector>
#include <boost/geometry/geometries/point_xy.hpp>

class Vec2f2i
{
public:
	int x,  y;

	Vec2f2i(const int &X, const int &Y);
	Vec2f2i();
	
	bool operator==(Vec2f2i &other) const;
};

class Vec2f 
{
public:
	float x, y;

	operator boost::geometry::model::d2::point_xy<float>() {
		return  boost::geometry::model::d2::point_xy<float>(x, y);
	}

	Vec2f();
	Vec2f(const float &X, const float &Y);
		
	Vec2f operator*(const float &scale) const;
	Vec2f operator/(const float &scale) const;
	Vec2f operator+(const Vec2f &other) const;
	Vec2f operator-(const Vec2f &other) const;
	Vec2f operator-() const;
		
	const Vec2f &operator*=(const float &scale);
	const Vec2f &operator/=(const float &scale);
	const Vec2f &operator+=(const Vec2f &other);
	const Vec2f &operator-=(const Vec2f &other);
		
	float magnitude() const;
	float magnitudeSquared() const;
	Vec2f normalize() const;
	float dot(const Vec2f &other) const;
	float cross(const Vec2f &other) const;
};

Vec2f operator*(const float &scale, const Vec2f &v);
std::ostream &operator<<(std::ostream &output, const Vec2f &v);

#endif