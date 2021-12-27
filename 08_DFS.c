#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define nottraversed 1
#define traversed 2
int n,a[MAX][MAX],visited[MAX],stack[MAX],top=-1;
void DFS(int v);
void push(int v);
int pop();
int main()
{
    int i,j,v;
    printf("Enter number of vertices : ");
    scanf("%d",&n);
    printf("\nEnter the adjacency matrix : \n");
    for(i=1;i<=n;i++)
    {
	   	for(j=1;j<=n;j++)
	   	{
	   		printf("%d --> %d : ",i,j);
	   		scanf("%d",&a[i][j]);
		}
    }
    printf("\nAdjacency matrix : \n\n");
    for(i=1;i<=n;i++)
    {
    	for(j=1;j<=n;j++)
    	{
    		printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	printf("\nDFS traversal order : \n");
    for(v=1; v<=n; v++)
    {
    	visited[v]=nottraversed;
	}
    DFS(1);
} 
void push(int v)
{
        if(top==(MAX-1))
        {
                printf("\nStack Overflow\n");
                return;
        }
        top=top+1;
        stack[top] = v;
}
void DFS(int v)
{
        int i;
        push(v);
        while(top!=-1)
        {
                v=pop();
                if(visited[v]==nottraversed)
                {
                    printf("%d ",v);
                    visited[v]=traversed;
                }
                for(i=n;i>=1;i--)
                {
                    if(a[v][i]==1 && visited[i]==nottraversed)
                        push(i);
                }
        }
}
int pop()
{
        int v;
        if(top==-1)
        {
            printf("\nStack Underflow\n");
            exit(1);
        }
        else
        {
            v = stack[top];
            top=top-1;
            return v;
        }
}
