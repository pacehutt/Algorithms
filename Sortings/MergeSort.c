#include <stdio.h>
#include <conio.h>

void mergeSort(int A[], int l, int h)
{
	int m;
	if (l < h)
	{
		m = (l + h) / 2;
		//		This will divide the array in parts
		mergeSort(A, l, m);
		mergeSort(A, m + 1, h);

		merge(A, l, m, h);
	}
}

void mergeSortIterative(int A[], int size)
{
//	p for passes

   int p,i,l,h,mid,n=size;
   
   for(p=2; p<=n; p*=2)
   {
   	  for(i=0; i+p-1<n; i+=p)
   	  {
   	  	l=i;
   	  	h=i+p-1;
   	  	mid=(l+h)/2;
   	  	merge(A,l,mid,h);
		 
		}
	} 
}

void merge(int A[], int l, int m, int h)
{
	int i, j, k;
	int b[100];
	//	here we divided a single array into two parts by pointing i at lower and ending at m 
	//  then pointing j at m+1 and ending at h
	//  k is for incrementing the b array

	i = l, j = m + 1, k = l;

	while (i <= m && j <= h)
	{
		if (A[i] < A[j])
			b[k++] = A[i++];

		else
			b[k++] = A[j++];

	}

	while (i <= m)
		b[k++] = A[i++];

	while (j <= h)
		b[k++] = A[j++];

	//	Copying the sorted array back to A[]
	for (i = l; i <= h; i++)
		A[i] = b[i];

}


// Driver code
int main()
{
	int arr[] = { 9, 5, 1, 6, 8, 2, 7, 3, 4 };
	int i;
// 	mergeSort(arr, 0, 8);
    mergeSortIterative(arr,8);
	for (i = 0; i < 9; i++)
	printf("%d  ", arr[i]);
	

	getch();
	return 0;
}