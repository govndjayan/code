 #include<stdio.h>
#include<stdlib.h>

void display(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}

void merge(int a[],int p,int q,int r)
{
	int i,j,k;
	int n1=q-p+1;
	int n2=r-q;
	int L[n1+1],R[n2+1];
	for(i=0;i<n1;i++)
	L[i]=a[p+i];
	for(j=0;j<n2;j++)
	R[j]=a[q+1+j];
	
	
	i=0;
	j=0;
	k=p;
	while(i<n1 && j<n2)
	{
		if(L[i]<R[j])
		{
			a[k]=L[i];
			i++;
		}
		else
		{
			a[k]=R[j];
			j++;
		}
		
		k++;
	}
	while(i<n1)
	{
		a[k]=L[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		a[k]=R[j];
		j++;
		k++;
	}
	printf("\nMerging\n");
	display(a,k);
}

void mergesort(int a[],int p,int r)
{
	int q;
	if(p<r && p!=r)
	{
		q=(p+r)/2;
		mergesort(a,p,q);
		
		mergesort(a,q+1,r);
		
		merge(a,p,q,r);
		
	}
}

int main()
{
	int a[10],n,i;
	printf("Enter the size of the array:");
	scanf("%d",&n);
	printf("Enter the array elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\nGiven array:\n");
	display(a,n);
	mergesort(a,0,n-1);
	printf("\nSorted array:\n");
	display(a,n);
	return 0;
}
