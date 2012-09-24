// BinarySearch.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <vector>
using namespace std;

#include "Board.h"

//引子
//from http://www.madongfly.cn/articles/binarysearch.html

//这段代码是我写了很多次的二分之后总结出来的，因为二分的很多其他写法在不同的条件下稍不注意就会出现错误。
//这里说的不同的条件包括：求满足条件的最小的值； 求满足条件最大的值等等。
//而下面的代码可以通用我到目前为止遇到的所有情况(仅仅是改变一下ans = mid; 的位置即可)，所以一直这么写二分。
int BinarySearch(int *a,int n,int x)
{
	int low = 0;
	int high = n-1;
	int ans = -1;

	while (low <= high)
	{	
		int m = (low+high)/2;
		if (a[m] >= x)
		{
			ans = m;
			high = m-1;
		}
		else
		{
			low = m+1;
		}
	}
	return ans;
}

//from programming pearls,page 93
int BinarySearch2(int *a,int n,int x)
{
	int low = -1;
	int high = n;

	while (low+1 != high)
	{
		//invariant: a[low] < x && x[high] >= x && low < high
		int m = (low+high)/2;
		if (a[m] < x)
		{
			low = m;
		}
		else
			high = m;
	}

	//assert low+1 = high && a[low] < x && a[high] >= x
	int ans = high;
	if (ans > n || a[ans] != x)
	{
		ans = -1;
	}

	return ans;
}

//二分查找满足条件的最左边的下标
//加入了对要查找的数不存在的判断
int BinSearchL(int *a, int n, int key)
{
	if (NULL == a || n < 1)
	{
		return -1;
	}

	int low = 0;
	int high = n - 1;
	int ans = -1;

	while (low <= high)
	{
		int mid = (low + high) >> 1; // mid = low + ((high - low) >> 1);如果对溢出处理有特殊要求

		if (a[mid] >= key)
		{
			ans = mid;
			high = mid - 1;
		}
		else 
		{
			low = mid + 1;
		}
	}

	if (ans != -1 && key == a[ans])
	{
		return ans;
	}

	return -1;
}

//二分查找满足条件的最右边的下标. 变换ans = mid的位置即可，同时注意判断条件的变更（跟随a[mid]==key变化）
int BinSearchR(int *a, int n, int key)
{
	if (NULL == a || n < 1)
	{
		return -1;
	}

	int low = 0;
	int high = n - 1;
	int ans = -1;

	while (low <= high)
	{
		int mid = (low + high) >> 1; // mid = low + ((high - low) >> 1);如果对溢出处理有特殊要求

		if (a[mid] > key)
		{
			high = mid - 1;
		}
		else 
		{
			ans = mid;
			low = mid + 1;
		}
	}

	if (ans != -1 && key == a[ans])
	{
		return ans;
	}

	return -1;	
}

//旋转数组里查找某数,返回任意满足条件的下标
//数形结合，画示意图。
int BinarySearchRotate(int *a, int n, int key)
{
	if (NULL == a || n < 1)
	{
		return -1;
	}

	int low = 0;
	int high = n - 1;
	int ans = -1;

	while (low <= high)
	{
		int mid = (low + high) >> 1;

		if (key == a[mid])
		{
			ans = mid;
			break;
		}

		if (a[mid] > a[high])     //上半截
		{
			if (key > a[mid])
			{
				low = mid + 1;
			}
			else if (key >= a[low])
			{
				high = mid - 1;
			}
			else if (key <= a[high])
			{
				low = mid + 1;
			}
		}
		else                        //下半截
		{
			if (key < a[mid])
			{
				high = mid - 1;
			}
			else if (key <= a[high])
			{
				low = mid + 1;
			}
			else if (key >= a[low])
			{
				high = mid - 1;
			}
		}
	}
	return ans;
}

//在旋转数组中找到最小值
//参考：http://zhedahht.blog.163.com/blog/static/25411174200952765120546/

int BinSearchRotateMin(int *a, int n)
{
	if (NULL == a || n < 1)
	{
		return -1;
	}
	
	int low = 0;
	int high = n-1;
	int mid = low;

	//array has not been rotated
	//这块判断有些牵强：比如:1 0 1 1 1。如果不加该判断，该算法对这个case就不行了。
	if (a[low] <= a[high])
	{
		return -1;
	}

	while (a[low] >= a[high])
	{
		if (high - low == 1)    //最后low和high相邻
		{
			mid = high;
			break;
		}

		mid = (low + high) >> 1;
		if (a[mid] >= a[low])    //low在上半截
		{
			low = mid;
		}
		else if (a[mid] <= a[high])   //high在下半截
		{
			high = mid;
		}
	}

	return a[mid];
}

