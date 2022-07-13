#include<stdio.h>
#include <math.h>
#include<string.h>
int j,rem;
int conv_of_dec(int n,int b)
{
	char arr[100],i=0;
	while(n!=0)
	{
		rem=n%b;
		if(rem<10)
		arr[i++]=48+rem;
		else
		arr[i++]=55+rem;
		n=n/b;
	
		
	}
	for(j=i;j>=0;j--)
		printf("%c",arr[j]);

}
int other_conv(int n,int b,int c)
{ int i=0,dec=0;
	while(n!=0)
	 {
		rem=n%10;		
        dec=dec+rem * pow(c, i);
        n=n/10;
        i++;
	 }
    if(b==10)
    printf("%d",dec);
    else
    {
     char arr[100];
	 while(dec!=0)
	  {
		rem=dec%b;
		if(rem<10)
		arr[i++]=48+rem;
		else
		arr[i++]=55+rem;
		dec=dec/b;
	  }
	  for(j=i;j>=0;j--)
	  printf("%c",arr[j]);
	}
    
}
void conv_of_hex(char hex[],int l,int b)
{
	int val=0,dec=0,i=0;
	l--;
	for(i=0; hex[i]!='\0'; i++)
    {
        if(hex[i]>='0' && hex[i]<='9')
        {
            val = hex[i] - 48;
        }
        else if(hex[i]>='a' && hex[i]<='f')
        {
            val = hex[i] - 97 + 10;
        }
        else if(hex[i]>='A' && hex[i]<='F')
        {
            val = hex[i] - 65 + 10;
        }

        dec=dec+ val * pow(16,l);
        l--;
    }
    if(b==10)
    printf("\n%d",dec);
    else
    {
     char arr[100];
	 while(dec!=0)
	  {
		rem=dec%b;
		if(rem<10)
		arr[i++]=48+rem;
		else
		arr[i++]=55+rem;
		dec=dec/b;
	  }
	  for(j=i;j>=0;j--)
	  printf("%c",arr[j]);
	}
}
int main()
{
int n,ch,c;char hex[17];
do
{

printf("\n\t**********MAINMENU**********");
printf("\n1.Decimal ");
printf("\n2.Binary");
printf("\n3.Octal");
printf("\n4.Hexadecimal");
printf("\nEnter your choice:");
scanf("%d",&ch);
switch(ch)
{
	case 1 : printf("\nEnter the number:");
             scanf("%d",&n);
             conv_of_dec(n,2); 
             printf("\n");
             conv_of_dec(n,8);
             printf("\n");
             conv_of_dec(n,16);
             break;
    case 2: printf("\nEnter the number:");
             scanf("%d",&n);
			 other_conv(n,10,2);
	        printf("\n");
	        other_conv(n,8,2);
	        printf("\n");
	        other_conv(n,16,2);
	        break;
	case 3: printf("\nEnter the number:");
             scanf("%d",&n);
			 other_conv(n,10,8);
	        printf("\n");
	        other_conv(n,2,8);
	        printf("\n");
	        other_conv(n,16,8);
	        break;
	case 4: printf("\nEnter the number:");
	        fflush(stdin);
            gets(hex);
            int l = strlen(hex);
            conv_of_hex(hex,l,10);
            printf("\n");
            conv_of_hex(hex,l,2);
            printf("\n");
            conv_of_hex(hex,l,8);  
			break;         
}
printf("\nDo you want to continue--yes(1) or no(2)");
scanf("%d",&c);
}
while(c==1);
}
