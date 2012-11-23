#pragma once;

struct BinarySearchTree
{
	int value;
	BinarySearchTree *leftChild;
	BinarySearchTree *rightChild;
	BinarySearchTree *parent;	
};

BinarySearchTree *CreateBinarySearchTree(int value);

void ConnectTreeNodes(BinarySearchTree* pParent, BinarySearchTree* pLeft,BinarySearchTree* pRight);

//minimum node of the tree k
BinarySearchTree *Minimum(BinarySearchTree* k);

//search node
bool Search(BinarySearchTree* root,BinarySearchTree* k);

//find successor
BinarySearchTree *Successor(BinarySearchTree* k);

//insert node
void Insert(BinarySearchTree *root,BinarySearchTree *t);