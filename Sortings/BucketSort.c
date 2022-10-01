#include<stdio.h>
#include<stdlib.h>


struct Node
{
	int data;
	struct Node *next;
};


int findMax(int A[],int n)
{
	int tempArray[n];
	int i=0;
	
	
	for(i=0;i<n;i++)
	{
		tempArray[i]=A[i];
	}
	
	int max=tempArray[0];
	for(i=1;i<n;i++)
	{
		if(max<tempArray[i])
		{
			int t=max;
			max=tempArray[i];
			tempArray[i]=t;
		}
	}
	
//	printf("%d max \n",max);
	return max;
}

void appendNode(struct Node **start,int item)
{
	
//	printf("\n%u\t",start);
	
	struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
	newNode->data=item;
	newNode->next=NULL;
	
	if(*start==NULL)
	*start=newNode;
	
	else
	{
		struct Node *temp=*start;
		
	 	while(temp->next!=NULL)
	 	{
		 temp = temp->next;
		 }
		 
		temp->next=newNode;
	}
	

}

void bucketSort(int A[],int n)
{
    int max=findMax(A,n);
	
	struct Node **bucketArray=(struct Node**)calloc(max+1,sizeof(struct Node*));
	int i=0;
	
	for(i=0;i<n;i++)
	{
		
//		printf("%u\t",&bucketArray[i]); was checking if the address passed was same as the address here
	
		appendNode(&bucketArray[A[i]],A[i]);
	}
	
	int j=0;
	for(i=0;i<max+1;i++)
	{
		if(bucketArray[i] != NULL)
		{
			while(bucketArray[i]!=NULL)
			{
			  struct Node *temp=bucketArray[i];
			  A[j] = temp->data;
			  bucketArray[i] = bucketArray[i]->next;
			  free(temp);
			  j++;
			}
		}
	}
	
}






int main()
{
	int array[]={2,3,1,7,4,1,2,9,7,7};
	int n=10;
	int i=0;
	
//	Before sort
	for(i=0;i<n;i++)
	{
		printf("%d\t",array[i]);
	}
	bucketSort(array,n);

    printf("\n");
    
//  After Sort
	for(i=0;i<n;i++)
	{
		printf("%d\t",array[i]);
	}
	
	return 0;
}








