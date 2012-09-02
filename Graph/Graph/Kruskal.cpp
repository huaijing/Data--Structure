#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;

#include "Kruskal.h"

void Kruskal::Init(const int vertexNumber,const vector<vector<int>> weightedAdjacencyMatrix)
{
	//init the edges 
	for (unsigned int i = 0;i < weightedAdjacencyMatrix.size();i++)
	{
		for (unsigned int j = i; j < weightedAdjacencyMatrix[i].size();j++)
		{
			if (weightedAdjacencyMatrix[i][j] < maxWeight)
			{
				int u = i;
				int v = j;
				int w = weightedAdjacencyMatrix[i][j];
				Edge *e = new Edge(u,v,w);
				edgeSet.push_back(e);
			}
		}
	}

	N = vertexNumber;
	E = edgeSet.size();

	if (E == 0 || N == 0)
	{
		cout<<" The graph is NULL!\n";
		return;
	}

	//init parent
	parent = new int[N];
	for (int i = 0;i < N;i++)
	{
		parent[i] = i;
	}

	totalCost = 0;
}

int Kruskal::FindSet(int x, int *parent)  //find the root of the tree which the vertex belongs to.
{
	if (x != parent[x])
	{
		parent[x] = FindSet(parent[x],parent);
	}
	return parent[x];
}

void Kruskal::MSTKruskal(const int vertexNumber,const vector<vector<int>> weightedAdjacencyMatrix)
{
	//init the minimum spanning tree
	Init(vertexNumber,weightedAdjacencyMatrix);

	//sort the edges of edgeSet into nondecreasing by weight
	sort(edgeSet.begin(),edgeSet.end(),less_second);

	//add the edge in order
	for (int i = 0; i < E;i++)
	{
		Edge *e = edgeSet[i];
		int pu = FindSet(e->u,parent); //the root of the tree u belongs to
		int pv = FindSet(e->v,parent); //the root of the tree v belongs to

		if (pu != pv)  //u and v are in the different tree, otherwise the circle will occur.
		{
			MST.push_back(e);
			totalCost += e->weight;

			//union the tree of u and v
			parent[pu] = parent[pv];
		}
	}

	//print the minimum spanning tree 
	Print();

	//free
	delete []parent;
	edgeSet.clear();
	MST.clear();
}

void Kruskal::Print()
{
	cout<<"Kruskal:\n";
	for(unsigned int i=0; i < MST.size(); i++)
	{
		cout<<"adding edge  "<<MST[i]->u<<" to "<<MST[i]->v<<": cost "<<MST[i]->weight<<endl;
	}
	cout<<"total cost: "<<totalCost<<endl;
}