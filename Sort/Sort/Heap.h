#ifndef Heap_H
#define Heap_H

class Heap
{
public:
	Heap(int *a,int len):array(a),heapSize(len){ };
	~Heap(){
		delete array;
	}
	void MaxHeapify(int i); //maintain a max heap whose root is node i
	void BuildMaxHeap(); //build a max heap,from the bottom(the first parent) to the top(root). 
	void HeapSort();
private:
	int *array;  // the data
	int heapSize; // the size of array 
};

#endif