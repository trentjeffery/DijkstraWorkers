#ifndef EDGE_H
#define EDGE_H

class Node;

class Edge
{
public:
	Edge(Node* startNode, Node* endNode);
	~Edge();
	int getHiringCost();

	Node* start;
	Node* end;
	int cost;
};

#endif
