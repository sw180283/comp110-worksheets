#pragma once
#include "Point.h"
#include "Pathfinder.h"

class Node
{

public:
	Node(const Point& point);
	~Node();

	Point point;
	NodeStatus status = NodeStatus::None;
	double g = 0, h = 0;
	std::shared_ptr<Node> cameFrom;

	struct ComparePriority;

private:
};