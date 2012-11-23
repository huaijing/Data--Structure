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

//search node
BinarySearchTree *Search(BinarySearchTree* root,BinarySearchTree* k);

//find successor
BinarySearchTree *Successor(BinarySearchTree* k);

