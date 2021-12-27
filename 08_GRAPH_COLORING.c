#include<stdio.h>
int m,n,count=0;
int a[100][100],color[100];
int issafe(int v,int col)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		if(a[v][i]==1 && color[i]==col)
		return 0;
	}
	return 1;
}
void colorable(int i)
{
	int j,k,l;
	if(i==n)
	{
		count++;
		printf("\nSolution %d : ",count);
		for(l=0;l<n;l++)
		{
			printf("%d ",color[l]);
		}
		return;
	}
	for(k=1;k<=m;k++)
	{
		if(issafe(i,k))
		{
			color[i]=k;
			colorable(i+1);
			color[i]=0;
		}
	}
}
int main()
{
	int i,j;
	printf("\nEnter number of vertices : ");
	scanf("%d",&n);
	printf("\nEnter adjacency matrix : \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d --> %d : ",i+1,j+1);
			scanf("%d",&a[i][j]);
		}
	}
	printf("\nEnter number of colors : ");
	scanf("%d",&m);
	printf("\nAdjacency matrix : \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	colorable(0);
}
