#ifndef QUADTREEOCCUPANT_H
#define QUADTREEOCCUPANT_H

#include "Constructs.h"

#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/geometries/polygon.hpp>

typedef boost::geometry::model::d2::point_xy<float> Point;
typedef boost::geometry::model::polygon<Point> Polygon;

class QuadTreeNode;
class QuadTree;

struct AABB
{
	// Members
	Vec2f lowerBound;
	Vec2f upperBound;

	// Constructor
	AABB();
	AABB(const Vec2f &bottomLeft, const Vec2f &topRight);

	// Accessors
	Vec2f GetCenter() const;
	Vec2f GetDims() const;
	Vec2f GetLowerBound() const;
	Vec2f GetUpperBound() const;

	// Modifiers
	void SetCenter(const Vec2f &newCenter);
	void IncCenter(const Vec2f &increment);
	void SetDims(const Vec2f &newDims);

	// Utility
	bool Intersects(const AABB &other);
	bool Contains(const AABB &other);

	friend struct AABB;
};

class QuadTreeOccupant
{
private:
	QuadTreeNode* pQuadTreeNode;
	QuadTree* pQuadTree;

public:
	AABB aabb;

	// Call this whenever the AABB is modified or else stuff will break!
	void UpdateTreeStatus();
	void RemoveFromTree();

	virtual bool collision(QuadTreeOccupant& object) const = 0;

	virtual Polygon getPolygon() const = 0;

	QuadTreeOccupant();
	virtual ~QuadTreeOccupant();

	friend class QuadTreeNode;
	friend class QuadTree;
};

#endif