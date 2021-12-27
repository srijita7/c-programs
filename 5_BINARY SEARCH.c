#include<stdio.h>
void bubblesort(int arr[],int h);
int binarysearch(int arr[],int start,int end,int n);
int main()
{
	int i,n,key,d;
	printf("Enter number of elements: ");
	scanf("%d",&n);
	int a[n];
	printf("\nEnter the elements : \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter element you want to search: ");
	scanf("%d",&key);
	bubblesort(a,n);
	printf("\n\nAfter sorting : \n");
	for(i=0;i<n;i++)
	{
		printf("%d  ",a[i]);
	}
	d=binarysearch(a,0,n-1,key);
	if(d==-1)
	printf("\n\n%d Not found",key);
	else
	printf("\n\n%d element found at position %d",key,d+1);
}
void bubblesort(int arr[],int n)
{
	int i,j,temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}
int binarysearch(int arr[],int start,int end,int n) 
{
	if(start>end) 
   		return -1;
    int mid=(start+end)/2;
    if (arr[mid]==n) 
		return mid;
    else if (n<arr[mid])
    	binarysearch(arr,start,mid-1,n);
   	else
        binarysearch(arr,mid+1,end,n);
}
