#ifndef Board_H
#define Board_H

//all kinds of sort algorithm
static void Swap(int *a,int *b)
{
	//exception
	if (!a || !b)
	{
		return;
	}
	int temp = *a;
	*a = *b;
	*b = temp;
	return;
}

#endif

