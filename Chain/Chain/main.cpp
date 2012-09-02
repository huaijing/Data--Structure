// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
using namespace std;

#include "chain.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Chain<int> chain;
	// test size
	cout << "Initial size of chain = "
		<< chain.Length() << endl;
	
	// test empty
	if (chain.IsEmpty()) cout << "chain is empty" << endl;
	else cout << "chain is not empty" << endl;

	// test insert
	chain.Insert(0, 2);
	chain.Insert(1, 6);
	chain.Insert(0, 1);
	chain.Insert(2, 4);
	chain.Insert(3, 5);
	chain.Insert(2, 3);

	cout << "Inserted 6 integers, list chain should be 1 2 3 4 5 6" << endl;
	cout << "Size of chain = " << chain.Length() << endl;
	if (chain.IsEmpty()) cout << "chain is empty" << endl;
	else cout << "chain is not empty" << endl;
	chain.Output();

	int x  = -1,y = -1,z = -1;
	// test find and search
	bool exist = chain.Find(5,x);
	int index = chain.Search(6);

	// test delete
	chain.Delelte(0,x);
	chain.Delelte(3,y);
	chain.Delelte(7,z);
	cout << "Size of chain = " << chain.Length() << endl;
	if (chain.IsEmpty()) cout << "chain is empty" << endl;
	else cout << "chain is not empty" << endl;
	chain.Output();

	return 0;
}