#include<stdio.h>
#include<stdlib.h>
#define MAX 200  
int n;    
int adj[MAX][MAX];          
int visited[MAX];              
int queue[MAX],front=-1,rear=-1;
void push_queue(int v);
void BFS()
{
	int x,i,v;
	for(i=0;i<n;i++)
    {
    	visited[i]=0;
	}
    printf("\nEnter Start Vertex : ");
    scanf("%d",&x);
    v=x-1;
    push_queue(v);
    printf("\nTraversal order : ");
    while(!queue_empty())
    { 
        v=pop_queue();
        if(visited[v])              
        	continue; 
        printf("%d ",v+1);
        visited[v]=1;
        for(i=0;i<n;i++)
        {
        	if(adj[v][i]==1 && visited[i]==0)
            {
            	push_queue(i);
            }
        }
    }
    printf("\n");
}
void push_queue(int v)
{
    if(rear==MAX-1)
    	printf("Queue Overflow\n");
    else
    {
    	if(front==-1)
        	front=0;
        rear=rear+1;
        queue[rear]=v;
    }
}
int queue_empty()
{
    if(front==-1 || front>rear)
    	return 1;
    else
    	return 0;
}
int pop_queue()
{
    int v;
    if(front==-1 || front>rear)
    {
    	printf("Queue Underflow\n");
        exit(1);
    }   
    v=queue[front];
    front=front+1;
    return v;
}
int main()
{
	int i,j;
    printf("Enter number of vertices : ");
    scanf("%d",&n);
	for(i=0;i<n;i++)
    {
   	    for(j=0;j<n;j++)
   	    {
	   		printf("%d --> %d : ",i+1,j+1);
	   		scanf("%d",&adj[i][j]);
		}
    }
    BFS();
    return 0;
}
