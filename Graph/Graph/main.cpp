#include "stdafx.h"

#include <string>
#include <iostream>
using namespace std;

#include "Graph.h"
#include "Kruskal.h"
#include "Prim.h"
#include "Dijkstra.h"

int _tmain(int argc, _TCHAR* argv[])
{
	string file = "adjacencyMatrix.txt";
	Graph G;
	G.LoadGraph(file,1);

	cout<<"*********************************************************\n";
	cout<<"\t\tVisit Graph\n";
	cout<<"*********************************************************\n";
	G.BreadthFirstSearch();
	G.DepthFirstSearch();

	string file2 = "weightedAdjacencyMatrix.txt";
	G.LoadGraph(file2,2);

	cout<<"*********************************************************\n";
	cout<<"\t\tMinimum spanning tree\n";
	cout<<"*********************************************************\n";
	Kruskal k;
	k.MSTKruskal(G.vertexNumber,G.weightedAdjacencyMatrix);

	Prim p;
	int startVertex = 0;
	p.MSTPrim(G.vertexNumber,G.weightedAdjacencyMatrix,startVertex);

	string file3 = "weightedDirectedGraph.txt";
	G.LoadGraph(file3,3);

	cout<<"*********************************************************\n";
	cout<<"\t\tSingle-source shortest path \n";
	cout<<"*********************************************************\n";
	Dijkstra d;
	d.SSSPDijkstra(G.vertexNumber,G.weightedDirectedAdjacencyMatrix,startVertex);

	return 0;
}