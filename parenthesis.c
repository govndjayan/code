#include<stdio.h>
#include<string.h>

int top=-1;
char stack[20];

void push(char a)
{
	stack[++top]=a;
}

char pop()
{
	return stack[top--];
}

int main()
{
	char exp[30],t;
	int i,valid=1;
	printf("Enter an expression:");
	scanf("%s",exp);
	for(i=0;i<strlen(exp);i++)
	{
		if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
		{
			push(exp[i]);
		}
		else if(exp[i]==')'||exp[i]=='}'||exp[i]==']')
		{
			if(top==-1)
			{
				valid=0;
			}
			else
			{
			
				t=pop();
				if(exp[i]==')'&&(t=='['||t=='{')){
					valid=0;
				}
				if(exp[i]=='}'&&(t=='('||t=='[')){
					valid=0;
				}
				if(exp[i]==']'&&(t=='('||t=='{')){
					valid=0;
				}
				
		    }
		}
		else
			{
				valid=1;
			}
			
		}
		
		if(top>=0)
		{
			valid=0;
		}
		
		  if(valid==1)
		{
			printf("Valid expression");
		}
		 else{
		
		printf("Invalid expression");
	    }
	return 0;
}
