#include <stdio.h>
#include <conio.h>

//Here we are comparing elements with pivot and if it is small then replace it with 'i' index
int partition(int A[], int start, int pivot)
{
	int i, j, t;

	i = start - 1;
	for (j = start; j <= pivot - 1; j++)
	{
		if (A[j] <= A[pivot])
		{
			i = i + 1;
			t = A[i];
			A[i] = A[j];
			A[j] = t;
		}
	}

	t = A[i + 1];
	A[i + 1] = A[pivot];
	A[pivot] = t;

	return i + 1;
}

void quickSort(int A[], int start, int pivot)
{
	int setIdx;
	//	This index is placed at it's real pos

	if (start < pivot)
	{
		setIdx = partition(A, start, pivot);
		quickSort(A, start, setIdx - 1);
		quickSort(A, setIdx + 1, pivot);
	}
}

// Driver Code
int main()
{
	int i;
	int arr[] = { 99, 12, 6, 3, 14, 2, 8, 7, 11 };
	quickSort(arr, 0, 8);

	for (i = 0; i < 9; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}