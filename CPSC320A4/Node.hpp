#ifndef NODE_H
#define NODE_H
#include "Edge.hpp"
#include <vector>
#define FEB 2
#define MAR 3
#define APR 4
#define MAY 5
#define JUN 6
#define JUL 7
#define AUG 8
#define SEP 9

class Node
{
public:
	Node(int workMonth, int numWorkers);
	~Node();
	int getRequiredPopulation();
	int getPopulationCost();

	int month;
	int workers;
	int costToNode;
	Node* prevNode;
	std::vector<Edge*> incomingEdges;
	//int requiredPopulation;
	//int populationCost;
};

#endif

