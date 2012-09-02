#include "stdafx.h"
#include <iostream>
#include <assert.h>
using namespace std;

#include "Prim.h"

void Prim::Init(const int vertexNumber)
{
	N = vertexNumber;
	if (N == 0)
	{
		cout<<" The graph is NULL!\n";
		return;
	}

	//init parent , key , isInTree	
	key = new int[N];
	parent = new int[N];
	isInTree = new bool[N];
	for (int i = 0;i < N;i++)
	{
		key[i] = maxWeight;  //Initialize d with infinity
		parent[i] = i;    //root is -1
		isInTree[i] = false;   //all vertices are NOT in the minimum spanning tree
	}

	totalCost = 0;
}

void Prim::UpdateDistances(int target,const vector<vector<int>> weight)
{
	for(int i = 0;i < N;i++)
	{
		if (weight[target][i] != 0 && weight[target][i] < key[i]) 
		{
			key[i] = weight[target][i];  //update the min distance to minimum spanning tree
			parent[i] = target;
		}
	}
}

void Prim::MSTPrim(const int vertexNumber,const vector<vector<int>> weightedAdjacencyMatrix,const int startVertex)
{
	if (startVertex >= vertexNumber){
		return;
	}

	//init the minimum spanning tree
	Init(vertexNumber);

	//put the first vertex in the tree
	key[startVertex] = 0;
	isInTree[startVertex] = 1;
	UpdateDistances(startVertex,weightedAdjacencyMatrix);

	int totalVertex = 1;
	for (;totalVertex < N;totalVertex++)
	{
		//Extract-Min: find the min distance to minimum spanning tree
		int min = -1;
		for (int i = 0; i < N;i++)
		{
			if (!isInTree[i])
			{
				if (min == -1 || key[min] > key[i])
				{
					min = i;
				}
			}
		}
		
		//add the vertex to the minimum spanning tree
		Edge *e = new Edge(parent[min],min,key[min]);
		MST.push_back(e);
		isInTree[min] = true;
		totalCost += key[min];

		//update the weight
		UpdateDistances(min,weightedAdjacencyMatrix);
	}
	
	//all the vertices should be in the minimum spanning tree
	assert(totalVertex == vertexNumber);

	Print();

	//free
	delete []key;
	delete []parent;
	delete []isInTree;
	MST.clear();
}

void Prim::Print()
{
	cout<<"\nPrim:\n";
	unsigned int n = MST.size();

	/* Add the first vertex to the tree */
	cout<<"adding vertex "<<MST[0]->u<<endl;

	for (unsigned int i = 0;i < n;i++)
	{
		cout<<"adding edge  "<<MST[i]->u<<" to "<<MST[i]->v<<": cost "<<MST[i]->weight<<endl;
	}

	cout<<"total cost: "<<totalCost<<endl;
 }