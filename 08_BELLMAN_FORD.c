#include<stdio.h>
void bellman_ford(int* adj,int* b,int n,int k);
int main()
{
	int n,src,i,j;
	printf("\nEnter number of vertices : ");
	scanf("%d",&n);
	int adj[n][n];
	printf("\nEnter the weights (999 for infinity) : \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d --> %d : ",i+1,j+1);
			scanf("%d",&adj[i][j]);
		}
	}
	printf("\nAdjacency matrix : \n\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",adj[i][j]);
		}
		printf("\n");
	}
	printf("\nEnter the source vertex : ");
	scanf("%d",&src);
	int b[n+2][n];
	b[0][0]=src-1; b[1][0]=0;
	for(j=1;j<n;j++)
	{
		if(j>src-1)
		{
			b[0][j]=j;
		}
		else
		{
			b[0][j]=j-1;
		}
	}
	for(j=1;j<n;j++)
	{
		b[1][j]=999;
	}
	bellman_ford(*adj,*b,n,1);
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("        %d",b[0][i]+1);
	}
	printf("\n");
	printf("-------------------------------------------------");
	printf("\n");
	for(i=2;i<n+1;i++)
	{
		printf("  %d|  ",i-1); 
        for(j=0;j<n;j++)
		{
			if(b[i][j]>100)
			printf("\tI");
			else
            printf("\t%d",b[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<n;i++)
	{
        if(b[n+1][i]!=b[n][i])
		{
            printf("\nNEGATIVE EDGE CYCLE PRESENT");
            return 0;
        }
    }
}
void bellman_ford(int* adj,int* b,int n,int k)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		*(b+(k+1) *n+i)=*(b+k*n+i);
		for(j=0;j<n;j++)
		{
			if(*(b+(k+1)*n+i)>*(b+k*n+j)+*(adj+*(b+j)*n+*(b+i)))
			{
				*(b+(k+1)*n+i)=*(b+k*n+j)+*(adj+*(b+j)*n+*(b+i));
			}
		}
	}
	if(k<n)
	bellman_ford(adj,b,n,k+1);
}