//旋转数组
//在旋转数组中找到最小值的最左下标
int BinSearchRotateMinL(int *a, int n)
{	
	/*if (NULL == a || n < 1)
	{
		return -1;
	}

	int low = 0;
	int high = n - 1;
	int ans = low;

	while (low <= high && a[low] >= a[high])
	{
		int mid = (low + high) >> 1;

		if (a[mid] <= a[high])
		{
			ans = mid;
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}

	return ans;*/
	

	if (NULL == a || n < 1)
	{
		return -1;
	}

	int low = 0;
	int high = n-1;
	int mid = low;

	//array has not been rotated
	if (a[low] <= a[high])
	{
		return -1;
	}

	while (a[low] >= a[high])
	{
		if (high - low == 1)    //最后low和high相邻
		{
			mid = high;
			break;
		}

		mid = (low + high) >> 1;
		if (a[mid] >= a[low])    //low在上半截
		{
			low = mid;
		}
		else if (a[mid] <= a[high])   //high在下半截
		{
			high = mid;
		}
	}

	return mid;
}

////在旋转数组中找到最小值的最右下标
//int BinSearchRotateMinR(int *a, int n)
//{
//	if (NULL == a || n < 1)
//	{
//		return -1;
//	}
//
//	int low = 0;
//	int high = n-1;
//	int mid = low;
//
//	//array has not been rotated
//	if (a[low] <= a[high])
//	{
//		return -1;
//	}
//	
//	int formerDist = -1;
//
//	while (a[low] >= a[high])
//	{
//		if (high - low == formerDist)    //最后low和high距离不变
//		{
//			mid = high;
//			break;
//		}
//
//		formerDist = high - low;
//
//		mid = (low + high) >> 1;
//		if (a[mid] >= a[low])    //low在上半截
//		{
//			low = mid;
//		}
//		else if (a[mid] < a[high])   //high在下半截
//		{
//			high = mid;
//		}
//	}
//
//	return mid;
//}

//在旋转数组中找到最大值的最右下标
int BinSearchRotateMaxR(int *a, int n)
{
	if (NULL == a || n < 1)
	{
		return -1;
	}

	int low = 0;
	int high = n-1;
	int mid = low;

	//array has not been rotated
	if (a[low] <= a[high])
	{
		return -1;
	}

	while (a[low] >= a[high])
	{
		if (high - low == 1)    //最后low和high相邻
		{
			mid = low;
			break;
		}

		mid = (low + high) >> 1;
		if (a[mid] >= a[low])    //low在上半截
		{
			low = mid;
		}
		else if (a[mid] <= a[high])   //high在下半截
		{
			high = mid;
		}
	}

	return mid;
}

////在旋转数组中找到最大值的最左下标
//int BinSearchRotateMaxL(int *a, int n)
//{
//	if (NULL == a || n < 1)
//	{
//		return -1;
//	}
//
//	int low = 0;
//	int high = n-1;
//	int mid = low;
//
//	//array has not been rotated
//	if (a[low] <= a[high])
//	{
//		return -1;
//	}
//
//	int formerDist = -1;
//
//	while (a[low] >= a[high])
//	{
//		if (high - low == formerDist)    //最后low和high距离不变
//		{
//			mid = high;
//			break;
//		}
//
//		formerDist = high - low;
//
//		mid = (low + high) >> 1;
//		if (a[mid] > a[low])    //low在上半截
//		{
//			low = mid;
//		}
//		else if (a[mid] <= a[high])   //high在下半截
//		{
//			high = mid;
//		}
//	}
//
//	return mid;
//}

//coding interviewing:
//9.6 给定一个M*N的数组，它的每行按升序排列，每列也按升序排序，如何查找一个数x？
//思路：在矩阵中的应用。。。 和二分法有些不同，不过思想是相通的：批量移除不符合要求的数据块。
//初始点设在a[0][n-1];如果x<a[0][n-1],row++; 否则，col--。
bool FindElement(int a[4][4],int x)
{
	const int m = 4;
	const int n = 4;
	int high = 0;
	int c = n-1;
	while (high < m && c >= 0)
	{	
		int tmp = a[high][c];
		if (tmp == x)
		{
			return true;
		}
		if (tmp > x)
		{
			c--;
		}
		else
		{
			high++;
		}
	}

	return false;
}

int _tmain(int argc, _TCHAR* argv[])
{
	const int n = 8;
	int a[n] = {6,3,1,7,8,9,2,3};

	QuickSort(a,0,n-1);

	int high = BinarySearch(a,n,3);
	int r2 = BinarySearch(a,n,3);

	int aa[4][4]=
	{
		0,1,2,4,
		3,5,8,9,
		6,7,10,11,
		12,13,14,15
	};
			
	bool find = FindElement(aa,10);

	int b[n] = {1,2,6,6,6,8,9,11};
	int r3 = BinSearchL(b,n,6);
	int r4 = BinSearchR(b,n,6);

	int c[n] = {6,7,9,11,1,2,3,4};
	int r5 = BinarySearchRotate(c,n,7);
	int r6 = BinSearchRotateMin(c,n);

	//int d[n] = {6,7,1,1,1,1,1,4};
	//int r7 = BinSearchRotateMinL(d,n);
	//int d2[n] = {6,7,9,11,1,1,1,4};
	//int r7_2 = BinSearchRotateMinL(d2,n);

	int d[n] = {6,7,11,11,1,1,1,4};
	int r7 = BinSearchRotateMinL(d,n);
	//int r7_2 = BinSearchRotateMinR(d,n);	
	int r8 = BinSearchRotateMaxR(d,n);

	return 0;
}