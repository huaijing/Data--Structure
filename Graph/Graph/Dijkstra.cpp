#include "stdafx.h"

#include <iostream>
using namespace std;
#include "Dijkstra.h"


void Dijkstra::initSingleSource(const int vertexNumber,const vector<vector<int>> weight,const int startingVertex)
{
	N = vertexNumber;
	
	//init nodes
	for (int i = 0;i < N;i++)
	{
		Node *n = new Node(i);
		nodes.push_back(n);
	}
	
	//init edges
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < N;j++)
		{
			if (weight[i][j] < maxWeight)
			{
				Edge *e = new Edge(nodes[i],nodes[j],weight[i][j]);
				edges.push_back(e);
			}
		}
	}
    
	Node *n = nodes[startingVertex];
	n->distanceFromStart = 0;
}

void Dijkstra::SSSPDijkstra(const int vertexNumber,const vector<vector<int>> weightedAdjacencyMatrix,const int startVertex)
{
	//init 
	initSingleSource(vertexNumber,weightedAdjacencyMatrix,startVertex);

	while (nodes.size() > 0)
	{
		// Find the node with the smallest distance
		Node* smallest = ExtractMin();

		//all nodes adjacent to 'node' which are still in the 'nodes' collection.
		vector<Node*> *adjacentNodes = AdjacentRemainingNodes(smallest);

		//Relax(u,v,w), relaxes all edges leaving u.
		const int size = adjacentNodes->size();
		for (int i = 0; i < size; i++)
		{
			Node* adjacent = adjacentNodes->at(i);
			int w = weightedAdjacencyMatrix[smallest->id][adjacent->id];
			int distance = w + smallest->distanceFromStart;

			if (distance < adjacent->distanceFromStart)
			{
				adjacent->distanceFromStart = distance;
				adjacent->preDecessor = smallest;
			}
		}
		delete adjacentNodes;
		
		PrintShortestPath(smallest);
	}

	//free
	nodes.clear();
	edges.clear();
}

Node* Dijkstra::ExtractMin()
{
	int size = nodes.size();
	if (size == 0) 
	{
		return NULL;
	}

	int smallestPosition = 0;
	Node* smallest = nodes[0];
	for (int i = 1; i < size; i++)
	{
		Node* current = nodes[i];
		if (current->distanceFromStart < smallest->distanceFromStart)
		{
			smallest = current;
			smallestPosition = i;
		}
	}
	nodes.erase(nodes.begin() + smallestPosition);
	return smallest;
}

vector<Node*>* Dijkstra::AdjacentRemainingNodes(Node* node)
{
	vector<Node*>* adjacentNodes = new vector<Node*>();
	const int size = edges.size();
	for(int i = 0; i < size; i++)
	{
		Edge* edge = edges[i];
		Node* adjacent = NULL;
		if (edge->node1 == node)
		{
			adjacent = edge->node2;
		}

		//Adjacent and have not been stored
		if (adjacent&& Contains(nodes, adjacent))
		{
			adjacentNodes->push_back(adjacent);
		}
	}
	return adjacentNodes;
}


bool Dijkstra::Contains(vector<Node*>& nodes, Node* node)
{
	const int size = nodes.size();
	for(int i = 0; i < size; i++)
	{
		if (node == nodes[i])
		{
			return true;
		}
	}
	return false;
}

void Dijkstra::PrintShortestPath(Node* destination)
{
	Node* previous = destination;
	cout << "Node ID: "<< destination->id<< ": distance from start: " 
		<< destination->distanceFromStart << endl;
	cout<<"	    shortest path reversely:  ";
	while (previous)
	{
		cout << previous->id << "   ";
		previous = previous->preDecessor;
	}
	cout <<"\n\n";;
}