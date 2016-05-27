#pragma once

#include "Map.h"

enum class NodeStatus { None, Closed, Open };

class Pathfinder
{
public:

	struct ComparePriority
	{//bool operator <(
		bool operator()(const std::shared_ptr<Node>& left, const std::shared_ptr<Node>& right)
		{
			double leftFValue = left->g + left->h;
			double rightFValue = right->g + right->h;
			return leftFValue > rightFValue;
		}
	};
	std::vector<Point> reconstructPath(std::shared_ptr<Node> goalNode);
	std::vector<std::vector<std::shared_ptr<Node>>> nodes;

	double nodeScore;
	double lowestScore;
	double maxScore = 1000;

	std::vector<Point> findPath(const Map& map, const Point& start, const Point& goal);

private:
	Map* map;
};
