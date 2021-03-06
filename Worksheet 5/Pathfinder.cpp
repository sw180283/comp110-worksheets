#pragma once
#include "stdafx.h"
#include "Pathfinder.h"
#include "Node.h"

double euclideanDistance(const Point& a, const Point& b)
{
	double dx = a.getX() - b.getX();
	double dy = a.getY() - b.getY();
	return sqrt(dx*dx + dy*dy);
}

bool Pathfinder::isInOpenSet(std::shared_ptr<Node> node)
{
	// Make a copy of the openSet
	std::priority_queue<std::shared_ptr<Node>, std::vector<std::shared_ptr<Node>>, ComparePriority> openSetTemp = openSet;
}


std::vector<Point> Pathfinder::findPath(const Map& map, const Point& start, const Point& goal)
{
	//closeSet{}
	std::vector<std::shared_ptr<Node>> closedSet;

	//if dir==4
	const int dir = 4;
	static int x[dir] = { 1, 0, -1, 0 };
	static int y[dir] = { 0, 1, 0, -1 };

	//openSet{startNode}
	auto startNode = std::make_shared<Node>(start.getX(), start.getY());
	auto goalNode = std::make_shared<Node>(goal.getX(), goal.getY());

	std::priority_queue<std::shared_ptr<Node>, std::vector<std::shared_ptr<Node>>, ComparePriority> openSet;
	openSet.push(startNode);

	//startNode.g<-0
	startNode->g = 0;

	//startNode.h<- EUCLIDEANDISTANCE(startNode, goalNode)
	startNode->h = euclideanDistance(start, goal);

	//startNode.cameFrom<-null
	startNode->cameFrom = nullptr;

	//while openSet is not empty do
	while (!openSet.empty())
	{

		//currentNode<- node in openSet with lowest g+h score
		auto currentNode = openSet.top();
		//auto currentNode = std::make_shared<Node>(start.getX(), start.getY());

		//if currentNode = goalNode then
		if (currentNode == goalNode)
		{
			//return RECONSTRUCTPATH(goalNode)
			return reconstructPath(goalNode);
		}
		//end if

		//remove currentNode from openSet
		openSet.pop();

		//add currentNode to closeSet
		closedSet.push_back(currentNode);

		//for each neighbourNode adjacent to currentNode do
		static int i;
		for (i = 0; i < dir; i++)
		{
			double currentXPos = currentNode->point.getX();
			double currentYPos = currentNode->point.getY();
			double nextXPos = currentXPos + x[i];
			double nextYPos = currentYPos + y[i];
			const Point neighbourNode (nextXPos, nextYPos);

			//if neighbourNode is not a wall and neighbourNode not in closedSet then
			if (neighbourNode != map.isWall && std::find(closedSet.begin(), closedSet.end(), neighbourNode) == closedSet.end())
			{
				//gtentative<-currentNode.g+EUCLIDEANDISTANCE(currentNode, neighbourNode)
				double gTentative = currentNode->g + euclideanDistance(currentNode->point, neighbourNode);

				//if neighbourNode not in openSet or gtentative < neighbourNode.g then
				if (!isInOpenSet(neighbourNode) || gTentative < neighbourNode->g)
				{
					//neighbourNode.g = gtentative
					neighbourNode->g = gTentative;

					//neighbourNode.h <- EUCLIDEANDISTANCE(neighbourNode, goalNode)
					neighbourNode->h = euclideanDistance(neighbourNode, goalNode);

					//add neighbourNode to openSet (if it is not already in)
					if (!isInOpenSet(neighbourNode))
					{
						Node neighbourNode(openSet.top());

					}
				}
				//end if
			}
			//end if
		}
		//end for
	}
	//end while

	//return "Failed to find a path"

//end procedure
}

//RECONSTRUCTPATH(goalNode)
std::vector<Point> Pathfinder::reconstructPath(std::shared_ptr<Node> goalNode)
{
	//path<-{}
	std::vector<Point> result;

	//currentNode <-goalNode
	for (auto currentNode = goalNode; currentNode; currentNode = currentNode->cameFrom)
	{

	//while currentNode!=null do
		//add currentNode to the beginning of path
		result.insert(result.begin(), currentNode->point);
		//currentNode<-currentNode.cameFrom
	}
	//end while

	//return path
	return result;

//end procedure



