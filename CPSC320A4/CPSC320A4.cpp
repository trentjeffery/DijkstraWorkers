// CPSC320A4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include "math.h"
#include <vector>
#include <list>
#include <stack>
#include "Edge.hpp"
#include "Node.hpp"


Node* Nodes[17];
//std::vector<Node*> explored;

void Dijkstra(Node* Nodes[]) {
	Nodes[0]->costToNode = 0;
	Nodes[0]->prevNode = NULL;
	for (int i = 1; i < 17; i++) {
	//	Nodes[i]->costToNode = pow(2.0, 30.0);
		if (!Nodes[i]->incomingEdges.empty()){
			Nodes[i]->prevNode = Nodes[i]->incomingEdges[0]->start;
			Nodes[i]->costToNode = Nodes[i]->prevNode->costToNode + Nodes[i]->incomingEdges[0]->cost;
		}
		else
			Nodes[i]->prevNode = NULL;
	}

	Node* curr;
	curr = Nodes[1];
	for (int i = 1; i < 17; i++) {
//		for (int j = i; j < 17; j++) {
//			if (Nodes[i]->costToNode < curr->costToNode)
//				curr = Nodes[i];
//		}
		curr = Nodes[i];
	//	explored.push_back(curr);
		for (Edge* e : Nodes[i]->incomingEdges) {
			if (e->start->costToNode + e->cost < curr->costToNode) {
				curr->costToNode = e->start->costToNode + e->cost;
				curr->prevNode = e->start;
			}
		}
	}
	std::stack<Node*> ret;
	Node* endnode = Nodes[16];
	Node* outputNode = endnode;
	int totalCost = 0;
	while (outputNode != NULL) {
		ret.push(outputNode);
		outputNode = outputNode->prevNode;
	}
	while (!ret.empty()) {
		outputNode = ret.top();
		std::cout << "Month: " << outputNode->month << " Workers: " << outputNode->workers << std::endl;
		ret.pop();
	}

	std::cout << "Total Cost: " << endnode->costToNode << std::endl;
	
}


int _tmain(int argc, _TCHAR* argv[])
{
	Node* feb3 = new Node(FEB, 3);
	Node* mar4 = new Node(MAR, 4);
	Node* mar5 = new Node(MAR, 5);
	Node* mar6 = new Node(MAR, 6);
	Node* apr5 = new Node(APR, 5);
	Node* apr6 = new Node(APR, 6);
	Node* apr7 = new Node(APR, 7);
	Node* may6 = new Node(MAY, 6);
	Node* may7 = new Node(MAY, 7);
	Node* jun4 = new Node(JUN, 4);
	Node* jun5 = new Node(JUN, 5);
	Node* jun6 = new Node(JUN, 6);
	Node* jun7 = new Node(JUN, 7);
	Node* jul5 = new Node(JUL, 5);
	Node* jul6 = new Node(JUL, 6);
	Node* aug4 = new Node(AUG, 4);
	Node* sep3 = new Node(SEP, 3);

	Nodes[0] = feb3;
	Nodes[1] = mar4;
	Nodes[2] = mar5;
	Nodes[3] = mar6;
	Nodes[4] = apr5;
	Nodes[5] = apr6;
	Nodes[6] = apr7;
	Nodes[7] = may6;
	Nodes[8] = may7;
	Nodes[9] = jun4;
	Nodes[10] = jun5;
	Nodes[11] = jun6;
	Nodes[12] = jun7;
	Nodes[13] = jul5;
	Nodes[14] = jul6;
	Nodes[15] = aug4;
	Nodes[16] = sep3;
	
	Nodes[0]->workers = Nodes[16]->workers = 3;
	for (int i = 1; i < 17; i++) {
		int month = Nodes[i]->month;
		int lastMonth = month - 1;
		for (int j =0; j < i; j++) {
			if (Nodes[j]->month == lastMonth) {
				int minWorkers = Nodes[j]->workers - (Nodes[j]->workers / 3);
				int maxWorkers = Nodes[j]->workers + 3;
				if (Nodes[i]->workers >= minWorkers && Nodes[i]->workers <= maxWorkers) {
					Edge* e = new Edge(Nodes[j], Nodes[i]);
					Nodes[i]->incomingEdges.push_back(e);
				}
			}
		}
	}

	Dijkstra(Nodes);
	return 0;
}

