#include<stdio.h>
#include<stdlib.h>
int count(int m,int n,int a[m][n])
{
	int c=0,i,j;
	for(i=0;i<m;i++)
	{
		if(i%2==0)
		{
			for(j=0;j<n-1;j++)
			{
				if(a[i][j+1]>=a[i][j])
				{
					c++;
				}
				else
				return 0;
			}
			if(i==m-1)
			return c;
			if(a[i][j]<=a[i+1][j])
			{
				c++;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			for(j=n-1;j>0;j--)
			{
				if(a[i][j-1]>=a[i][j])
				{
					c++;
				}
				else
				return 0;
			}
			if(i==m-1)
			return c;
			if(a[i][j]<=a[i+1][j])
			{
				c++;
			}
			else
			{
				return 0;
			}
		}
	}
	return c;
}
void column_wise(int m,int n,int a[m][n])
{
	int i,j,k,temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m-1;j++)
		{
			for(k=0;k<m-j-1;k++)
			{
				if(a[k][i]>a[k+1][i])
				{
					temp=a[k][i];
					a[k][i]=a[k+1][i];
					a[k+1][i]=temp;
				}
			}
		}
	}
}
void row_sort(int m,int n,int a[m][n])
{
	int i,j,k,temp;
	for(i=0;i<m;i++)
	{
		if(i%2==0)
		{
			for(j=0;j<n-1;j++)
			{
				for(k=0;k<n-j-1;k++)
				{
					if(a[i][k]>a[i][k+1])
					{
						temp=a[i][k];
						a[i][k]=a[i][k+1];
						a[i][k+1]=temp;
					}
				}
			}
		}
		else
		{
			for(j=0;j<n-1;j++)
			{
				for(k=0;k<n-j-1;k++)
				{
					if(a[i][k]<a[i][k+1])
					{
						temp=a[i][k];
						a[i][k]=a[i][k+1];
						a[i][k+1]=temp;
					}
				}
			}
		}
	}
}
int main()
{
	int m,n,i,j,temp,key,k,c=0,p=1;
	printf("\nEnter number of rows : ");
	scanf("%d",&m);
	printf("\nEnter number of columns : ");
	scanf("%d",&n);
	if(m==0 || n==0)
	{
		printf("\nInvalid input");
		exit(0);
	}
	int a[m][n];
	printf("\nEnter the elements : \n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("a[%d][%d] : ",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	printf("\nInitial phase : \n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	c=count(m,n,a);
	while(c!=(m*n)-1)
	{
		if(p%2==1)
		{
			row_sort(m,n,a);
		}
		else
		{
			column_wise(m,n,a);
		}
		printf("\nAfter Phase %d : \n",p);
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				printf("%d ",a[i][j]);
			}
			printf("\n");
		}
		p++;
		c=count(m,n,a);
	}
}
