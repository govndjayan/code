#include<stdio.h>
int i,j,k;
add(int a[20][20],int b[20][20],int m,int n)
{
	int c[m][n];
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		 c[i][j]=a[i][j]+b[i][j];
	}
	printf("NEW ARRAY : \n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		 printf("%d\t",c[i][j]);
		printf("\n");
	}
}
sub(int a[20][20],int b[20][20],int m,int n)
{
	int c[m][n];
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		 c[i][j]=a[i][j]-b[i][j];
	}
	printf("NEW ARRAY : \n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		 printf("%d\t",c[i][j]);
		 printf("\n");
	}
}
multiply(int a[20][20],int b[20][20],int m,int n,int p,int q)
{
	int c[m][n],k=0,res=0;
	for(i=0;i<m;i++)
        {
         for(j=0;j<q;j++)
         {
            for(k=0;k<p;k++)
            {
                res=res+a[i][k]*b[k][j];
            }
            c[i][j]=res;
            res=0;
          }
        }
        printf("Product of the matrices\n");
        for(i=0;i<m;i++)
        { 
         for(j=0;j<q;j++)
            printf("%d\t ",c[i][j]);
        printf("\n");

        }
    
}
greatest(int a[20][20],int m,int n)
{
    int max=0;
	for(i=0;i<m;i++)
	{
		max=a[i][0];
		for(j=0;j<n;j++)
		{
			if(a[i][j]>max)
			max=a[i][j];	
		}
		printf("Greatest value in %dst row: %d\n",i+1,max);
	}
}
maj_diag(int a[20][20],int m,int n)
{
	int s=0;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
		   if(i=j)
		    s=s+a[i][j];
		}
	}
	printf("Sum of major diagonal elements:%d ",s);
}
int sparse(int a[20][20],int m,int n)
{
   int sp[3][100];
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i][j]!=0)
			{
				sp[0][k]=i;
				sp[1][k]=j; 
				sp[2][k]=a[i][j];
				k++;
			}
		}
	}
	printf("\nRepresentation of Sparse Matrix:\n");
	            for(i=0;i<3;i++)
	            {
		         for(j=0;j<k;j++)
		         {
			      printf("%d\t",sp[i][j]);
		          }
	           	printf("\n");
            	}            
}
main()
{
	int ch,c;
 do
 {
  printf("\n\t-------------MAINMENU--------------------");
  printf("\n1. ADDITION OF MATRICES");
  printf("\n2. SUBTRACTION OF MATRICES");
  printf("\n3. MULTIPLICATION OF MATRICES");
  printf("\n4. GREATEST ELEMENT IN EACH ROW OF A MATRIX");
  printf("\n5. ADDITION OF MAJOR DIAGONAL ELEMENTS");
  printf("\n6. SPARSE MATRIX REPRESENTATION OF GIVEN MATRIX");
  printf("\n ENTER YOUR CHOICE : ");
  scanf("%d",&ch);
  int m,n,z=0,nz=0,p,q;
  printf("\nEnter the no.of rows:");
  scanf("%d",&m);
  printf("\nEnter the no.of coloumns:");
  scanf("%d",&n);
  int a[20][20],b[20][20];
    switch(ch)
   {
  	case 1 :  printf("Enter elements of 1st array:\n");
  	         for(i=0;i<m;i++)
  	           {
  	            for(j=0;j<n;j++)
  	            scanf("%d",&a[i][j]);
  	            printf("\n");
	           }
	           printf("Enter elements of 2nd array:\n");
  	         for(i=0;i<m;i++)
  	           {
  	            for(j=0;j<n;j++)
  	            scanf("%d",&b[i][j]);
  	            printf("\n");
  	           }
			 add(a,b,m,n);
			 break;
	case 2 : 
	         printf("Enter elements of 1st array:\n");
  	         for(i=0;i<m;i++)
  	           {
  	            for(j=0;j<n;j++)
  	            scanf("%d",&a[i][j]);
  	            printf("\n");
	           }
	           printf("Enter elements of 2nd array:\n");
  	         for(i=0;i<m;i++)
  	           {
  	            for(j=0;j<n;j++)
  	            scanf("%d",&b[i][j]);
  	            printf("\n");
	           }
	           sub(a,b,m,n);
	         break;
	case 3 : printf("\nEnter elements of 1st array:\n");
  	         for(i=0;i<m;i++)
  	           {
  	            for(j=0;j<n;j++)
  	            scanf("%d",&a[i][j]);
  	            printf("\n");
	           }
	           printf("Enter the no.of rows and coloumns for 2nd matrix:\n");
	           scanf("%d",&p);
	           scanf("%d",&q);
	           if(n!=p)
        	   printf("\nMultiplication is not possible");
        	   else
        	   {
	           printf("Enter elements of 2nd array:\n");
  	         for(i=0;i<p;i++)
  	           {
  	            for(j=0;j<q;j++)
  	            scanf("%d",&b[i][j]);
  	            printf("\n");
	           }
	           multiply(a,b,m,n,p,q);
	       }
	         break;
	case 4 : printf("\nEnter elements of the array:");
  	         for(i=0;i<m;i++)
  	           {
  	            for(j=0;j<n;j++)
  	            scanf("%d",&a[i][j]);
  	            printf("\n");
	           }
	           greatest(a,m,n);
	           break;
	case 5 : printf("Enter elements of array:\n");
  	         for(i=0;i<m;i++)
  	           {
  	            for(j=0;j<n;j++)
  	            scanf("%d",&a[i][j]);
  	            printf("\n");
	           }
	           maj_diag(a,m,n);
	           break;
	case 6 : printf("Enter elements of 1st array:\n"); 
  	         for(i=0;i<m;i++)
  	           {
  	            for(j=0;j<n;j++)
  	            {
				  scanf("%d",&a[i][j]);
				  if(a[i][j]==0)
				  z++;
				  else
				  nz++;
			    }
  	            printf("\n");
	           }
	           if(z>nz)	           
			    sparse(a,m,n);
			   else
	           printf("Entered MAtrix is not a sparse matrix");
	           break;    	
        }
      
    printf("\n Do u want to continue:(yes-1/no-2)");
    scanf("%d",&c);
}
while(c==1);
}
