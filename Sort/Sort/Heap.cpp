#include "stdafx.h"
#include "Heap.h"
#include "Board.h"

void Heap::MaxHeapify(int i)
{
	//exception
	if (!array)
	{
		return;
	}

	int l = 2*i+1;  //left(i)
	int r = 2*i+2; //right(i)
	int largest = 0;

	//find the max element from  left(i) ,right(i) and parent. 
	if (l < heapSize && array[l] > array[i])
	{
		largest = l;
	}
	else
	{
		largest = i;
	}
	if (r < heapSize && array[r] > array[largest])
	{
		largest = r;
	}
	
	if (largest != i)
	{
		Swap(&array[largest],&array[i]);
		MaxHeapify(largest);
	}
}

void Heap::BuildMaxHeap()
{
	int firstParent = int(heapSize/2)-1; //the first parent from the bottom 
	for (int i = firstParent;i >=0;i--)
	{
		MaxHeapify(i);  //keep the max heap from the first parent to the root 
	}
}

void Heap::HeapSort()
{
	BuildMaxHeap();
	for (int i = heapSize-1;i >= 1;i--)
	{
		Swap(&array[i],&array[0]);
		heapSize--;
		MaxHeapify(0);
	}
}