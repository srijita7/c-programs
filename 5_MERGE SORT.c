#include<stdio.h>
void mergesort(int arr[],int l,int r);
void merge(int arr[],int p,int q,int r);
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
    mergesort(a,0,n-1);
    printf("\n\nList after sorting : \n");
    for(i=0;i<n;i++)
    printf("%d  ",a[i]);
}
void merge(int arr[],int p,int q,int r) 
{
	int i,j,k;
    int n1=q-p+1;
    int n2=r-q;
    int le[n1],ri[n2];
    for (i=0;i<n1;i++)
    	le[i]=arr[p+i];
    for (j=0;j<n2;j++)
    	ri[j]=arr[q+1+j];
  	i=0;
  	j=0;
  	k=p;
    while (i<n1 && j<n2) 
	{
    if (le[i]<=ri[j]) 
	{
      arr[k]=le[i];
      i++;
    } 
	else 
	{
      arr[k]=ri[j];
      j++;
    }
    k++;
  }
  while (i<n1) 
  {
    arr[k]=le[i];
    i++;
    k++;
  }
  while (j<n2) 
  {
    arr[k]=ri[j];
    j++;
    k++;
  }
}
void mergesort(int arr[],int l,int r) 
{
  if (l<r) 
  {
    int m=l+(r-l)/ 2;
    mergesort(arr,l,m);
    mergesort(arr,m+1,r);
    merge(arr,l,m,r);
  }
}


