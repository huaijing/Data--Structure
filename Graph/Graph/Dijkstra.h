//Directed graph: Single-source shortest path 

/*

The input file (weightedDirectedGraph.txt) look something like this
5
999	10	999	5	999
999	999	1	2	999
999	999	999	999	4
999	3	9	999	2
7	999	6	999	999

The first line contains n, the number of vertices.
Next is an n x n matrix contains the distances between the vertices

*/

#pragma once;

#include "Edge.h"
#include "Graph.h"

//The algorithm repeatedly selects the vertex u( belongs to V - S) with the minimum shortest-path estimate,
  //adds u to S, and relaxes all edges leaving u.
class Dijkstra
{
public:
	void initSingleSource(const int vertexNumber,const vector<vector<int>> weight,const int startingVertex);

	void SSSPDijkstra(const int vertexNumber,const vector<vector<int>> weightedAdjacencyMatrix,const int startVertex);

	// Find the node with the smallest distance,remove it, and return it.
	Node* ExtractMin();
	
	// Return all nodes adjacent to 'node' which are still in the 'nodes' collection.
	vector<Node*>* AdjacentRemainingNodes(Node* node);	

	// Does the 'nodes' vector contain 'node'
	bool Contains(vector<Node*>& nodes, Node* node);

	void PrintShortestPath(Node* destination);

private:
	int N;  //number of vertex

	vector<Node*> nodes;
	vector<Edge*> edges;
};