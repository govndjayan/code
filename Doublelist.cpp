#include<iostream>
#include<stdlib.h>
using namespace std;

class Node{
	public:
		int data;
		Node *prev,*next;
	
};
class List{
	Node *listptr,*temp,*listptr1,*listptr2,*temp2;
	public:
		List(){
			listptr=NULL;
			temp=NULL;
			listptr1=NULL;
			listptr2=NULL;
			temp2=NULL;
		}
		void create();
		void display();
		void insert_start();
		void insert_end();
		void insert_pos();
		void delete_start();
		void delete_end();
		void delete_pos();
		void reverse();
		void concat();
};

void List::create(){
	int i,n,num;
	cout<<"Enter number of nodes:";
	cin>>n;
	for(int i=0;i<n;i++){
		cout<<"Enter the data:";
		cin>>num;
		Node *newnode = new Node();
		newnode->data = num;
		newnode->next = NULL;
		newnode->prev = NULL;
		if(listptr==NULL){
			listptr=temp=newnode;
		}
		else{
			temp->next=newnode;
			newnode->prev=temp;
			temp=temp->next;
		}
	}
}

void List::display(){
	temp = listptr;  
	cout<<"\n";
	if(listptr==NULL){
		cout<<"List is empty";
	}else{
	cout<<"The list elements are\n";
	while(temp!=NULL) {
		
		cout<<temp->data<<"<->";
		temp = temp->next;  
	}
	cout<<"NULL";}
}

void List::insert_start(){
	Node *newnode = new Node;
	if(newnode==NULL){
		cout<<"Unable to allocate memory";
	}else{	
	int num;
	cout<<"\nEnter value to be inserted:";
	cin>>num;

	newnode->data = num;  
	newnode->next=listptr;      
	listptr->prev = newnode;
	listptr = newnode;       
    }
}

void List::insert_end(){
	int num;
	Node *newnode = new Node;
	temp = listptr;

	while(temp->next!=NULL) {
		temp = temp->next;  
	}
	cout<<"Enter the value to be inserted: ";
	cin>>num;

	temp->next = newnode;
    newnode->data = num;
	newnode->next = NULL;
	newnode->prev = temp;
}

void List::insert_pos()
{
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
    newnode->data = num;
	newnode->next = temp->next;
	(temp->next)->prev = newnode;
	temp->next = newnode;
	newnode->prev = temp;
}

void List::delete_start()
{
   if(listptr==NULL){
		cout<<"List is empty"<<endl;
	}
	else{
	temp = listptr;        
	listptr = temp->next;  
	delete temp;          
    } 	
}

void List::delete_end(){
	
	Node *d; 
	if(listptr==NULL){
		cout<<"List is empty"<<endl;
	}
	else{
	    d = listptr;
	    temp = listptr;
	    while(d->next!=NULL){
	    	temp = d;
	    	d = d->next;
		}
		temp->next = NULL;
		delete(d);
   }
}

void List::delete_pos(){
	int i,n=1;
	Node *q;
	temp = listptr;
	cout<<"\nEnter position of node you want to delete : ";
	cin>>n;
	for(i=1;i<n-1; i++) {
		temp = temp->next;
	}
	q = temp->next;        
    temp->next = q->next;
	q->next->prev = q->prev;  
	delete q;
}

void List::reverse()
{
	Node *p1 = listptr;
	Node *p2 = p1->next;
	p1->next = NULL;
	p1->prev = p2;
	while(p2!=NULL){
		p2->prev = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p2->prev;
	}
	listptr = p1;
}

void List::concat()
{
	int n,m,i,x;
	cout<<"\nEnter the number of nodes of first list:";
	cin>>n;
	for(i=0; i<n; i++) {
	cout<<"Enter the data:";
		cin>>x;
		Node *newnode = new Node();
		newnode->data = x;
		newnode->next = NULL;
		newnode->prev = NULL;
		if(listptr1==NULL){
			listptr1=temp=newnode;
		}
		else{
			temp->next=newnode;
			newnode->prev=temp;
			temp=temp->next;
		}	
	}
	cout<<"\nEnter the number of nodes of second list:";
	cin>>m;
	for(i=0; i<m; i++) {
		cout<<"Enter the data:";
		cin>>x;
		Node *newnode = new Node();
		newnode->data = x;
		newnode->next = NULL;
		newnode->prev = NULL;
		if(listptr2==NULL){
			listptr2=temp=newnode;
		}
		else{
			temp->next=newnode;
			newnode->prev=temp;
			temp=temp->next;
		}
	}
	
	temp = listptr1;
	while(temp->next!=NULL) {
		temp = temp->next;
	}
	temp->next = listptr2;
	
	temp = listptr1;
	cout<<"\n";
	while(temp!=NULL){
		cout<<temp->data<<"<->";
		temp=temp->next;
	}
	cout<<"NULL";
    
}

int main() {
	int ans=1,choice;
	List l;
	cout<<"\nTHE DOUBLE LINKED LIST OPERATIONS\n";
	cout<<"1.Create List\n2.Insert node at start position\n3.Insert node at end\n";
	cout<<"4.Insert node at a position\n5.Delete node from start\n6.Delete node from end\n";
	cout<<"7.Delete node from position\n8.Reverse List\n9.Concatenate\n10.Display\n";
	while(ans==1) {
	
		cout<<"\nEnter choice: ";
		cin>>choice;

		switch(choice) {
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
			         
			case 10:
				l.display();
				break;
				
			default:
				cout<<"Invalid choice";
				break;

		}
		cout<<"\n\nDo you want to continue(1/0): ";
		cin>>ans;
	
	}
}
