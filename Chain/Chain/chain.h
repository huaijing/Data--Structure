#pragma once;

#include <iostream>
using namespace std;

template <class T>
struct ChainNode 
{
	T data;
	ChainNode<T> *link;
};

template<class T>
class Chain
{
	ChainNode<T> *first; //point to the first node
public:
	
	Chain(){ first = 0; }
	~Chain();
	bool IsEmpty()const { return first == 0;}
	int Length() const;

	bool Find(int k,T &x) const; //find the k-th number of the chain,and store it in x
	int Search(const T&x) const;
	void Delelte(int k,T &x);  //store the k-th element in x,then delete the k-th node
	void Insert(int k,const T&x);  //insert x after the k-th element

	void Output() const;
};

template<class T>
Chain<T>::~Chain()
{
	//delete all the node of the chain
	ChainNode<T> *next;
	while (first)
	{
		next = first->link;
		delete first;
		first = next;
	}
}

template<class T>
int Chain<T>::Length() const
{
	//return the total number of the node in the chain
	int len = 0;
	ChainNode<T> *current = first;
	while (current)
	{
		len++;
		current = current->link;
	}
	return len;
}

template<class T>
bool Chain<T>::Find(int k,T &x) const
{
	//find the k-th number of the chain,and store it in x
	if (k < 1)
	{
		return false;
	}

	ChainNode<T> *current = first;
	for (int index = 1;current && index < k;current = current->link,index++);
	if (current)
	{
		x = current->data;
		return true;
	}
	return false;
}

template<class T>
int Chain<T>::Search(const T&x) const
{
	//if find x,return the index of x; if not, return 0
	ChainNode<T> *current = first;
	for (int index = 1;current;current = current->link,index++)
	{
		if(current->data == x)
		{
			return index;
		}
	}
	return 0;
}

template<class T>
void Chain<T>::Delelte(int k,T &x)
{
	//store the k-th element in x,then delete the k-th node

	//if the k-th element does not exist
	if (k < 1 || !first)
	{
		return;
	}

	//at last , p will point to the k-th element
	ChainNode<T> *p = first;
	if (k == 1)
	{
		first = first->link;
	}
	else
	{
		//q will point to the k-1-th element
		ChainNode<T> *q = first;
		for (int index = 1;q && index < k-1;q = q->link,index++);

		//the k-th element does not exist
		if(!q || !q->link)
		{
			return;
		}

		p = q->link;
		q->link = p->link;
	}
	x = p->data;
	delete p;

	//return *this;

}

template<class T>
void Chain<T>::Insert(int k,const T &x)
{
	//insert x after the k-th element
	if (k < 0)
	{
		return;
	}
	//at last , p will point to the k-th element
	ChainNode<T> *p = first;
	for (int index = 1;index < k && p;p = p->link,index++);

	//if the k-th element does not exist
	if (k > 0 && !p)
	{
		return;
	}
	else
	{
		//insert 
		ChainNode<T> *y = new ChainNode<T>;
		y->data = x;
		if (k == 0)
		{
			y->link = first;
			first = y;
		}
		else
		{
			y->link = p->link;
			p->link = y;
		}
	}
	//return *this;
}

template<class T>
void Chain<T>::Output() const
{
	ChainNode<T> *current = first;
	for (int index = 1;current;current = current->link,index++)
	{
		cout<<"the "<<index<<"-th element is:"<<current->data<<endl;
	}
	cout<<endl;
}