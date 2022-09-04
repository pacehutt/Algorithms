#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
	
//	Bubble Sort
    int i,j,t;
    int n=10;
    int arr[]={2,13,0,-2,-5,23,5,1,6,10};
    
//    Here i-loop is for rounds and it will iterate for n-1 rounds
    for(i=1;i<n-1;i++)
    { 
//        Here j will start from 0 and check upto n-1-i because after every round 
//        one element is placed at it's right place from the end of the array
          for(j=0;j<n-1-i;j++)  
		  {
		  	    if(arr[j]>arr[j+1])
		  	    {
		  	    	t=arr[j];
		  	    	arr[j]=arr[j+1];
		  	    	arr[j+1]=t;
				}
		    }	
		    
//		    this sorting is O(n^2)  
	}
    
    
    for(i=0;i<n;i++)
     printf("%d\t",arr[i]);
    
	return 0;
	
}