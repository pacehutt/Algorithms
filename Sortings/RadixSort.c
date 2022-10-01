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
	
//	struct Node *temp=*start;
//	
//	while(temp->next!=NULL)
//	{
//		printf("%d\n",temp->data);
//		temp=temp->next;
//	}

}




void radixSort(int A[],int n)
{
	int max=findMax(A,n);
	
	printf("\nMax is : %d\n",max);
	
	int pass=0,i=0;
	int countMaxDigits=0;
	while(max!=0)
	{
		countMaxDigits++;
		max/=10;
	}
	
	printf("Max digits are : %d\n",countMaxDigits);
		
	int modDivider=10;
	int divider=1;	
	for(pass=0; pass<countMaxDigits; pass++)
	{
		struct Node **bucketArray=(struct Node**)calloc(10,sizeof(struct Node*));
		
		for(i=0;i<n;i++)
		{
			int index = (A[i]%modDivider)/divider;
			appendNode(&bucketArray[index],A[i]);
			
		}
		
		int j=0;
	    for(i=0;i<10;i++)
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
		
	printf("\n\nPass = %d\n",pass+1);
	for(i=0;i<n;i++)
	{
		printf("%d\t",A[i]);
	}
		modDivider*=10;
		divider*=10;
	}
}





int main()
{
	int array[]={2,3,1,7,4,3,7,190,0,1};
	int n=10;
	int i=0;
	
//	Before sort
	for(i=0;i<n;i++)
	{
		printf("%d\t",array[i]);
	}
	radixSort(array,n);

    printf("\n\nAfter Sort\n");
    
//  After Sort
	for(i=0;i<n;i++)
	{
		printf("%d\t",array[i]);
	}
	
	return 0;
}











