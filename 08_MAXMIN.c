#include<stdio.h>
int max,min;
void findminmax(int a[],int start,int end)
{
	int max1,min1;
	if(start==end)
	{
		min=a[start];
		max=a[start];
	}
	else if(start+1==end)
	{
		if(a[start]<a[end])
		{
			min=a[start];
			max=a[end];
		}
		else
		{
			max=a[start];
			min=a[end];
		}
	}
	else
	{
		int mid=(start+end)/2;
		findminmax(a,start,mid);
		max1=max;
		min1=min;
		findminmax(a,mid+1,end);
		if(max1>max)
		{
			max=max1;
		}
		if(min1<min)
		{
			min=min1;
		}
	}
}
int main()
{
    int i,n;
    printf("\nEnter number of elements : ");
    scanf("%d",&n);
    int a[n];
	printf("\nEnter the elements : \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
    printf("\n\nEntered list : \n");
    for(i=0;i<n;i++)
    printf("%d  ",a[i]);
    max=a[0];
    min=a[0];
    findminmax(a,0,n-1);
    printf("\n\nMinimum element : %d",min);
    printf("\nMaximum element : %d",max);
}
