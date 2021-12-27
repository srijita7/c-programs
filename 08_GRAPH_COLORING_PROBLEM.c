#include<stdio.h>
int m,n,count=0;
int a[100][100],x[100];
void mcoloring(int k);
void nextvalue(int k);
void mcoloring(int k)
{
	int l;
	while(1)
	{
		nextvalue(k);
		if(x[k]==0)
		return;
		if(k==n)
		{
			count++;
			printf("\nSolution %d : ",count);
			printf("[ ");
			for(l=1;l<=n;l++)
			{
				if(l==n)
				printf("%d ",x[l]);
				else
				printf("%d, ",x[l]);
			}
			printf("]");
		}
		else
		{
			mcoloring(k+1);
		}
	}
}
void nextvalue(int k)
{
	int j;
	while(1)
	{
		x[k]=(x[k]+1)%(m+1);
		if(x[k]==0)
		return;
		for(j=1;j<=n;j++)
		{
			if((a[k][j]==1) && (x[k]==x[j]))
			{
				break;
			}
		}
		if(j==n+1)
		return;
	}
}
int main()
{
	int i,j;
	printf("\nEnter number of vertices : ");
	scanf("%d",&n);
	printf("\nEnter adjacency matrix : \n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d --> %d : ",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	printf("\nEnter number of colors : ");
	scanf("%d",&m);
	printf("\nAdjacency matrix : \n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	mcoloring(1);
	printf("\n\nTotal number of solutions : %d",count);
}
