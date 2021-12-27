#include<stdio.h>
#include<limits.h>
void bellman_ford(int src,int cost[][3],int e,int v)
{
	int i,dist[v],j,weight,x,y,k;
	for(i=0;i<v;i++)
	{
		dist[i]=INT_MAX;
	}
	dist[src]=0;
	for(i=0;i<v-1;i++)
	{
		for(j=0;j<e;j++)
		{
			if(dist[cost[j][0]]!=INT_MAX && dist[cost[j][0]]+cost[j][2]<dist[cost[j][1]])
			{
				dist[cost[j][1]]=dist[cost[j][0]]+cost[j][2];
			}
			printf("%d\t",dist[j]);
		}
		printf("\n");
	}
	for(i=0;i<e;i++)
	{
		x=cost[i][0];
		y=cost[i][1];
		weight=cost[i][2];
		if(dist[x]!=INT_MAX && dist[x]+weight<dist[y])
		{
			printf("\nGraph contains negative edge cycle\n");
		}
	}
}
int main()
{
	int n,m,i;
	printf("\nEnter number of vertices : ");
	scanf("%d",&m);
	printf("\nEnter number of edges : ");
	scanf("%d",&n);
	int cost[n][3];
	printf("\nEnter the source vertex, destination vertex and weight : \n");
	for(i=0;i<n;i++)
	{
		scanf("%d,%d,%d",&cost[i][0],&cost[i][1],&cost[i][2]);
	}
	bellman_ford(0,cost,n,m);
}
