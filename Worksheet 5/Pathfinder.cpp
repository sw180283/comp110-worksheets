#pragma once
#include "stdafx.h"
#include "Pathfinder.h"
#include "Node.h"
#include "EuclideanDistance.h"

double euclideanDistance(const Point& a, const Point& b)
{
	double dx = a.getX() - b.getX();
	double dy = a.getY() - b.getY();
	return sqrt(dx*dx + dy*dy);
}
/*
void Pathfinder::addToClosedSet();

std::vector<Point> Pathfinder::findPath(const Map& map, const Point& start, const Point& goal)
{
	// TODO: implement the A* algorithm to find a path from start to goal
	
	//Start node from Node
	//Node startNode(start);
	auto startNode = std::make_shared<Node>(start.getX(), start.getY());

	//Goal node from Node
	//Node goalNode(goal);
	auto goalNode = std::make_shared<Node>(goal.getX(), goal.getY());

	
	//if dir==4
	const int dir = 4;
	static int x[dir] = { 1, 0, -1, 0 };
	static int y[dir] = { 0, 1, 0, -1 };
	
	//closedSet is empty
	std::vector<Node> closedSet;

	//openSet has startNode in
	std::priority_queue<Node, std::vector<Node>, ComparePriority> openSet;
	openSet.push(startNode);

	//startNode.g is set 0
	startNode.g = 0;

	//Euclidean Distance startNode goalNode
	startNode.h = EuclideanDistance(startNode, goalNode);

	//cameFrom
	startNode.cameFrom = nullptr;

	//while
	while (!openSet.empty())
	{
		//getFValue
		Node currentNode(openSet.top());

		if currentNode = goalNode
		{
			return ReconstructPath(goalNode);
		}
		//remove currentNode from openSet
		openSet.pop();
		closedSet.push_back(currentNode);

		static int i;
		for (i = 0; i < dir; i++)
		{
			nextXPos = currentXPos + x[i];
			nextYPos = currentYPos + y[i];
			const Point& neighbourNode = (nextXPos, nextYPos);
			Map* map;
			if(!neighbourNode = map.isWall)
		}
	}
	//end



	std::vector<Point> result;
	return result;
}*/

std::vector<Point> Pathfinder::findPath(const Map& map, const Point& start, const Point& goal)
{
	//closeSet{}
	std::vector<Node> closedSet;

	//if dir==4
	const int dir = 4;
	static int x[dir] = { 1, 0, -1, 0 };
	static int y[dir] = { 0, 1, 0, -1 };

	//openSet{startNode}
	auto startNode = std::make_shared<Node>(start.getX(), start.getY());
	auto goalNode = std::make_shared<Node>(goal.getX(), goal.getY());

	std::priority_queue<Node, std::vector<Node>, ComparePriority> openSet;
	openSet.push(startNode);

	//startNode.g<-0
	startNode->g = 0;

	//startNode.h<- EUCLIDEANDISTANCE(startNode, goalNode)
	startNode->h = euclideanDistance(start, goal);

	//startNode.cameFrom<-null
	startNode->cameFrom = nullptr;

	//while openSet is not empty do
	while (!openSet.empty())

		//currentNode<- node in openSet with lowest g+h score
		Node currentNode(openSet.top());
		//auto currentNode = std::make_shared<Node>(start.getX(), start.getY());

		//if currentNode = goalNode then
		if currentNode = goalNode
		{
			//return RECONSTRUCTPATH(goalNode)
			return ReconstructPath(goalNode);
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
			double currentXPos = currentNode.getX();
			double curerntYPos = currentNode.getY();
			double nextXPos = currentXPos + x[i];
			double nextYPos = currentYPos + y[i];
			const Point& neighbourNode = (nextXPos, nextYPos);

			//if neighbourNode is not a wall and neighbourNode not in closedSet then
			if (neighbourNode != map.isWall && != closedSet)
			{
				//gtentative<-currentNode.g+EUCLIDEANDISTANCE(currentNode, neighbourNode)
				double gTentative = currentNode.g + euclideanDistance(currentNode, neighbourNode);

				//if neighbourNode not in openSet or gtentative < neighbourNode.g then
				if (neightbourNode != openSet || gTentative < neighbourNode.g)
				{
					//neighbourNode.g = gtentative
					neighbourNode.g = gTentative;

					//neighbourNode.h <- EUCLIDEANDISTANCE(neighbourNode, goalNode)
					neighbourNode.h = euclideanDistance(neighbourNode, goalNode);

					//add neighbourNode to openSet (if it is not already in)
					if (std::find(openSet.begin(), openSet.end(), neighbourNode) == openSet.end())
					{
						Node neighbourNode(openSet.top());

					}

				}
				//end if
			}
			//end if
		}
		//end for

	//end while

	//return "Failed to find a path"
//end procedure
}

//RECONSTRUCTPATH(goalNode)

	//path<-{}

	//currentNode <-goalNode

	//while currentNode!=null do

		//add currentNode to the beginning of path

		//currentNode<-currentNode.cameFrom

	//end while

	//return path

//end procedure