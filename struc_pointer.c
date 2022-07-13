#include<stdio.h>
#include<string.h>
int i,c=0;
struct student
{
	char name[50];
	int prn;
	float perc;
};

void create(struct student *a)
{
	int n;
	printf("ENTER THE NO.OF ENTRIES:\n");
	scanf("%d",&n);
	printf("ENTER NAME, PRN AND PERCENTAGE:\n");
	for(i=0;i<n;i++)
	{
		scanf("%s\n%d\n%f",a->name,&a->prn,&a->perc);
		a++;
		c++;
	}
}
void insert(struct student *a)
{
	int n;
	printf("ENTER THE NO.OF ENTRIES TO BE INSERTED:\n");
	scanf("%d",&n);
	printf("ENTER NAME, PRN AND PERCENTAGE:\n");
	for(i=0;i<n;i++)
	{
		scanf("%s\n%d\n%f",a[c].name,&a[c].prn,&a[c].perc);
		c++;
	}
}
void modify(struct student *a)
{
	char name[50];
	int prn;
	float perc;
	printf("ENTER THE NAME OF THE STUDENT WHOSE DETAILS ARE TO BE MODIFIED:\n");
	scanf("%s",name);
	fflush(stdin);
	printf("ENTER NEW PRN AND PERCENTAGE:\n");
	scanf("%d\n%f",&prn,&perc);
	for(i=0;i<c;i++)
	{
		if(strcmp(name,a->name)==0)
		{
			a->prn=prn;
			a->perc=perc;
		}
		a++;
	}
}
void del(struct student *a)
{
	char name[50];
	printf("ENTER THE NAME TO BE DELETED:\n");
	scanf("%s",name);
	fflush(stdin);
	for(i=0;i<c;i++)
	{
		if(strcmp(name,(a+i)->name)!=0)
		{
			while(i<c)
			{
				a[i]=a[i+1];
				i++;
			}
		}
	}
	c--;
}
void display(struct student *a)
{
	printf("-----------STUDENT DATABASE------------\n");
	for(i=0;i<c;i++)
	{
		printf("%s\t%d\t%f\n",a->name,a->prn,a->perc);
		a++;
	}
	
}
main()
{
	struct student st[50];
	int ch,n;
	do
	{
		printf("----------MAIN MENU----------\n");
		printf("1. CREATE A STUDENT DATABASE\n");
		printf("2. MODIFY THE STUDENT DATABASE\n");
		printf("3. DELETE FROM STUDENT DATABASE\n");
		printf("3. DELETE FROM STUDENT DATABASE\n");
		printf("4. INSERT NEW FIELDS\n");
		printf("5. DISPLAY THE STUDENT DATABASE\n");
		printf("ENTER YOUR CHOICE:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 : create(st);
			         break;
			case 2 : modify(st);
			         break;
			case 3 : del(st);
			         break;
			case 4 : insert(st);
			         break;
			case 5 : display(st);
			         break;
			default:printf("INVALID OPTION\n");
		}
		printf("DO U WISH TO CONTINUE:(yes-1/no-2)\n");
		scanf("%d",&n);
	}
	while(n==1);
}

