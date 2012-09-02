#include "stdafx.h"
#include "BinaryTree.h"

#include <queue>
#include <stack>
#include <iostream>
using namespace std;

BinaryTreeNode* CreateTreeNode(int value)
{
	BinaryTreeNode *t = new BinaryTreeNode();  //new 
	t->m_nValue = value;
	t->m_pLeft = NULL;   //set NULL
	t->m_pRight = NULL;

	return t;
}

void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft,BinaryTreeNode* pRight)
{
	if (pParent == NULL)
	{
		return;
	}

	pParent->m_pLeft = pLeft;
	pParent->m_pRight = pRight;

	//prevent visit the child node
	pLeft = pRight = 0;
}

void PrintTreeNode(BinaryTreeNode *pNode)
{
	if (pNode)
	{
		cout<<pNode->m_nValue<<" ";
	}
}

void PreOrder(BinaryTreeNode* pNode)
{
	if (pNode)
	{
		PrintTreeNode(pNode);

		if (pNode->m_pLeft)
		{
			PreOrder(pNode->m_pLeft);
		}
		if (pNode->m_pRight)
		{
			PreOrder(pNode->m_pRight);
		}
	}
}

void InOrder(BinaryTreeNode* pNode)
{
	if (pNode)
	{
		if (pNode->m_pLeft)
		{
			InOrder(pNode->m_pLeft);
		}

		PrintTreeNode(pNode);

		if (pNode->m_pRight)
		{
			InOrder(pNode->m_pRight);
		}
	}
}

void PostOrder(BinaryTreeNode* pNode)
{
	if (pNode)
	{
		if (pNode->m_pLeft)
		{
			PostOrder(pNode->m_pLeft);
		}

		if (pNode->m_pRight)
		{
			PostOrder(pNode->m_pRight);
		}	

		PrintTreeNode(pNode);
	}
}

void LevelOrder(BinaryTreeNode* pNode)
{
	if (!pNode)
	{
		return;
	}

	queue<BinaryTreeNode *> Q;
	Q.push(pNode);

	BinaryTreeNode *pTemp = NULL;
	while (!Q.empty())
	{
		pTemp = Q.front();    //get the front element in the queue
		PrintTreeNode(pTemp);

		if (pTemp->m_pLeft)
		{
			Q.push(pTemp->m_pLeft);
		}
		if (pTemp->m_pRight)
		{
			Q.push(pTemp->m_pRight);
		}

		Q.pop();  //pop the the front element in the queue
	}
}

void VisitTreeNode(BinaryTreeNode *pNode)
{
	if (pNode)
	{
		cout<<"value of this node is :"<<pNode->m_nValue<<endl;
		if (pNode->m_pLeft)
		{
			cout<<"value of its left child is:"<<pNode->m_pLeft->m_nValue<<endl;
		}
		else
			cout<<"left child is null.\n";
		if (pNode->m_pRight)
		{
			cout<<"value of its right child is:"<<pNode->m_pRight->m_nValue<<endl;
		}
		else
			cout<<"right child is null.\n";
	}
	else
		cout<<"this node is null.\n";

	cout<<"\n";
}

int Height(BinaryTreeNode *pNode)
{
	if (!pNode)
	{
		return 0;
	}

	int hl = 0;
	int hr = 0;

	//height of the left subtree
	if (pNode->m_pLeft)
	{
		hl = Height(pNode->m_pLeft);
	}

	//height of the right subtree
	if (pNode->m_pRight)
	{
		hr = Height(pNode->m_pRight);
	}

	return max(hl,hr)+1;  //max of subtree + 1
}

void DestroyTree(BinaryTreeNode* pRoot)
{
	if(pRoot != NULL)
	{
		BinaryTreeNode* pLeft = pRoot->m_pLeft;
		BinaryTreeNode* pRight = pRoot->m_pRight;

		delete pRoot;
		pRoot = NULL;

		DestroyTree(pLeft);
		DestroyTree(pRight);
	}
}

bool ReBuild1(BinaryTreeNode* &root, int *aPre, int *aPreEnd, int *aIn, int *aInEnd)
{
	//check length
	if (aPreEnd - aPre != aInEnd - aIn)
	{
		cout<<"The length of the two traverse results are not equal."<<endl;
		root = NULL;
		return false;
	}
	
	//end 
	if (aPreEnd < aPre || aInEnd < aIn)
	{
		root = NULL;
		return true;
	}

	//init the root node
	root = new BinaryTreeNode();
	root->m_nValue = *aPre;
	root->m_pLeft = NULL;
	root->m_pRight = NULL;

	//calculate length of the left sub-tree 
	int *tempIn = aIn;
	int count = 0;
	while (tempIn <= aInEnd && *tempIn != *aPre)
	{
		tempIn++;
		count++;
	}
	
	if (tempIn > aInEnd)
	{
		return false;
	}
	
	bool isLeft = ReBuild1(root->m_pLeft,aPre+1,aPre+count,aIn,tempIn-1);
	bool isRight = ReBuild1(root->m_pRight,aPre+count+1,aPreEnd,tempIn+1,aInEnd);

	return (isLeft & isRight);
}

