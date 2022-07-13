#include<iostream>
#include<stdlib.h>
using namespace std;

class Node {
	public:
		int data;
		Node *next;
		
};

class List:public Node {
		Node *listptr,*temp,*temp2,*listptr1,*listptr2;
	public:
		List() {
			listptr = NULL;
			temp = NULL;
			temp2 = NULL;
			listptr1 = NULL;
			listptr2 = NULL;
		}

		void create();
		void insert_start();
		void insert_end();
		void insert_pos();
		void delete_start();
		void delete_end();
		void delete_pos();
		void reverse();
        void concat();
        void display();
};

void List::create()
{
	int n,i,num;
	cout<<"\nEnter the number of nodes :";
	cin>>n;
	for(i=0; i<n; i++) {
		Node *newnode = new Node;  
		cout<<"Enter the data : ";
		cin>>num;
		newnode->data=num;    
		newnode->next=NULL; 
		if(listptr==NULL) { 
			listptr=temp=newnode;
			newnode->next=listptr;

		} else {
			temp->next=newnode;
			newnode->next=listptr;
			temp=temp->next;
		}
		
	}
}
void List::insert_start() {
	
	Node *newnode = new Node;
	if(newnode==NULL){
		cout<<"Unable to allocate memory";
	}else{	
	int num;
	cout<<"\nEnter value to be inserted:";
	cin>>num;
	while(temp->next!=listptr)
	     temp=temp->next;
    newnode->data=num;
    newnode->next=listptr;
    listptr=newnode;
    temp->next=newnode;
    }
}
void List::insert_end() {
	
	int num;
	Node *newnode = new Node;
	temp = listptr;

	while(temp->next!=listptr) {
		temp = temp->next;  
	}
	cout<<"Enter the value to be inserted: ";
	cin>>num;

	temp->next = newnode;
    newnode->data = num;
	newnode->next = listptr;
}
void List::insert_pos() {
	
	int i=1,num,n=1;
	temp = listptr;
	cout<<"Enter the position to insert the node:";
	cin>>n;
	while(i!=n-1) {
		temp = temp->next;  
		i++;
	}
	cout<<"Enter the value to be inserted: ";
	cin>>num;
	Node *newnode= new Node;

	newnode->next = temp->next;
	temp->next = newnode;
	newnode->data = num;
}

void List::delete_start() {
	
	Node *d;
	if(listptr==NULL){
		cout<<"List is empty"<<endl;
	}
	else{
	d = listptr;
	temp = listptr;
	while(d->next!=listptr){
		d = d->next;
	}  
	d->next = temp->next;      
	listptr = d->next;
	delete temp;       
    }
}

void List::delete_end(){
Node *d;
if(listptr==NULL)
{
	cout<<"THe list is empty";
}
else
{
	d=listptr;
	temp=listptr;
	while(d->next!=listptr)
	{
		temp=d;
		d=d->next;
	}
	temp->next= listptr;
	delete(d);
	
}
	
}
void List::delete_pos() {
	
	int i,n=1;
	Node *q;
	temp = listptr;
	cout<<"\nEnter position of node you want to delete : ";
	cin>>n;
	for(i=1;i<n-1; i++) {
		temp = temp->next ;
	}
	 q = temp->next;        

	temp->next= q->next;  
	delete q;
}

void List::reverse() {
	
	Node *prev,*curr;
	if(listptr==NULL){
		cout<<"Empty List\n";
		return;
	}
	else{
		temp = listptr;
		prev = listptr;
		curr = listptr->next;
		listptr = listptr->next;
		while(listptr!=temp){
			listptr = listptr->next;
			curr->next = prev;
			prev = curr;
			curr = listptr;
		}
		curr->next = prev;
		listptr = prev;
	}
}

void List::concat()
{
	int n,m,i,x;
	cout<<"\nEnter the number of nodes of first list:";
	cin>>n;
	for(i=0; i<n; i++) {
		Node *newnode = new Node;  
		cout<<"Enter the data : ";
		cin>>x;
		newnode->data=x;   
		newnode->next=NULL; 

		if(listptr1==NULL) { 
			listptr1=newnode;
			temp=newnode;
			newnode->next=listptr1;

		} else {
			temp->next=newnode;
			newnode->next=listptr1;
			temp=temp->next;
		}
	}
	cout<<"\nEnter the number of nodes of second list:";
	cin>>m;
	for(i=0; i<m; i++) {
		Node *newnode = new Node;  
		cout<<"Enter the data : ";
		cin>>x;
		newnode->data=x;    
		newnode->next=NULL; 

		if(listptr2==NULL) { 
			listptr2=newnode;
			temp=newnode;
			newnode->next=listptr2;

		} else {
			temp->next=newnode;
			newnode->next=listptr2;
			temp=temp->next;
		}
	}
	
	temp = listptr1;
	while(temp->next!=listptr1) {
		temp = temp->next;
	}
	temp->next = listptr2;
	temp2= listptr2;  
	cout<<"\n";
	while(temp2->next!=listptr2) {
	   temp2=temp2->next;	
    }
	temp2->next=listptr1;
	
	temp = listptr1;
	cout<<"\n";
	while(temp->next!=listptr1){
    	cout<<temp->data<<"->";
    	temp = temp->next;
	}
	cout<<temp->data<<"->";
	cout<<"HEAD";
    
}

void List::display()
{
	
	temp = listptr;  
	cout<<"\n";
    while(temp->next!=listptr){
    	cout<<temp->data<<"->";
    	temp = temp->next;
	}
	cout<<temp->data<<"->";
	cout<<"HEAD";
}

int main()
{
	int ans=1,choice;
	List l;
	cout<<"\nTHE CIRCULAR LINKED LIST OPERATIONS\n";
	cout<<"\n1.Create a list\n2.Insert start\n3.Insert end\n4.Insert at position";
	cout<<"\n5.Delete start\n6.Delete end\n7.Delete from position";
	cout<<"\n8.Reverse\n9.Concatenate\n10.Display\n\n";
	while(ans==1)
	{
		cout<<"Enter choice:";
	    cin>>choice;
	    switch(choice)
	{
		case 1:
			l.create();
			l.display();
			break;
			
		case 2:
			l.insert_start();
			l.display();
			break;
			
		case 3:
			l.insert_end();
			l.display();
			break;
			
		case 4:
			l.insert_pos();
			l.display();
			break;
			
		case 5:
			l.delete_start();
			l.display();
			break;
			
		case 6:
			l.delete_end();
			l.display();
			break;
			
		case 7:
			l.delete_pos();
			l.display();
			break;
			
		case 8:
			l.reverse();
			l.display();
			break;
			
		case 9:
			l.concat();
			
			break;
			
		default:
			cout<<"Invalid!";
			break;
		
	}
	    cout<<"\n\nDo you want to continue(1/0): ";
		cin>>ans;
	}
	
}	
	
		    
	
