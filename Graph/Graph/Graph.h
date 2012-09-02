#pragma once;

#include <vector>
#include <string>
using namespace std;

class Graph
{
	//friend class Kruskal;
	//friend class Prim;
public:
	
	//flag: 1 adjacencyMatrix ; 2 weightedAdjacencyMatrix; 3 : weightedDirectedAdjacencyMatrix
	void LoadGraph(string file,int flag);
	void ReadMatrix(string file,vector<vector<int>> &weight);

	//visit
	void BreadthFirstSearch();
	void DepthFirstSearch();
	void DFS(int begin, vector<bool> &visitedMap);

//private:
	int vertexNumber;
	vector<vector<int>> adjacencyMatrix;
	vector<vector<int>> weightedAdjacencyMatrix;
	vector<vector<int>> weightedDirectedAdjacencyMatrix;
};