// BinarySearchTree.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include"BinarySearchTree.h"

BinarySearchTree *CreateBinarySearchTree(int value)
{
	BinarySearchTree *t = new BinarySearchTree();
	t->value = value;
	t->leftChild = NULL;
	t->rightChild = NULL;
	t->parent = NULL;

	return t;
}

void ConnectTreeNodes(BinarySearchTree* pParent, BinarySearchTree* pLeft,BinarySearchTree* pRight)
{
	pParent->leftChild = pLeft;
	pParent->rightChild = pRight;
	pLeft->parent = pParent;
	pRight->parent = pParent;
}

bool Search(BinarySearchTree* root,BinarySearchTree* k)
{
	if(root == NULL || k == NULL) 
		return NULL;

	bool isFind = false;
	if(k->value == root->value) 
		return true;
	else if( k->value < root->value) 
		isFind = Search(root->leftChild,k);
	else
		isFind = Search(root->rightChild,k);

	return isFind;
}

BinarySearchTree *Minimum(BinarySearchTree* k)
{
	if(k == NULL)  return NULL;
	while(k->leftChild != NULL)
	{
		k = k->leftChild;
	}

	return k;
}

BinarySearchTree *Successor(BinarySearchTree* x)
{
	if(x == NULL)  return NULL;
	if(x->rightChild != NULL)
		return Minimum(x->rightChild); //minimum of the right sub-tree
	else
	{
		BinarySearchTree *y = x->parent;
		while(y != NULL && x == y->rightChild) 
		{
			x = y;
			y = y->parent;
		}
		if(y->value < x->value) return NULL; //maybe have no successor
		return y;
	}
}

void Insert(BinarySearchTree *root,BinarySearchTree *t)
{
	if (root == NULL || t == NULL) return;
	
	//find proper location to insert
	BinarySearchTree *p = root;
	BinarySearchTree *q = NULL;
	while (p)
	{
		q = p;
		if (p->value == t->value)
		{
			return;
		}
		else if (p->value > t->value)
		{
			p = p->leftChild;
		}
		else
			p = p->rightChild;
	}

	t->parent = q;
	if (t->value < q->value)
	{
		q->leftChild = t;
	}
	else
	{
		q->rightChild = t;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	BinarySearchTree *x1 = CreateBinarySearchTree(2);
	BinarySearchTree *x2 = CreateBinarySearchTree(1);
	BinarySearchTree *x3 = CreateBinarySearchTree(4);

	ConnectTreeNodes(x1,x2,x3);

	cout<<Search(x1,x3)<<endl;
	BinarySearchTree * x0 = Successor(x2);

	BinarySearchTree *x4 = CreateBinarySearchTree(3);
	Insert(x1,x4);

	return 0;
}