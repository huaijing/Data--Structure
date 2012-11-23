// BinarySearchTree.cpp : 定义控制台应用程序的入口点。
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

BinarySearchTree *Search(BinarySearchTree* root,BinarySearchTree* k)
{
	if(root == NULL || k == NULL) 
		return NULL;

	BinarySearchTree* t = NULL;
	if(k->value == root->value) 
		return k;
	else if( k->value < root->value) 
		t = Search(root->leftChild,k);
	else
		t = Search(root->rightChild,k);

	return t;
}

BinarySearchTree *Min(BinarySearchTree* k)
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
		return Min(x->rightChild);
	else
	{
		BinarySearchTree *y = x->parent;
		while(y != NULL && x == y->rightChild)
		{
			x = y;
			y = y->parent;
		}
		if(y->value < x->value) return NULL;
		return y;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	BinarySearchTree *x1 = CreateBinarySearchTree(1);
	BinarySearchTree *x2 = CreateBinarySearchTree(3);
	BinarySearchTree *x3 = CreateBinarySearchTree(4);

	ConnectTreeNodes(x1,x2,x3);

	BinarySearchTree * x = Search(x1,x3);
	BinarySearchTree * x0 = Successor(x2);

	return 0;
}