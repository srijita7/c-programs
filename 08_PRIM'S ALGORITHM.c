#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
int n,s=0;
int mincost(int cost[],bool visited[])
{
    int min=INT_MAX,min_index,i;
    for (i=0;i<n;i++)
    {
    	if (visited[i]==false && cost[i]<min)
        {
        	min=cost[i],min_index=i;
		}
	}
    return min_index;
}
int print(int parent[], int adj[n][n])
{
	int i;
    printf("\nEdge \tWeight\n");
    for (i=1;i<n;i++)
    {
    	printf("%d - %d \t%d \n",parent[i]+1,i+1,adj[i][parent[i]]);
    	s=s+adj[i][parent[i]];
	}
	printf("\nMinimum cost : %d",s);
}
void prim(int adj[n][n])
{
    int parent[n],i,j,u,k;
    int cost[n];
    bool visited[n];
    for (i=0;i<n;i++)
    {
    	cost[i]=INT_MAX, visited[i]=false;
	}
    cost[0]=0;
    parent[0]=-1; 
    for (j=0;j<n-1;j++) 
	{
        u=mincost(cost,visited);
        visited[u]=true;
        for (k=0;k<n;k++)
        {
        	if (adj[u][k] && visited[k] == false && adj[u][k]<cost[k])
            {
            	parent[k]=u;
				cost[k]=adj[u][k];
			}
		}
    }
    print(parent,adj);
}
int main()
{
	printf("\nEnter number of vertices : ");
	scanf("%d",&n);
    int adj[n][n],i,j;
    printf("\nEnter cost matrix : (enter 0 if no edge present)\n");
    for(i=0;i<n;i++)
    {
    	for(j=0;j<n;j++)
    	{
    		printf("%d --> %d : ",i+1,j+1);
    		scanf("%d",&adj[i][j]);
		}
	}
	printf("\nEntered cost matrix : \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",adj[i][j]);
		}
		printf("\n");
	}
    prim(adj);
    return 0;
}
