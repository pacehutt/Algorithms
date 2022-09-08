// SELECTION SORT

#include<stdio.h>

int main()
{
	
	int arr[]={1,34,32,21,0};
	int n=5,i=0,j=0,minIdx=0;
    
	for(i=0;i<n;i++)
	{
//		So here are declaring the mininum index as i which is 0 for the first time
//      Now this min will be compared with all the others and then 
//	    after the inner loop execution values will be swapped of this minIdx and j
		minIdx=i;
		
		for(j=i+1;j<n;j++)
		{
			if(arr[j]<arr[minIdx])
			minIdx=j;
		}
		
		int t=arr[i];
		arr[i]=arr[minIdx];
		arr[minIdx]=t;
		}
		
		for(i=0;i<n;i++)
        printf("%d\t",arr[i]);
    
	return 0;	
}


