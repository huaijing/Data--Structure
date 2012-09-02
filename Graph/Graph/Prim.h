//Undirected graph: Minimum spanning tree 
/*
The input file (weightedAdjacencyMatrix.txt) look something like this
9 
999	4	999	999	999	999	999	8	999	   
4	999	8	999	999	999	999	11	999	   
999	8	999	7	999	4	999	999	2	   
999	999	7	999	9	14	999	999	999	   
999	999	999	9	999	10	999	999	999	   
999	999	4	14	10	999	2	999	999	   
999	999	999	999	999	2	999	1	6	   
8	11	999	999	999	999	1	999	7	   
999	999	2	999	999	999	6	7	999

The first line contains n, the number of vertices.
Next is an n x n matrix contains the distances between the vertices.
*/

#pragma once;

#include "Edge.h"
#include "Graph.h"

//the tree starts from an arbitrary root vertex r and grows until the tree spans all the vertices in V. 
//At each step, a light edge is added to the tree A that connects A to an isolated vertex of GA = (V, A).
class Prim
{
public:
	void Init(const int vertexNumber);

	//update the min distance of each vertex (NOT in the tree) to minimum spanning tree as the vertex target is added!
	void UpdateDistances(int target,const vector<vector<int>> weight); 

	void MSTPrim(const int vertexNumber,const vector<vector<int>> weightedAdjacencyMatrix,const int startVertex);

	void Print();

private:
	vector<Edge*> MST; //Minimum spanning tree 
	int totalCost;    //the cost of minimum spanning tree 

	int N;  //number of vertex

	int *parent;  //parent[i] holds the index of the vertex i would have to be
					//linked to in order to get a distance of key[i] 

	int *key; // key[i] is the distance between vertex i and the minimum spanning
					//tree; this is initially infinity (maxWeight); if i is already in
					//the tree, then d[i] is undefined;

	bool *isInTree; //isInTree[i] is 1 if the vertex i is already in the minimum
					//spanning tree; 0 otherwise
};