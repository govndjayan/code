#include <stdio.h>

void bubblesort(int a[],int n )
{
    int i,j,k,temp;
    printf("Unsorted data:");
    for(k=0;k<n;k++)
    {
        printf("%d ",a[k]);
    }
    
    for(i=1;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
        
    printf("\nPass %d: ",i);
    for(k=0;k<n;k++)
      {
        printf("%d ",a[k]);
      }
    }
    
}

void insertion(int a[],int n)
{
    int i,j,k,temp;
    printf("Unsorted data:");
    for(k=0;k<n;k++)
    {
        printf("%d ",a[k]);
    }
    for(i=0;i<n;i++)
    {
        j=i;
        while(j<=i && j>0)
        {
            if(a[j]<a[j-1])
            {
                temp=a[j];
                a[j]=a[j-1];
                a[j-1]=temp;
            }
            j--;
        }
        
    printf("\nPass %d: ",i+1);
    for(k=0;k<n;k++)
      {
        printf("%d ",a[k]);
      }
    }
}
 
void selection(int a[],int n)
{
    int i,j,k,temp,min,position;
    printf("Unsorted data:");
    for(k=0;k<n;k++)
    {
        printf("%d ",a[k]);
    }
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[min]>a[j])
            {
                min=j;
            }
        }
        
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
        printf("\nPass %d: ",i+1);
        for(k=0;k<n;k++)
        {
          printf("%d ",a[k]);
        }
        
    }
    
}
   
int main()
{
	 int a[10],n,i,s,ch;
	do
	{
    printf("How many elements you want in your array?\n");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nSORTING TECHNIQUES:\n");
    printf("\n1.Bubble sort");
    printf("\n2.Insertion sort");
    printf("\n3.Selection sort");
    printf("\nEnter your choice:");
    scanf("%d",&s);
    switch(s)
    {
        case 1:
        bubblesort(a,n);
        break;
        
        case 2:
        insertion(a,n);
        break;
        
        case 3:
        selection(a,n);
        break;
        
        default:
        printf("Invalid choice!");
    }
    printf("\n DO U WANT TO CONTINUE:(1-YES/0-NO)");
    scanf("%d",&ch);
   } 
   while(ch==1); 
    return 0;
}
        
    


    

    


