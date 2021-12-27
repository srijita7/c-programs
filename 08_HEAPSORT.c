#include<stdio.h>
void maxheapify(int a[],int i,int n)
{
	int largest=i,left=(2*i)+1,right=(2*i)+2,temp;
	if(left<n && a[left]>a[largest])
	{
		largest=left;
	}
	if(right<n && a[right]>a[largest])
	{
		largest=right;
	}
	if(largest!=i)
	{
		temp=a[i];
		a[i]=a[largest];
		a[largest]=temp;
		maxheapify(a,largest,n);
	}
}
void heapsort(int a[],int n)
{
	int i,temp;
	for(i=n/2-1;i>=0;i--)
	{
		maxheapify(a,i,n);
	}
	for(i=n-1;i>=0;i--)
	{
		temp=a[0];
		a[0]=a[i];
		a[i]=temp;
		maxheapify(a,0,i);
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
    heapsort(a,n);
    printf("\n\nList after sorting : \n");
    for(i=0;i<n;i++)
    printf("%d  ",a[i]);
}

