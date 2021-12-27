#include<stdio.h>
void knapsack(int n,float w[],float p[],float capacity,int index[]) 
{
	float sol_vector[n],tp=0.0;
	int i,j,rem_w;
	rem_w=capacity;
	for (i=0;i<n;i++)
	{
		sol_vector[i]=0.0;
	}
	for (i=0;i<n;i++) 
	{
		if (w[i]>rem_w)
        	break;
		else 
		{
	        sol_vector[index[i]]=1.0;
	        tp=tp+p[i];
	        rem_w=rem_w-w[i];
    	}
	}
    if (i<n)
    	sol_vector[index[i]]=rem_w/w[i];
   	tp=tp+(sol_vector[index[i]]*p[i]);
    printf("\nThe solution vector is : { ");
    for (i=0;i<n;i++)
    {
    	if(i==n-1)
    	printf("%0.2f }",sol_vector[i]);
    	else
    	printf("%0.2f, ",sol_vector[i]);
	}
    printf("\n\nMaximum profit is : %0.2f\n",tp);
}
void stat2(int n,float w[],float p[],float capacity,int index[])
{
	float ratio[n],temp;
	int i,j;
	for (i=0;i<n;i++)
	{
    	ratio[i]=p[i]/w[i];
    }
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
 			if(w[j]>w[j+1])
 			{
 				temp=ratio[j];
 				ratio[j]=ratio[j+1];
 				ratio[j+1]=temp;
 				
 				temp=w[j];
 				w[j]=w[j+1];
 				w[j+1]=temp;
 				
 				temp=p[j];
 				p[j]=p[j+1];
 				p[j+1]=temp;
 				
 				temp=index[j];
 				index[j]=index[j+1];
 				index[j+1]=temp;
			}
		}
	}
	printf("\n");
	knapsack(n,w,p,capacity,index);
}
void stat1(int n,float w[],float p[],float capacity,int index[])
{
	float ratio[n],temp;
	int i,j;
	for (i=0;i<n;i++)
	{
      ratio[i]=p[i]/w[i];
    }
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
 			if(p[j]<p[j+1])
 			{
 				temp=ratio[j];
 				ratio[j]=ratio[j+1];
 				ratio[j+1]=temp;
 				
 				temp=w[j];
 				w[j]=w[j+1];
 				w[j+1]=temp;
 				
 				temp=p[j];
 				p[j]=p[j+1];
 				p[j+1]=temp;
 				
 				temp=index[j];
 				index[j]=index[j+1];
 				index[j+1]=temp;
			}
		}
	}
	knapsack(n,w,p,capacity,index);
}
void stat3(int n,float w[],float p[],float capacity,int index[])
{
	float ratio[n],temp;
	int i,j;
	for (i=0;i<n;i++)
	{
      ratio[i]=p[i]/w[i];
    }
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
 			if(ratio[j]<ratio[j+1])
 			{
 				temp=ratio[j];
 				ratio[j]=ratio[j+1];
 				ratio[j+1]=temp;
 				
 				temp=w[j];
 				w[j]=w[j+1];
 				w[j+1]=temp;
 				
 				temp=p[j];
 				p[j]=p[j+1];
 				p[j+1]=temp;
 				
 				temp=index[j];
 				index[j]=index[j+1];
 				index[j+1]=temp;
			}
		}
	}
	knapsack(n,w,p,capacity,index);
}
int main() 
{
	int n,i,choice,c=0;
	printf("\nEnter number of items : ");
	scanf("%d",&n);
	int index[n];
	float p[n],w[n],capacity;
	printf("\nEnter the profits : \n");
	for(i=0;i<n;i++)
	{
		scanf("%f",&p[i]);
	}
	printf("\nEnter the weights : \n");
	for(i=0;i<n;i++)
	{
		scanf("%f",&w[i]);
	}
	for(i=0;i<n;i++)
	{
		index[i]=i;
	}
	printf("\nEnter the maximum capacity of knapsack : ");
	scanf("%f",&capacity);
    printf("\n1. Decreasing order of profit \n2. Increasing Order of weight\n3. Decreasing order of per unit profit \n");
    while(c<3)
	{
		printf("\nEnter choice : ");
    	scanf("%d",&choice);
		switch(choice)
		{
			case 1: 
			{
				stat1(n,w,p,capacity,index);
				c++;
				break;
			}
			case 2:
			{
				stat2(n,w,p,capacity,index);
				c++;
				break;	
			}
			case 3:
			{
				stat3(n,w,p,capacity,index);
				c++;
				break;
			}
			default:
				printf("\nInvalid Input");
		}
	}
}
