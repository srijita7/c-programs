#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int nstates,nsymbols,nfinal,i,e,j,k,*states,initial,*final,flag1=0,flag2=0,flag;
	char *symbols,*string;
	printf("\nEnter number of symbols : ");
	scanf("%d",&nsymbols);
	symbols=(char*)malloc(nsymbols*sizeof(char));
	printf("\nEnter the symbols of the alphabet set : \n");
	for(i=0;i<nsymbols;i++)
	{
		fflush(stdin);
		scanf("%c",(symbols+i));
	}
	printf("\nEnter total number of states : ");
	scanf("%d",&nstates);
	states=(int*)malloc(nstates*sizeof(int));
	printf("\nEnter the states (enter integers) : \n");
	for(i=0;i<nstates;i++)
	{
		scanf("%d",(states+i));
	}
	printf("\nEnter initial state (enter integer): ");
	scanf("%d",&initial);
	printf("\nEnter number of final states : ");
	scanf("%d",&nfinal);
	if(nfinal>nstates)
	{
		printf("\nNumber of final states cannot be greater than total number of states");
		exit(0);
	}
	final=(int*)malloc(nfinal*sizeof(int));
	printf("\nEnter the final state/states (enter integer): \n");
	for(i=0;i<nfinal;i++)
	{
		flag=0;
		scanf("%d",&e);
		for(j=0;j<nstates;j++)
		{
			if(e==*(states+j))
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			*(final+i)=e;
		}
		else
		{
			printf("\nEntered final state not present in the set of states");
			break;
		}
	}
	int **q=(int**)malloc(nstates*sizeof(int*));
	for(i=0;i<nstates;i++)
	{
		*(q+i)=(int*)malloc(nsymbols*sizeof(int*));
	}
	printf("Enter the transitions (enter integers for states) : \n");
	for(i=0;i<nstates;i++)
	{
		for(j=0;j<nsymbols;j++)
		{
			printf("q[%d , %c] : ",i,*(symbols+j));
			scanf("%d",(*(q+i)+j));
		}
	}
	printf("\nEntered transition table : \n");
	printf("        ");
	for(i=0;i<nsymbols;i++)
	{
		printf("%c    ",*(symbols+i));
	}
	printf("\n");
	for(i=0;i<nstates;i++)
	{
		printf("q[%d] : ",i);
		for(j=0;j<nsymbols;j++)
		{
			printf("q[%d] ",*(*(q+i)+j));
		}
		printf("\n");
	}
	string=(char*)malloc(nsymbols*sizeof(char));
	printf("\nEnter string : \n");
	scanf(" ");
	gets(string);
	for(i=0;*(string+i)!='\0';i++)
	{
	    k=initial;
	    flag1=0;
		for(j=0;j<nsymbols;j++)
	    {
		    if(*(symbols+j)==*(string+i))
			{	
			    initial=*(*(q+k)+j);
				flag1=1;
				break;
		    }
		}
		if(flag1!=1)
		{
			printf("\nInvalid Input (symbol not present in alphabet set)");
			exit(0);
		}
	}
	for(i=0;i<nfinal;i++)
	{
		if(initial==*(final+i))
		{
			printf("\nString Accepted");
			flag2=1;
			break;
		}
	}
	if(flag2!=1)
	printf("\nString Not Accepted");
}

