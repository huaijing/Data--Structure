#pragma once;

struct BinaryTreeNode 
{
	int  m_nValue;    
	BinaryTreeNode *m_pLeft;
	BinaryTreeNode *m_pRight;
};

//build the tree
__declspec( dllexport ) BinaryTreeNode* CreateTreeNode(int value);
__declspec( dllexport ) void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft,BinaryTreeNode* pRight);

//visit the tree£¬recursive vision
__declspec( dllexport ) void PrintTreeNode(BinaryTreeNode *pNode);
__declspec( dllexport ) void PreOrder(BinaryTreeNode* pNode);
__declspec( dllexport ) void InOrder(BinaryTreeNode* pNode);
__declspec( dllexport ) void PostOrder(BinaryTreeNode* pNode);

__declspec( dllexport ) void LevelOrder(BinaryTreeNode* pNode);
__declspec( dllexport ) void VisitTreeNode(BinaryTreeNode *pNode);


//height of the tree
__declspec( dllexport ) int Height(BinaryTreeNode *pNode);

//destroy the tree
__declspec( dllexport ) void DestroyTree(BinaryTreeNode* pRoot);


//rebuild the tree. 

//Given the array of PreOrderTraverse and array of InOrderTraverse.
__declspec( dllexport ) bool ReBuild1(BinaryTreeNode* &root, int *aPre, int *aPreEnd, int *aIn, int *aInEnd);

//Given the array of PostOrderTraverse and array of InOrderTraverse.
__declspec( dllexport ) bool ReBuild2(BinaryTreeNode* &root, int *aPost, int *aPootEnd, int *aIn, int *aInEnd);

//visit the tree£¬iterative vision
__declspec( dllexport ) void PreOrder_Iter(BinaryTreeNode* pNode);
__declspec( dllexport ) void PreOrder_Iter2(BinaryTreeNode* pNode);
__declspec( dllexport ) void InOrder_Iter(BinaryTreeNode* pNode);
__declspec( dllexport ) void PostOrder_Iter(BinaryTreeNode* pNode);
__declspec( dllexport ) void PostOrder_Iter2(BinaryTreeNode* pNode);