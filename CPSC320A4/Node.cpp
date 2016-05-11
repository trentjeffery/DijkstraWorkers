#pragma once
#include "stdafx.h"
#include "Node.hpp"
//#include "Edge.cpp"

Node::Node(int workMonth, int numWorkers)
{
	month = workMonth;
	workers = numWorkers;
	costToNode = NULL;
	prevNode = NULL;
	incomingEdges = std::vector < Edge* > ();
}

Node::~Node()
{
	delete this;
}


int Node::getRequiredPopulation() {
	int pop = 0;
	switch (month){
	case FEB:
		pop = 3;
		break;
	case MAR:
		pop = 4;
		break;
	case APR:
		pop = 6;
		break;
	case MAY:
		pop = 7;
		break;
	case JUN:
		pop = 4;
		break;
	case JUL:
		pop = 6;
		break;
	case AUG:
		pop = 2;
		break;
	case SEP:
		pop = 3;
		break;
	}
	return pop;
}

int Node::getPopulationCost(){
	int extraWorkers = workers - getRequiredPopulation();
	int underCost = 2000;
	int overCost = 1000;
	int cost = 0;
	if (extraWorkers < 0) {
		cost = -extraWorkers * underCost;
	}
	else if (extraWorkers > 0) {
		cost = extraWorkers *overCost;
	}
	return cost;
}