bool ReBuild2(BinaryTreeNode* &root, int *aPost, int *aPostEnd, int *aIn, int *aInEnd)
{
	//check length
	if (aPostEnd - aPost != aInEnd - aIn)
	{
		cout<<"The length of the two traverse results are not equal."<<endl;
		root = NULL;
		return false;
	}

	//end
	if (aPostEnd < aPost || aInEnd < aIn)
	{
		root = NULL;
		return true;
	}
	
	//init root node
	root = new BinaryTreeNode();
	root->m_nValue = *aPostEnd;
	root->m_pLeft = NULL;
	root->m_pRight =NULL;

	//calculate length of left sub-tree
	int *tempIn = aIn;
	int count = 0;
	while (tempIn <= aInEnd && *tempIn != *aPostEnd)
	{
		tempIn++;
		count++;
	}

	if (tempIn > aInEnd)
	{
		return false;
	}

	bool isLeft = ReBuild2(root->m_pLeft,aPost,aPost+count-1,aIn,tempIn-1);
	bool isRight = ReBuild2(root->m_pRight,aPost+count,aPostEnd-1,tempIn+1,aInEnd);

	return (isLeft & isRight);
}

void PreOrder_Iter(BinaryTreeNode* pNode)
{
	if (pNode == NULL)
	{
		return;
	}
	
	stack<BinaryTreeNode *> s;
	s.push(pNode);

	while (!s.empty())
	{
		BinaryTreeNode *tmp = s.top();
		s.pop();

		PrintTreeNode(tmp);
		if (tmp->m_pRight)
		{
			s.push(tmp->m_pRight);
		}

		if (tmp->m_pLeft)
		{
			s.push(tmp->m_pLeft);
		}
	}
}

void PreOrder_Iter2(BinaryTreeNode* pNode)
{
	if (pNode == NULL)
	{
		return;
	}

	stack<BinaryTreeNode *> s;
	s.push(pNode);

	while (!s.empty())
	{
		BinaryTreeNode *tmp = s.top();
		s.pop();
		
		while(tmp)
		{
			PrintTreeNode(tmp);
			if (tmp->m_pRight)
			{
				s.push(tmp->m_pRight);
			}

			tmp = tmp->m_pLeft;
		}		
	}
}

void InOrder_Iter(BinaryTreeNode* pNode)
{
	if (pNode == NULL)
	{
		return;
	}

	stack<BinaryTreeNode *> s;
	BinaryTreeNode *tmp = pNode;
	
	while (tmp)
	{
		s.push(tmp);
		tmp = tmp->m_pLeft;
	}

	while (!s.empty())
	{
		tmp = s.top();
		s.pop();

		PrintTreeNode(tmp);	
	
		//store the right sub-tree
		if (tmp->m_pRight)
		{
			tmp = tmp->m_pRight;
			while (tmp)
			{
				s.push(tmp);
				tmp = tmp->m_pLeft;
			}
		}		
	}
}

void PostOrder_Iter(BinaryTreeNode* pNode)
{
	//exception
	if (!pNode)
	{
		return;
	}
	
	stack<BinaryTreeNode *> s;
	BinaryTreeNode *tmp = pNode;

	while (tmp)
	{
		s.push(tmp);
		tmp = tmp->m_pLeft;
	}

	BinaryTreeNode *p = NULL;
	BinaryTreeNode *q = NULL; //the last node has been visited
	while (!s.empty())
	{
		if (NULL == s.top()->m_pRight || q == s.top()->m_pRight) //right child of the top node is NULL or has been visited
		{
			q = s.top();
			s.pop();
			PrintTreeNode(q);
		}

		else
		{
			//store the right sub-tree
			p = s.top()->m_pRight;
			while (p)
			{
				s.push(p);
				p = p->m_pLeft;
			}
		}
	}
}

void PostOrder_Iter2(BinaryTreeNode* pNode)
{
	if (pNode == NULL)
	{
		return;
	}

	stack<BinaryTreeNode *> s;
	BinaryTreeNode *tmp = pNode;

	while (1)
	{
		if (tmp)
		{
			if (tmp->m_pRight)
			{
				s.push(tmp->m_pRight);
			}

			s.push(tmp);
			tmp = tmp->m_pLeft;
			continue;
		}

		if (s.empty())
		{
			return;
		}

		tmp = s.top();
		s.pop();


		if (tmp->m_pRight && !s.empty() && tmp->m_pRight == s.top())  //right child of tmp has not been visited 
		{
			s.pop();
			s.push(tmp);
			tmp = tmp->m_pRight;
		}
		else   //right child of tmp has been visited 
		{
			PrintTreeNode(tmp);
			tmp = NULL;
		}
	}
}