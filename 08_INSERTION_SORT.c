#include<stdio.h>
int main()
{
	int n,i,j,temp,key;
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
	for(i=1;i<n;i++)
	{
		key=a[i];
		j=i-1;
		while(j>=0 && key<a[j])
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=key;
	}
	printf("\n\nAfter sorting : \n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	
}
