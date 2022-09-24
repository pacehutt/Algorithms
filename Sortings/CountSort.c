#include<stdio.h>
#include<stdlib.h>



int Max(int *A,int n)
{
	int i,max=A[0];
	
	for(i=1;i<n;i++)
	{
		if(max<A[i])
		max=A[i];
	}
	
	return max;
}

countSort(int *A,int n)
{
	int max,*C,i,j;
	
	max= Max(A,n);
	C = (int*)calloc(max+1,sizeof(int));
	
	for(i=0;i<n;i++)
	C[A[i]]++;
	
	i=0;
	j=0;
	
	while(i<max+1)
	{
		if(C[i]>0)
		{
           // j is to track the Original Array A			
			A[j++]=i;
			C[i]--;
			
		}
		else
		i++; //i is to track the Count Array C
		
		
	}	
	
}


// Driver Code
int main(int argc,char *argv[])
{
	int arr[]={10,2,7,1,2,3,4,6,9};
	
	int i=0;
	
	countSort(arr,9);
	
	for(i=0;i<9;i++)
	{
		printf("%d\t",arr[i]);
	}
	
	
	return 0;
}