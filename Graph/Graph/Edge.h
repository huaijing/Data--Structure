#pragma once;

const int maxWeight = 999;

struct Node
{
	int id;
	Node* preDecessor; //preDecessor[i] holds the index of the vertex i would have to be
							//linked to in order to get a distance of key[i] 

	int distanceFromStart;  // distance[i] is the distance between vertex i and the starting vertex

	Node(int id): id(id), preDecessor(NULL), distanceFromStart(maxWeight){ }
};

struct Edge
{
	int u; //two vertices
	int v;

	Node* node1;
	Node* node2;

	int weight;  //cost

	Edge(int a,int b,int w):u(a),v(b),weight(w){ };

	Edge(Node* node1, Node* node2, int weight) 
		: node1(node1), node2(node2), weight(weight){ }
	~Edge() {};

	bool operator< (const Edge* rhs){
		return this->weight < rhs->weight;
	}
};

static bool less_second(const Edge * e1, const Edge * e2) 
{
	return e1->weight < e2->weight;
}