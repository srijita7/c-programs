#include<stdio.h>
int main()
{
	int n,i,j,temp,pos;
	printf("\nEnter size : ");
	scanf("%d",&n);
	int a[n];
	printf("\nEnter elements : \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\nEntered array : \n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	for(i=0;i<n-1;i++)
	{
		pos=i;
		for(j=i+1;j<n;j++)
		{
			if(a[pos]>a[j])
			{
				pos=j;
			}
		}
		if(pos!=i)
		{
			temp=a[i];
			a[i]=a[pos];
			a[pos]=temp;
		}
	}
	printf("\n\nAfter sorting : \n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
