#pragma once;

#include <iostream>
using namespace std;

struct ListNode
{
	int       data;
	ListNode* next;
};

ListNode* CreateListNode(int value)
{
	ListNode* pNode = new ListNode();
	pNode->data = value;
	pNode->next = NULL;

	return pNode;
}

void ConnectListNodes(ListNode* pCurrent, ListNode* pNext)
{
	if(pCurrent == NULL)
	{
		cout<<"Error to connect two nodes."<<endl;
		return;
	}
	pCurrent->next = pNext;
}

//find the middle element of the chain
ListNode *FindMiddleNode(ListNode *head);

//find the k-th node to tail
ListNode* FindKthNodeToTail(ListNode *head, int k);

//check if a list has a circle
bool IsCircled(ListNode head);

//check if a list has a circle, if not, return NULL, if exist, return the entrance of the circle
ListNode *FindHeadOfCircle(ListNode *head);

//Delete a node in the middle of a list, given only access to that node.
bool DeleteNode(ListNode *node);

//reverse a chain
ListNode *ReverseList(ListNode *head);

