#pragma once
#include "stdafx.h"
#include "Node.h"
#include "Map.h"
#include "PathfindingApp.h"

Node::Node(const Point& point)
	: point(point),
{
}
/*
Node::Node(int x, int y)
	:point(x, y)
{
}
*/
Node::~Node()
{
}
