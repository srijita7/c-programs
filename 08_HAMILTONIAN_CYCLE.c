#include<stdio.h>
int c,n;
void next_value(int adj[n][n],int x[],int k,int n)
{
	int i,j;
	while(1)
	{
		x[k]=(x[k]+1)%(n+1);		
		if(x[k]==0)
		{
			return;
		}
		if(k==1)
		return;			
		if(adj[x[k-1]][x[k]]!=0)
		{
			for(j=1;j<=k-1;j++)
			{
				if(x[j]==x[k])
				{
					break;
				}					
			}
			if(j==(k-1))
			{
				if((k<n) || ((k==n) && (adj[x[n]][x[1]]!=0)))
				{
					return;
				}
			}
		}
	}
}
void hamiltonian_cycle(int adj[n][n],int k)
{
	int i;
	while(1)
	{
		next_value(k,n);		
		if(x[k]==0)
		{
			return;
		}			
		if(k==n)
		{
			c++;
			printf("\nSolution %d : ",c);
			for(i=1;i<=n;i++)
			{
				printf("%d ",x[i]);
			}
			printf("%d",x[1]);
			printf("\n");
		}			
		else
		{
			hamiltonian_cycle(k+1,n);
		}			
	}
}
int main()
{
	int i,j;
	printf("\nEnter the no of vertices : ");
	scanf("%d",&n);	
	printf("Enter the Adjacency matrix : \n");
   	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
				printf("%d --> %d : ",i,j);
   				scanf("%d",&adj[i][j]);
		}
	}	
	hamiltonian_cycle(adj,1);
	printf("\nTotal no of solutions : %d\n",c);	
}
