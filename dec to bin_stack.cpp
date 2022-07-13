//decimal to binary using stack
#include<stdio.h>
int stack[50],n,top=-1;
void push();
void pop();
main()
{
	printf("Enter the decimal number to be converted to binary. ");
	scanf("%d",&n);
	push();
	pop();
}
void push()
{
int x;
while(n>0)
{
	x=n%2;
    top++;
	stack[top]=x;
	n=n/2;
}
}
void pop()
{
		printf("\nThe binary number is : ");
		for(int i=top;i>=0;i--)
		printf("%d",stack[i]);	
}
