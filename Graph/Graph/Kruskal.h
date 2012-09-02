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
Next is an n x n matrix contains the distances between the vertices
*/

#pragma once;

#include "Edge.h"
#include "Graph.h"

//select minimal cost edge int the graph.
//if adding the two vertices of this edge form a circle, then abandon this edge.

class Kruskal
{
public:
	void Init(const int vertexNumber, const vector<vector<int>> weightedAdjacencyMatrix);
	int FindSet(int x, int *parent);   //find the root of the tree which the vertex belongs to.
	void MSTKruskal(const int vertexNumber,const vector<vector<int>> weightedAdjacencyMatrix);
	void Print();

private:
	vector<Edge*> edgeSet;
	vector<Edge*> MST; //Minimum spanning tree 
	int totalCost;    //the cost of minimum spanning tree 

	int N;  //number of vertex
	int E;	//number of edge
	int *parent;  //parent of each vertex
};