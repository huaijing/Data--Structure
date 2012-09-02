#pragma  once;

void Swap(int *a,int *b)
{
	if (!a || !b)
	{
		return;
	}
	int t = *a;
	*a = *b;
	*b = t;
}

void QuickSort(int *a,int left,int right)
{
	if (left >= right)
	{
		return;
	}

	int i = left;
	int j = right+1;
	int pivot = a[left];

	while(1)
	{
		do
		{
			i++;
		}while (i <= right && a[i] < pivot);

		do
		{
			j--;
		}while (a[j] > pivot);

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