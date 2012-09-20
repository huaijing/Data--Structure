// List.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "List.h"

//find the middle element of the chain
//use two index pSlow and pFast. pSlow take one step and pFast two steps during each loop.
//if pFast reach the end , return pSlow.
ListNode *FindMiddleNode(ListNode *head)
{
	if (head == NULL)
	{
		return NULL;
	}

	if (head->next == NULL) //special case: only one node
	{
		return head;
	}

	ListNode *pFast = head;
	ListNode *pSlow = head;
	while (pFast != NULL && pFast->next != NULL)
	{
		pSlow = pSlow->next;
		pFast = pFast->next->next;
	}
	return pSlow;
}

//find the k-th node to tail
ListNode* FindKthNodeToTail(ListNode *head, int k)
{
	if(head == NULL || k < 0)
	{
		return NULL;
	}

	ListNode *pFast = head;
	ListNode *pSlow = head;

	for (int i=0;i<k;i++)
	{
		if (pFast->next == NULL)  //length of the list is less than k
		{
			return NULL;
		}
		pFast = pFast->next;
	}

	while(pFast != NULL)
	{
		pFast = pFast->next;
		pSlow = pSlow->next;
	}

	return pSlow;
}

//check if a list has a circle
//use two index pSlow and pFast. pSlow take one step and pFast two steps during each loop.
//if pSlow meets pFast, there is a circle; otherwise, not a circle.
bool IsCircled(ListNode *head)
{
	if (head == NULL || head->next==NULL)
	{
		return false;
	}

	ListNode *pFast = head;
	ListNode *pSlow = head;
	while (pFast != NULL && pFast->next != NULL)
	{
		pFast = pFast->next->next;
		pSlow = pSlow->next;

		if (pFast == pSlow)
		{
			return true;
		}
	}

	return false;
}

//check if a list has a circle, if not, return NULL, if exist, return the entrance of the circle
/*
思路：
第一步：也是判断链表有环的经典方法。两个指针slow和fast，slow每次走一步，fast每次走两步，知道两个指针相遇。
第二步：fast指向表头，两个指针每次走一步，下一次相遇即为环开始的节点。
证明: 当fast若与slow相遇时，slow在环内循环了m(0<=m<n)圈，而fast已经在环内循环了n圈(1<=n)。
设环入口与相遇点距离为x，起点到环入口点的距离为a，环长为C。则有距离关系：
	x+a+nC = 2*(x+a+mC)
可以推出：
	x = (m-2n)C-k
由此可知，从链表头到环入口点等于 循环内环--相遇点到环入口点，于是我们从链表头、与相遇点分别设一个指针，
每次各走一步，两个指针必定相遇，且相遇第一点为环入口点。
*/
ListNode *FindHeadOfCircle(ListNode *head)
{
	if (head == NULL || head->next==NULL)
	{
		return NULL;
	}

	ListNode *pFast = head;
	ListNode *pSlow = head;
	bool isCircle = false;

	//find meeting point
	while (pFast != NULL && pFast->next != NULL)
	{
		pFast = pFast->next->next;
		pSlow = pSlow->next;
		
		if (pFast == pSlow)
		{
			isCircle = true;
			break;
		}
	}

	//the circle does not exist
	if (!isCircle)
	{
		return NULL;
	}

	//move pFast to head,the next point they meet will be the the entrance of the circle.
	pFast = head;
	while (pFast != pSlow)
	{
		pFast = pFast->next;
		pSlow = pSlow->next;
	}

	return pSlow;
}

//Delete a node in the middle of a list, given only access to that node.
bool DeleteNode(ListNode *node)
{
	//the problem can only be solved if the node to be deleted is not in the last of the list
	if (node == NULL || node->next == NULL) 
	{
		return false;
	}

	ListNode *nextNode = node->next;	
	node->data = nextNode->data;
	node->next = nextNode->next;

	delete nextNode;
	return true;
}

//reverse a chain
ListNode *ReverseList(ListNode *head)
{
	if (head == NULL || head->next == NULL)
	{
		return NULL;
	}

	ListNode *pPre = NULL;
	ListNode *pCur = head;
	while(pCur != NULL)
	{
		ListNode *pNext = pCur->next;
		pCur ->next = pPre;

		pPre = pCur;
		pCur = pNext;
	}

	return pPre;
}

//reverse a chain recursively
//http://bbs.sei.ynu.edu.cn/viewthread.php?tid=5568

ListNode *reverseRecursive(ListNode *pPre,ListNode *pCur)
{   
	if(pCur == NULL)
	{
		return NULL;
	}

	if(pCur->next == NULL)
	{
		pCur->next = pPre;
		return pCur;
	}
	else
	{
		ListNode *head = reverseRecursive(pCur,pCur->next);
		pCur->next = pPre;

		return head;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	ListNode *x1 = CreateListNode(5);
	ListNode *x2 = CreateListNode(4);
	ListNode *x3 = CreateListNode(8);
	ListNode *x4 = CreateListNode(1);
	ListNode *x5 = CreateListNode(6);
	//ListNode *x6 = CreateListNode(9);

	ConnectListNodes(x1,x2);
	ConnectListNodes(x2,x3);
	ConnectListNodes(x3,x4);
	ConnectListNodes(x4,x5);
	//ConnectListNodes(x5,x6);
	
	ListNode *head = x1;
	
	//ListNode *head2 = reverseRecursive(head);
	ListNode *middle = FindMiddleNode(head);

	int k = 2;
	ListNode *KthToTail = FindKthNodeToTail(head,k);	

	//create a circle
	x5->next = x3;
	bool isCircle = IsCircled(head);
	ListNode *circleHead = FindHeadOfCircle(head);

	x5->next = NULL;
	bool deleteNode = DeleteNode(x4);

	ListNode *newHead = ReverseList(head);

	ListNode *newHead2 = reverseRecursive(NULL,newHead);
	return 0;
}