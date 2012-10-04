//Graph.cpp
#include "stdafx.h"

#include <fstream>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;

#include "Graph.h"

void Graph::ReadMatrix(string file,vector<vector<int>> &weight)
{
	fstream cin(file.c_str());
	int n;
	cin>>n;

	weight.resize(vertexNumber);
	for (unsigned int i = 0;i < weight.size();i++)
	{
		weight[i].resize(vertexNumber);
	}

	//init weight
	for (unsigned int i = 0;i < weight.size();i++)
	{
		for (unsigned int j = 0;j < weight[i].size();j++)
		{
			cin>>weight[i][j];
			cout<<weight[i][j]<<"\t";
		}
		cout<<endl;
	}
}

void Graph::LoadGraph(string file,int flag)
{
	fstream cin(file.c_str());
	cin>>vertexNumber;
	
	if (flag == 1)
	{
		cout<<"1. The Adjacency Matrix:\n";
		ReadMatrix(file,adjacencyMatrix);
	}
	else if (flag == 2)
	{
		cout<<"\n\n2.The weighted Adjacency Matrix:\n";
		ReadMatrix(file,weightedAdjacencyMatrix);
	}
	else 
	{
		cout<<"\n\n3.The weighted Directed Adjacency Matrix:\n";
		ReadMatrix(file,weightedDirectedAdjacencyMatrix);
	}
}

void Graph::BreadthFirstSearch()
{
	cout<<"Breadth first search graph:\n ";
	if (adjacencyMatrix.size() == 0)
	{
		return;
	}

	//visited map
	vector<bool> visitedMap(vertexNumber);
	for (int i = 0;i < vertexNumber;i++)
	{		
		visitedMap[i] = false;
	}

	queue<int> Q;

	//visit the first node: 0
	int begin = 0;
	Q.push(begin);
	visitedMap[begin] = true;
	cout<<begin<<" ";

	int temp = 0;
	while (!Q.empty())
	{
		temp = Q.front();	

		//find all the vertices adjacented to temp and have not been visied
		for (int i = 0;i < vertexNumber;i++)
		{
			if (adjacencyMatrix[temp][i] != 0 && !visitedMap[i])
			{
				Q.push(i);		
				visitedMap[i] = true;
				cout<<i<<" ";
			}
		}

		Q.pop();
	}
}

void Graph::DepthFirstSearch()
{
	cout<<"\nDepth first search graph:\n ";
	if (adjacencyMatrix.size() == 0)
	{
		return;
	}

	//visited map
	vector<bool> visitedMap(vertexNumber);
	for (int i = 0;i < vertexNumber;i++)
	{		
		visitedMap[i] = false;
	}

	//visit the first node: 0
	int begin = 0;
	visitedMap[begin] = true;
	cout<<begin<<" ";

	DFS(begin,visitedMap);
}

void Graph::DFS(int begin, vector<bool> &visitedMap)
{
	//find the first node connected to begin
	int next = -1;
	for (int i = 0;i < vertexNumber;i++)
	{
		if (adjacencyMatrix[begin][i] != 0 && !visitedMap[i])
		{
			next = i;
			break;
		}
	}

	while (next != -1)
	{
		visitedMap[next] = true;
		cout<<next<<" ";
		DFS(next,visitedMap);
		
		next = -1;

		//find the next node connected to begin             //Attention!!!
		for (int i = 0;i < vertexNumber;i++)
		{
			if (adjacencyMatrix[begin][i] != 0 && !visitedMap[i])
			{
				next = i;
				break;
			}
		}
	}
}

void Graph::DepthFirstSearchIteratively()
{
	cout<<"\nDepth first search graph iteratively:\n ";
	if (adjacencyMatrix.size() == 0)
	{
		return;
	}

	//visited map
	vector<bool> visitedMap(vertexNumber);
	for (int i = 0;i < vertexNumber;i++)
	{		
		visitedMap[i] = false;
	}

	//visit the first node: 0
	int begin = 0;
	visitedMap[begin] = true;
	cout<<begin<<" ";

	DFSIteratively(begin,visitedMap);
}

void Graph::DFSIteratively(int begin, vector<bool> &visitedMap)
{	
	int visitedNodeNum = 1; //numbers of nodes have been visited

	//find the first node connected to begin
	int next = -1;
	for (int i = 0;i < vertexNumber;i++)
	{
		if (adjacencyMatrix[begin][i] != 0 && !visitedMap[i])
		{
			next = i;
			break;
		}
	}

	if (next == -1)
	{
		return;
	}

	stack<int> S;
	while (visitedNodeNum < visitedMap.size())
	{
		if (next != -1)
		{		
			visitedMap[next] = true;	
			S.push(next);
			visitedNodeNum++;
			cout<<next<<" ";
		}

		next = -1;
		//find the next node connected to S.top() 
		for (int i = 0;i < vertexNumber;i++)
		{
			if (adjacencyMatrix[S.top()][i] != 0 && !visitedMap[i])
			{
				next = i;
				break;
			}
		}
		if (next == -1 && !S.empty())
		{
			S.pop();        //Backtracking
		}
	}
}