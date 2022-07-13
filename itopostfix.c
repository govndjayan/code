#include<stdio.h>
#include<ctype.h>

int top=-1;
char stack[30];

void push(char a)
{
	stack[++top]=a;
}

char pop()
{ 
    if(top==-1)
      return -1;
    else
	  return stack[top--];
}

int priority(char a)
{
	if(a=='(')
	  return 0;
	else if(a=='+'||a=='-')
	  return 1;
	else if(a=='*'||a=='/')
	  return 2;
	else if(a=='^')
	  return 3;
	return 0;
}

int main()
{
	char exp[20];
	char *e,x;
	printf("Enter the expression:");
	scanf("%s",exp);
	e=exp;
	
	while(*e!='\0')
	{
		if(isalnum(*e))
		  printf("%c",*e);
		else if(*e=='(')
		  push(*e);
		else if(*e==')')
		  {
		  	while((x=pop())!='(')
		  	  printf("%c",x);
		  }
		else
		{
			while(priority(stack[top])>=priority(*e))
			    printf("%c",pop());
			push(*e);
		}
		e++;
	}
	
	while(top!=-1)
	{
		printf("%c",pop());
	}
	
	return 0;
}
