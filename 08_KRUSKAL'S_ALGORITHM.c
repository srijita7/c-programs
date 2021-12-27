#include<stdio.h>
#include<limits.h>
int find_set(int n,int i,int parent[]);
void union_find(int n,int parent[],int i,int j);
void kruskal(int n,int cost[n][n]);
int find_set(int n,int i,int parent[])
{
	while(parent[i]!=i)
	{
		i=parent[i];
	}
	return i;
}
void union_find(int n,int parent[],int i,int j)
{
	int p,q;
	p=find_set(n,i,parent);
	q=find_set(n,j,parent);
	parent[p]=q;
}
void kruskal(int n,int cost[n][n])
{
	int a,b,i,j,min,p,q;
	int count=0;
	int total_cost=0;
	int parent[n];
	for(i=0;i<n;i++)
	{
		parent[i]=i;
	}
	while(count<n-1)
	{
		min=INT_MAX;
		a=-1;
		b=-1;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(find_set(n,i,parent)!=find_set(n,j,parent) && cost[i][j]<min)
				{
					min=cost[i][j];
					a=i;
					b=j;
				}
			}
		}
		union_find(n,parent,a,b);
		printf("\nEdge %d --> %d , cost : %d",a+1,b+1,min);
		total_cost=total_cost+min;
		count++;
	}
	printf("\n\nMinimum cost : %d",total_cost);
}
int main()
{
	int n,j,i,l;
	printf("\nEnter number of nodes : ");
	scanf("%d",&n);
	int cost[n][n];
	printf("\nEnter the cost matrix (enter 999 if edge not present): \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d --> %d : ",i+1,j+1);
			scanf("%d",&l);
			if(l>=999)
			cost[i][j]=INT_MAX;
			else
			cost[i][j]=l;
		}
	}
	printf("\nEntered cost matrix : \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(cost[i][j]>=999)
			{
				printf("INF\t");
			}
			else
			printf("%d\t",cost[i][j]);
		}
		printf("\n");
	}
	printf("\nEdges of minimum spanning tree using Kruskal's algorithm : \n");
	kruskal(n,cost);
}
