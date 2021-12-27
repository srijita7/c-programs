#include<stdio.h>
int a[100][100];
void print(int k,int n)
{
	int i,j;
	printf("A%d|\t",k+1);
	for(i=0;i<n;i++)
	{
		printf("%d\t",i+1);	
	}
	printf("\n------------------------------------\n");
	for(i=0;i<n;i++)
	{
		printf("%d|\t",i+1);
		for(j=0;j<n;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void shortest_path(int n)
{
	int k,i,j;
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if((a[i][k]+a[k][j])<a[i][j])
				{
					a[i][j]=a[i][k]+a[k][j];
				}
			}
		}
		print(k,n);
	}
}

int main()
{
	int n,i,j;
	printf("\nEnter number of vertices : ");
	scanf("%d",&n);
	printf("\nEnter the costs : \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("\nCost for edge %d-%d : ",i+1,j+1);
			scanf("%d",&a[i][j]);
		}
	}
	print(-1,n);
	shortest_path(n);
	return 0;
}

