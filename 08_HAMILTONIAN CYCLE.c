#include<stdio.h>
#include<stdlib.h>
int adj[100][100],x[100];
int n,c=0;
void nextvalue(int k);
void hamiltonian(int k);
int main()
{
	int i,j;
	printf("\nEnter number of vertices : ");
	scanf("%d",&n);
	printf("\nEnter the adjacency matrix : \n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d --> %d : ",i,j);
			scanf("%d",&adj[i][j]);
		}
	}
	printf("\nAdjacency matrix : \n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d ",adj[i][j]);
		}
		printf("\n");
	}
	hamiltonian(1);
	printf("\nTotal number of solutions : %d",c);
}
void nextvalue(int k)
{
	int j;
	while(1)
	{
		x[k]=(x[k]+1)%(n+1);
		if(x[k]==0)
		return;
		if(adj[x[k-1]][x[k]]!=0)
		{
			for(j=1;j<=k-1;j++)
			{
				if(x[j]==x[k])
				break;
			}
			if(j==k)
			{
				if((k<n) || ((k==n) && adj[x[n]][x[1]]!=0))
				return;
			}
		}
	}
}
void hamiltonian(int k)
{
	int i;
	while(1)
	{
		nextvalue(k);
		if(x[k]==0)
		return;
		if(k==n)
		{
			c++;
			printf("\nSolution : %d",c);
			for(i=1;i<n;i++)
			{
				printf("%d ",x[i]);
			}
			printf("%d",x[1]);
		}
		else
		hamiltonian(k+1);
	}
}
