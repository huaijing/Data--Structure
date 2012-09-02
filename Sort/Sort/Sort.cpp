// Sort.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <limits> 
#include "Board.h"
#include "Heap.h"

using namespace std;

//Selection 
//select the min element each loop
int SelectionSort(int *a,int length)
{
	//exception
	if (!a || length < 0)
	{
		return -1;
	}

	for (int i = 0;i < length;i++)
	{
		int min = a[i];
		int minID = i;	
		
		//select the min element each loop
		for (int j = i;j < length;j++)
		{
			if (a[j] < min)
			{
				min = a[j];
				minID = j;
			}
		}
		Swap(&a[minID],&a[i]);
	}
	return 1;
}

//Bubble 
//compare two adjacent elements in order,and put the smaller on in front of the other
int BubbleSort(int *a,int length)
{
	//exception
	if (!a || length < 0)
	{
		return -1;
	}
	
	for (int i = 0;i < length;i++)
	{		
		for (int j = 0;j < length-i-1;j++)
		{
			//compare two adjacent elements in order,and put the smaller on in front of the other
			if (a[j] > a[j+1])
			{
				Swap(&a[j],&a[j+1]);
			}
		}
	}
	return 1;
}

//Insertion
//find the proper location of the elements, then insert it to that location
int InsertionSort(int *a,int length)
{
	//exception
	if (!a || length < 0)
	{
		return -1;
	}
	int i,j;
	for (i = 1;i < length;i++)
	{
		int key = a[i];
		for (j = i-1;j >= 0 && a[j] > key;j--)
		{
			a[j+1] = a[j];
		}
		a[j+1] = key;			
	}
	return 1;
}

//Quick
//select an element as a pivot, the ones larger than are put on the right, others are put on the left
int QuickSort(int a[],int left,int right)
{
	//exception
	if (!a){
		return -1;
	}

	if (left >= right)	{
		return 0;
	}

	int i = left;   //the index from left to right
	int j = right+1;  //the index from right to left
	int pivot = a[left];  //pivot 

	while(1)
	{
		do{
			i++;
		} while (i <= right && a[i] < pivot);  //i <= right to stop the index properly when the largest element is the pivot

		do{
			j--;
		} while (a[j] > pivot);

		if (i > j)
		{
			break;
		}
		Swap(&a[i],&a[j]);
	};

	Swap(&a[left],&a[j]);

	QuickSort(a,left,j-1);
	QuickSort(a,j+1,right);
}

//Merge (Divide and conquer)
void Merge(int *a,int left,int middle,int right)
{
	int n1 = middle-left+1;
	int n2 = right-middle;

	int *L = new int[n1+1];	
	int *R = new int[n2+1];

	int i = 0;
	int j = 0;
	//left array
	for (i = 0;i < n1;i++)
	{
		L[i] = a[left+i];
	}
	L[n1] = numeric_limits <int>::max(); //sentinel card ÉÚ±øÅÆ

	//right array
	for (j = 0;j < n2;j++)
	{
		R[j] = a[middle+j+1];
	}
	R[n2] = numeric_limits <int>::max();//sentinel card ÉÚ±øÅÆ

	//merge and copy
	i = j = 0;
	for (int k = left;k <= right;k++)//sentinel card can make the copy of  one of the array(L or R) correctly 
										//when the other one is ended.
	{													
		if (L[i] <= R[j])
		{
			a[k] = L[i];
			i++;
		}
		else if(L[i] > R[j])
		{
			a[k] = R[j];
			j++;
		}
	}
}

int MergeSort(int *a,int left,int right)
{
	if (!a)
	{
		return -1;
	}
	if(left < right)
	{
		int middle = (int)(right+left)/2;
		MergeSort(a,left,middle);
		MergeSort(a,middle+1,right);

		Merge(a,left,middle,right);
		
		return 1;
	}
	return 0;	
}

//Counting 
//given x,between [0 k],counting the number of input data which is smaller than x.
int CountingSort(int *a,int *b,int length,int k)  //*a: input array; *b:output array
{
	//exception
	if (!a || !b || length < 0 || k < 0)
	{
		return -1;
	}
	int *c = new int[k+1];

	int i = 0;
	for (i = 0;i < k+1;i++)
	{
		c[i] = 0;
	}

	for (i = 0;i < length;i++)
	{
		c[a[i]]++; 
	}	//c[k] is the number of data equal to k

	for (i = 1;i < k+1;i++)
	{
		c[i] = c[i] + c[i-1];
	}	//c[k] is the number of data not larger than k

	for (i = length-1;i >= 0;i--)
	{
		b[c[a[i]]-1] = a[i];
		c[a[i]]--;
	}
	return 1;
}

int _tmain(int argc, _TCHAR* argv[])
{
	const int len = 8;
	int array1[len] = {5,6,3,9,4,0,3,7};
	int result1 = 0;
	result1 = SelectionSort(array1,len);

	int array2[len] = {5,6,3,9,4,0,3,7};
	int result2 = 0;
	result2 = BubbleSort(array2,len);

	int array3[len] = {5,6,3,9,4,0,3,7};
	int result3 = 0; 
	result3 = InsertionSort(array3,len);

	int array4[len] = {5,6,3,9,4,0,3,7};
	int result4 = 0; 
	result4 = QuickSort(array4,0,len-1);	

	int array5[len] = {6,3,1,7,8,9,2,3};//{5,6,3,9,4,0,3,7};//{9,1,2,3,4,5,6,7};
	int result5 = 0; 
	result5 = QuickSort(array5,0,len-1);	

	int array6[len] = {5,6,3,9,4,0,3,7};//{9,1,2,3,4,5,6,7};
	Heap heap(array6,len);
	heap.HeapSort();

	int array7[len] = {5,6,3,9,4,0,3,7};//{9,1,2,3,4,5,6,7};
	int result7 = MergeSort(array7,0,len-1); 

	int array8[len] = {5,6,3,9,4,0,3,7};
	int array9[len];
	int result8 = CountingSort(array8,array9,len,9);
 	return 0;
}