#include "stdafx.h"
#include "BinaryTree.h"

#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	cout<<"Build the  tree\n";

	/*
			 2
		    /  \
		 4	    6
	    / \     / 
	   7   3   9

	*/
	BinaryTreeNode *x1 = CreateTreeNode(2);
	BinaryTreeNode *x2 = CreateTreeNode(4);
	BinaryTreeNode *x3 = CreateTreeNode(6);
	BinaryTreeNode *x4 = CreateTreeNode(7);
	BinaryTreeNode *x5 = CreateTreeNode(3);
	BinaryTreeNode *x6 = CreateTreeNode(9);

	ConnectTreeNodes(x1,x2,x3);
	ConnectTreeNodes(x2,x4,x5);
	ConnectTreeNodes(x3,x6,0);

	cout<<"\nVisit the tree recursively:";
	cout<<"\nPreOrder Visit:\n";
	PreOrder(x1);

	cout<<"\nInOrder Visit:\n";
	InOrder(x1);

	cout<<"\nPostOrder Visit:\n";
	PostOrder(x1);

	cout<<"\nLevelOrder Visit:\n";
	LevelOrder(x1);

	cout<<"\n\nHeight of the tree:\n";
	int h = Height(x1);
	cout<<h<<endl;

	DestroyTree(x1);
	
	cout<<"\nRebuild the tree.....\n"<<endl;
	const int len = 6;
	int pre[len] = {2,4,7,3,6,9};
	int in[len] = {7,4,3,2,9,6};
	
	BinaryTreeNode *root1 = NULL;
	bool result1 = ReBuild1(root1,pre,pre+len-1,in,in+len-1);

	int post[len] = {7,3,4,9,6,2};
	BinaryTreeNode *root2 = NULL;
	bool result2 = ReBuild2(root2,post,post+len-1,in,in+len-1);


	cout<<"Visit the tree iteratively:\n";
	cout<<"PreOrder_Iter Visit:\n";
	PreOrder_Iter(root1);
	cout<<"\nPreOrder_Iter2 Visit:\n";
	PreOrder_Iter2(root1);

	cout<<"\nInOrder_Iter Visit:\n";
	InOrder_Iter(root1);

	cout<<"\nPostOrder_Iter Visit:\n";
	PostOrder_Iter(root1);

	cout<<"\nPostOrder_Iter2 Visit:\n";
	PostOrder_Iter2(root1);
	return 0;
}