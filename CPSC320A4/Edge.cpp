
#include "stdafx.h"
#include "Edge.hpp"
#include "Node.hpp"

Edge::Edge(Node* startNode, Node* endNode) {
	start = startNode;
	end = endNode;
	cost = getHiringCost() + start->getPopulationCost();
}

int Edge::getHiringCost() {
	int numHired = end->workers - start->workers;
	int dischargeCost = 800;
	int hireCost = 500;
	int cost = 0;
	if (numHired < 0) {
		cost = -numHired * dischargeCost;
	}
	else if (numHired > 0) {
		cost = numHired * hireCost;
	}
	return cost;
}

Edge::~Edge() {
	delete this;
}
