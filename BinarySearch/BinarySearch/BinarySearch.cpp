// BinarySearch.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <vector>
using namespace std;

#include "Board.h"

//����
//from http://www.madongfly.cn/articles/binarysearch.html

//��δ�������д�˺ܶ�εĶ���֮���ܽ�����ģ���Ϊ���ֵĺܶ�����д���ڲ�ͬ���������Բ�ע��ͻ���ִ���
//����˵�Ĳ�ͬ��������������������������С��ֵ�� ��������������ֵ�ȵȡ�
//������Ĵ������ͨ���ҵ�ĿǰΪֹ�������������(�����Ǹı�һ��ans = mid; ��λ�ü���)������һֱ��ôд���֡�
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

//���ֲ�����������������ߵ��±�
//�����˶�Ҫ���ҵ��������ڵ��ж�
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
		int mid = (low + high) >> 1; // mid = low + ((high - low) >> 1);������������������Ҫ��

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

//���ֲ����������������ұߵ��±�. �任ans = mid��λ�ü��ɣ�ͬʱע���ж������ı��������a[mid]==key�仯��
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
		int mid = (low + high) >> 1; // mid = low + ((high - low) >> 1);������������������Ҫ��

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

//��ת���������ĳ��,�������������������±�
//���ν�ϣ���ʾ��ͼ��
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

		if (a[mid] > a[high])     //�ϰ��
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
		else                        //�°��
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

//����ת�������ҵ���Сֵ
//�ο���http://zhedahht.blog.163.com/blog/static/25411174200952765120546/

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
	//����ж���Щǣǿ������:1 0 1 1 1��������Ӹ��жϣ����㷨�����case�Ͳ����ˡ�
	if (a[low] <= a[high])
	{
		return -1;
	}

	while (a[low] >= a[high])
	{
		if (high - low == 1)    //���low��high����
		{
			mid = high;
			break;
		}

		mid = (low + high) >> 1;
		if (a[mid] >= a[low])    //low���ϰ��
		{
			low = mid;
		}
		else if (a[mid] <= a[high])   //high���°��
		{
			high = mid;
		}
	}

	return a[mid];
}

//��ת����
//����ת�������ҵ���Сֵ�������±�
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
		if (high - low == 1)    //���low��high����
		{
			mid = high;
			break;
		}

		mid = (low + high) >> 1;
		if (a[mid] >= a[low])    //low���ϰ��
		{
			low = mid;
		}
		else if (a[mid] <= a[high])   //high���°��
		{
			high = mid;
		}
	}

	return mid;
}

////����ת�������ҵ���Сֵ�������±�
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
//		if (high - low == formerDist)    //���low��high���벻��
//		{
//			mid = high;
//			break;
//		}
//
//		formerDist = high - low;
//
//		mid = (low + high) >> 1;
//		if (a[mid] >= a[low])    //low���ϰ��
//		{
//			low = mid;
//		}
//		else if (a[mid] < a[high])   //high���°��
//		{
//			high = mid;
//		}
//	}
//
//	return mid;
//}

//����ת�������ҵ����ֵ�������±�
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
		if (high - low == 1)    //���low��high����
		{
			mid = low;
			break;
		}

		mid = (low + high) >> 1;
		if (a[mid] >= a[low])    //low���ϰ��
		{
			low = mid;
		}
		else if (a[mid] <= a[high])   //high���°��
		{
			high = mid;
		}
	}

	return mid;
}

////����ת�������ҵ����ֵ�������±�
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
//		if (high - low == formerDist)    //���low��high���벻��
//		{
//			mid = high;
//			break;
//		}
//
//		formerDist = high - low;
//
//		mid = (low + high) >> 1;
//		if (a[mid] > a[low])    //low���ϰ��
//		{
//			low = mid;
//		}
//		else if (a[mid] <= a[high])   //high���°��
//		{
//			high = mid;
//		}
//	}
//
//	return mid;
//}

//coding interviewing:
//9.6 ����һ��M*N�����飬����ÿ�а��������У�ÿ��Ҳ������������β���һ����x��
//˼·���ھ����е�Ӧ�á����� �Ͷ��ַ���Щ��ͬ������˼������ͨ�ģ������Ƴ�������Ҫ������ݿ顣
//��ʼ������a[0][n-1];���x<a[0][n-1],row++; ����col--��
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