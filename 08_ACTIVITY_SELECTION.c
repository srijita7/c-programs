#include<stdio.h>
struct activity
{
	int num;
	int start,finish;
};
int partition(struct activity a[],int l,int r)
{
	int pivot=a[r].finish,i=l-1,j;
	struct activity temp;
	for(j=l;j<=r-1;j++)
	{
		if(a[j].finish<pivot)
		{
			i++;
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	temp=a[i+1];
	a[i+1]=a[r];
	a[r]=temp;
	return i+1;
}
void quicksort(struct activity a[],int l,int r)
{
	if(l<r)
	{
		int pi=partition(a,l,r);
		quicksort(a,l,pi-1);
		quicksort(a,pi+1,r);
	}
}
int main()
{
	int n,i,j;
	printf("\nEnter number of activities : ");
	scanf("%d",&n);
	struct activity a[n];
	printf("\nEnter the starting and finishing time of activities : \n");
	for(i=0;i<n;i++)
	{
		printf("Activity %d : \n",i+1);
		a[i].num=i+1;
		printf("Start time : ");
		scanf("%d",&a[i].start);
		printf("Finish time : ");
		scanf("%d",&a[i].finish);
	}
	printf("\nEntered data : \n");
	printf("Activity Start Finish\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i].num);
		printf("%d\t",a[i].start);
		printf("%d\t",a[i].finish);
		printf("\n");
	}
	quicksort(a,0,n-1);
	printf("\nAfter sorting on the besis of increasing finish time : \n");
	printf("Activity Start Finish\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i].num);
		printf("%d\t",a[i].start);
		printf("%d\t",a[i].finish);
		printf("\n");
	}
	i=0;
	printf("\nFollowing activities are selected : ");
	printf("%d ",a[0].num);
	for(j=1;j<n;j++)
	{
		if(a[j].start>=a[i].finish  && a[j].start<a[j].finish)
		{
			printf("%d ",a[j].num);
			i=j;
		}
	}
}
