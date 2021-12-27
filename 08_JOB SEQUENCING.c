#include<stdio.h>
int sp_case(int a[],int range);
int main()
{
	int n,i,j,temp,max_d,total_p=0;
	printf("\nEnter number of jobs : ");
	scanf("%d",&n);
	int job[n],p[n],d[n];
	for(i=0;i<n;i++)
	{
		job[i]=i+1;
	}
	printf("\nEnter the deadlines : ");
	for(i=0;i<n;i++)
	{
		printf("\nJob %d Deadline : ",i+1);
		scanf("%d",&d[i]);
	}
	printf("\nEnter the profits : ");
	for(i=0;i<n;i++)
	{
		printf("\nJob %d Profit: ",i+1);
		scanf("%d",&p[i]);
	}
	printf("\nEntered Data : \n");
	printf("\nJob Deadline Profit\n");
	for(i=0;i<n;i++)
	{
		printf(" %d      %d      %d\n",job[i],d[i],p[i]);
	}
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(p[j]<p[j+1])
			{
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
				
				temp=job[j];
				job[j]=job[j+1];
				job[j+1]=temp;
				
				temp=d[j];
				d[j]=d[j+1];
				d[j+1]=temp;
			}
		}
	}
	max_d=d[0];
	for(i=0;i<n;i++)
	{
		if(d[i]>max_d)
		max_d=d[i];
	}
	for(i=0;i<max_d-1;i++)
	{
		for(j=0;j<max_d-i-1;j++)
		{
			if(d[j]>d[j+1])
			{
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
				
				temp=job[j];
				job[j]=job[j+1];
				job[j+1]=temp;
				
				temp=d[j];
				d[j]=d[j+1];
				d[j+1]=temp;
			}
		}
	}
	if(sp_case(d,max_d)==0)
	printf("\nSpecial case");
	else
	{
		for(i=0;i<max_d;i++)
		{
			total_p=total_p+p[i];
		}
		printf("\nJob Processing Sequence :\n");
		for(i=0;i<max_d;i++)
		{
			printf("%d  ",job[i]);
		}
		printf("\n\nTotal profit : %d",total_p);
		}
}
int sp_case(int a[],int range)
{
	int i;
	for(i=0;i<range;i++)
	{
		if(a[i]<=i)
		return 0;
	}
	return 1;
}
