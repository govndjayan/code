#include<iostream>
#include<stdlib.h>
using namespace std;

class List
{
	class node
	{
		
		public:
			int data;
		    node *next;
			node(int n)
			{
				data=n;
				next=NULL;
			}
	}*Listptr,*Listptr2;
	
	public:
		void create();
	    void display();
	    void insert_start();
	    void insert_end();
	    void insert_intermediate();
	    void delete_start();
	    void delete_end();
	    void delete_inter();
        void reverse();
	    void concatenate();
};

void List::create()
{
	int i,n,num;
	node *temp;
	cout<<"Enter no.of nodes(a positive number):";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"Enter data to be written:";
		cin>>num;
		node *newnode= new node(num);
		if(Listptr==NULL)
		{
			Listptr=temp=newnode;
		}
		else
		{
			temp->next=newnode;
			temp=temp->next;
		}
	}
	display();
}

void List::display()
{
	node *temp=Listptr;
	if(Listptr==NULL)
	{
		cout<<"List is empty";
	}
	else
	{
		cout<<"\nList Elements\n";
		while(temp!=NULL)
		{
			cout<<temp->data<<">-";
			temp=temp->next;
		}
		cout<<"NULL"<<endl;
	}
}

void List::insert_start()
{
	int x;
	node *newnode = new node(x);
	if (newnode==NULL){
	   cout<<"Unable to allocate";
	}else{
	cout<<"Enter value to be inserted:";
	cin>>x;
	//cout<<Listptr->data;
	newnode->data = x;
	newnode->next = NULL;
	newnode->next=Listptr;
	Listptr=newnode;
	display();
}
}

void List::insert_end()
{
	int x;
	node *newnode = new node(x);
	if (newnode==NULL){
	   cout<<"Unable to allocate";
	}else{
	cout<<"Enter value to be inserted at the end:";
	cin>>x;
	node *temp= Listptr;
	while(temp!=NULL){
		temp= temp->next;
	}
	temp->next=newnode;
	newnode->data=x;
	newnode->next=NULL;
	display();
}
}

void List::insert_intermediate()
{
	int x,n=1;
	node *temp=Listptr;
	cout<<"Enter valid position to enter the data:";
	cin>>n;
	for(int i=1;i<n-1;i++){
		temp=temp->next;
		
	}
	cout<<"Enter the data to insert:";
	cin>>x;
	node *newnode= new node(x);
	newnode->next=temp->next;
	temp->next=newnode;
	newnode->data=x;
	display();
}

void List::delete_start()
{
	node *temp=Listptr;
	Listptr=temp->next;
	delete(temp);
	display();
}

void List::delete_end()
{
	node *q;
	node *temp=Listptr;
	while(temp->next->next!=NULL)
	{
		temp=temp->next;
	}
	q=temp->next;
	temp->next=NULL;
	delete(q);
	display();
}

void List::delete_inter()
{
	node *q;
	int n=1;
	node *temp=Listptr;
	cout<<"Enter node to be deleted:";
	cin>>n;
	for(int i=1;i<n-1;i++){
		temp=temp->next;
	}
	q=temp->next;
	temp->next=q->next;
	delete(q);
	display();
}

void List::reverse()
{
	node *prev,*curr;
	if(Listptr!=NULL)
	{
		prev=Listptr;
		curr=Listptr->next;
		Listptr=Listptr->next;
		
		prev->next=NULL;
		while(Listptr!=NULL){
			Listptr=Listptr->next;
			curr->next=prev;
			prev=curr;
			curr=Listptr;
		}
		Listptr=prev;
		
	}
}

void List::concatenate()
{
	int n,num,m,i,x;
	node *temp;
	cout<<"Enter no.of nodes(a positive number) in 1st list:";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"Enter data to be written:";
		cin>>num;
		node *newnode= new node(num);
		if(Listptr==NULL)
		{
			Listptr=temp=newnode;
		}
		else
		{
			temp->next=newnode;
			temp=temp->next;
		}
	}
	cout<<"Enter no.of nodes(a positive number) 2nd list:";
	cin>>m;
	for(i=0;i<m;i++)
	{
		cout<<"Enter data to be written:";
		cin>>num;
		node *newnode= new node(num);
		if(Listptr2==NULL)
		{
			Listptr2=temp=newnode;
		}
		else
		{
			temp->next=newnode;
			temp=temp->next;
		}
	}
	
	temp= Listptr;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=Listptr2;
	
	//displaying concatenated list
	temp=Listptr;
	cout<<"\n";
	/*cout<<"The new list\n";
		while(temp->next!=NULL){
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<"NULL";*/
	display();
    
}

int main()
{
    int y,s;
    List l1;
    cout<<"Given below are the options:\n";
    cout<<"1.Create\n2.Display\n3.Insert beginning\n4.Insert end\n5.Insert intermediate";
    cout<<"\n6.Delete beginning\n7.Delete end\n8.Delete intermediate\n9.Reverse\n10.Concatenate\n";
    	
    	do{
    		cout<<"Enter your choice:";
    	cin>>s;
    	switch(s)
    	{
    		case 1:
    			l1.create();
    			break;
    			
    		case 2:
    			l1.display();
    			break;
    			
    		case 3:
    			l1.insert_start();
    			break;
    			
    		case 4:
    			l1.insert_end();
    			break;
    			
    		case 5:
    			l1.insert_intermediate();
    			break;
    		
    		case 6:
    			l1.delete_start();
    			break;
    			
    		case 7:
    			l1.delete_end();
    			break;
    			
    		case 8:
    			l1.delete_inter();
    			break;
    			
    		case 9:
    			l1.reverse();
    			l1.display();
    			break;
    			
    		case 10:
    			l1.concatenate();
    			
    		default:
    			cout<<"Invalid";
    		
		}
		cout<<"\nDo you want to continue(1/0)?";
		cin>>y;
	}while(y!=0);
    
	return 0;
}
		
    	
		
    	
