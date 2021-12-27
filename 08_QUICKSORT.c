#include<stdio.h>
void quicksort(int a[],int start,int end)
{
	int i,j,pivot,temp;
	if(start<end)
	{
	    pivot=start;
		i=start;
		j=end;
		while(i<j)
		{
			while(a[i]<=a[pivot] && i<end)
			{
				i++;
			}
			while(a[j]>a[pivot])
			{
				j--;
			}
			if(i<j)
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
		temp=a[pivot];
		a[pivot]=a[j];
		a[j]=temp;
		quicksort(a,start,j-1);
		quicksort(a,j+1,end);
	}
}
int main()
{
    int i,n;
    printf("\nEnter number of elements : ");
    scanf("%d",&n);
    int a[n];
	printf("\nEnter the elements : \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
    printf("\nlist before sorting : \n");
    for(i=0;i<n;i++)
    printf("%d  ",a[i]);
    quicksort(a,0,n-1);
    printf("\n\nList after sorting : \n");
    for(i=0;i<n;i++)
    printf("%d  ",a[i]);
}

