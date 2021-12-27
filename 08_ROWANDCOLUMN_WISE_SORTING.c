#include<stdio.h>
int main()
{
	int m,n,i,j,temp,key,k;
	printf("\nEnter number of rows : ");
	scanf("%d",&m);
	printf("\nEnter number of columns : ");
	scanf("%d",&n);
	int a[m][n];
	printf("\nEnter the elements : \n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("a[%d][%d] : ",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	printf("\nEntered matrix : \n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n-1;j++)
		{
			for(k=0;k<n-j-1;k++)
			{
				if(a[i][k]>a[i][k+1])
				{
					temp=a[i][k];
					a[i][k]=a[i][k+1];
					a[i][k+1]=temp;
				}
			}
		}
	}
	printf("\n\nAfter sorting row wise : \n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m-1;j++)
		{
			for(k=0;k<m-j-1;k++)
			{
				if(a[k][i]>a[k+1][i])
				{
					temp=a[k][i];
					a[k][i]=a[k+1][i];
					a[k+1][i]=temp;
				}
			}
		}
	}
	printf("\n\nAfter sorting column wise : \n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}
