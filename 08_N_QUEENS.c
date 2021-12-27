#include<stdio.h>
#include<math.h>
int place(int k,int i);
void display(int n);
void nqueens(int k,int n);
int board[30],count=0;
int main()
{
	int n;
	printf("\nEnter number of queens : ");
	scanf("%d",&n);
	printf("\n");
	nqueens(1,n);
	printf("\nTotal Number of solutions : %d",count);
}
int place(int k,int i)
{
	int j;
	for(j=1;j<=k-1;j++)
	{
		if((board[j]==i) || (abs(board[j]-i)==abs(j-k)))
		{
			return 0;
		}
	}
	return 1;
}
void display(int n)
{
	int i,j;
	count++;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(j-1==board[i])
			printf("Q\t");
			else
			printf("-\t");
		}
		printf("\n");
	}
	printf("\n\n");
	printf("Solution %d : [ ",count);
	for(i=1;i<=n;i++)
	{
		if(i==n)
		printf("%d  ",board[i]+1);
		else
		printf("%d,  ",board[i]+1);
	}
	printf("]\n\n");
}
void nqueens(int k,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(place(k,i)==1)
		{
			board[k]=i;
			if(k==n)
			{
				display(n);
			}
			else
			{
				nqueens(k+1,n);
			}
		}
	}
}
