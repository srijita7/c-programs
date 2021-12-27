#include <stdio.h>
int main()
{
	int n,p,q,r,s,t,u,v,i,j;
	n=2;
	int a[n][n],b[n][n],c[n][n];
	printf("\nEnter elements of first matrix : \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("a%d%d : ",i+1,j+1);
			scanf("%d",&a[i][j]);
		}
	}
	printf("\nEnter elements of second matrix : \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("b%d%d : ",i+1,j+1);
			scanf("%d",&b[i][j]);
		}
	}
	printf("\nFirst matrix entered : \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	printf("\nSecond matrix entered : \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",b[i][j]);
		}
		printf("\n");
	}
	p=(a[0][0]+a[1][1])*(b[0][0]+b[1][1]);
	q=(a[1][0]+a[1][1])*(b[0][0]);
	r=(a[0][0])*(b[0][1]-b[1][1]);
	s=(a[1][1])*(b[1][0]-b[0][0]);
	t=(a[0][0]+a[0][1])*(b[1][1]);
	u=(a[1][0]-a[0][0])*(b[0][0]+b[0][1]);
	v=(a[0][1]-a[1][1])*(b[1][0]+b[1][1]);
	c[0][0]=p+s-t+v;
	c[0][1]=r+t;
	c[1][0]=q+s;
	c[1][1]=p+r-q+u;
	printf("\nResultant matrix : \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",c[i][j]);
		}
		printf("\n");
	}
}
