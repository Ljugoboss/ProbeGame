/*     _____   _    _      ___      _____    _______   ______    ______   ______
 *    /  _  \ | |  | |    / _ \    |  __ \  |__   __| |  __  \  |  ____| |  ____|
 *    | | | | | |  | |   / /_\ \   | |  | |    | |    | |__| |  |  ____| |  ____|
 *    | |_| | | |__| |  / _____ \  | |__| |    | |    |  __  /  | |____  | |____
 *    \__  _/  \____/  /_/     \_\ |_____/     |_|    |_|  \_\  |______| |______|
 *       \_\
 *
 *		Eric Laukien
 */

#ifndef QUADTREE_H
#define QUADTREE_H

#include "QuadTreeNode.h"
#include "QuadTreeOccupant.h"

#include <unordered_set>

class QuadTree
{
private:
	std::unordered_set<QuadTreeOccupant*> outsideRoot;

	QuadTreeNode* rootNode;

public:
	QuadTree(const AABB &startRegion);
	~QuadTree();

	void AddOccupant(QuadTreeOccupant* pOc);
	void ClearTree(const AABB &newStartRegion);

	void Query(const AABB &queryRegion, std::vector<QuadTreeOccupant*> &queryResult);

	unsigned int GetNumOccupants();

	friend class QuadTreeNode;
	friend class QuadTreeOccupant;
};

#endif