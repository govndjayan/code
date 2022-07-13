#include<iostream>
#include<stdlib.h>

const int size = 5;
int deque[size];
int front=-1;
int rear=-1;

void insert_front(int num);
void insert_rear(int num);
int delete_front();
int delete_rear();
void display();
int isEmpty();
int isFull();
using namespace std;
void insert_front(int num)
{
        if(isFull())
        {
                cout<<"Queue Overflow\n";
                return;
        }
        if(front==-1)
        {
                front=0;
                rear=0;
        }
        else if(front==0)
                front=size-1;
        else
                front=front-1;
        deque[front]=num ;
}
 
void insert_rear(int num)
{
        if(isFull())
        {
                cout<<"Queue Overflow\n";
                return;
        }
        if(front==-1)  
        {
                front=0;
                rear=0;
        }
        else if(rear==size-1)  
                rear=0;
        else
                rear=rear+1;
        deque[rear]=num ;
}
 
int delete_front()
{
        int num;
        if(isEmpty())
        {
                cout<<"Queue Underflow\n";
                exit(1);
        }
        num=deque[front];
        if(front==rear) 
        {
                front=-1;
                rear=-1;
        }
        else
                if(front==size-1)
                    front=0;
                else
                    front=front+1;
        return num;
}
 
int delete_rear()
{
        int num;
        if( isEmpty() )
        {
                cout<<"Queue Underflow\n";
                exit(1);
        }
        num=deque[rear];
        if(front==rear)
        {
                front=-1;
                rear=-1;
        }
        else if(rear==0)
                rear=size-1;
        else
                rear=rear-1;
        return num;
}
int isFull()
{
        if ((front==0 && rear==size-1) || (front==rear+1))
                return 1;
        else
                return 0;
}

int isEmpty()
{
        if(front==-1)
                return 1;
        else
                return 0;
}
void display()
{
        int i;
        if(isEmpty())
        {
                cout<<"Queue is empty\n";
                return;
        }
        cout<<"Queue elements :\n";
        i=front;
        if(front<=rear)
        {
                while(i<=rear)
                    cout<<deque[i++]<<"\t";
        }
        else
        {
                while(i<=size-1)
                        cout<<deque[i++]<<"\t";
                i=0;
                while(i<=rear)
                        cout<<deque[i++]<<"\t";
        }
        cout<<endl;
}
int main()
{
        int choice,n;
        while(1)
        {       cout<<"-------------MENU--------------\n";
        	    cout<<"Enter your choice :\n";
                cout<<"1.Insert at the front end\n";
                cout<<"2.Insert at the rear end\n";
                cout<<"3.Delete from front end\n";
                cout<<"4.Delete from rear end\n";
                cout<<"5.Display\n";
                cout<<"6.Quit\n";
                cin>>choice;
 
                switch(choice)
                {
                case 1:
                        cout<<"Enter element to be inserted at front\n";
                        cin>>n;
                        insert_front(n);
                        break;
                case 2:
                        cout<<"Enter element to be inserted at rear\n";
                        cin>>n;
                        insert_rear(n);
                        break;
                case 3:
                        cout<<"Element deleted from front is:"<<delete_front();
                        cout<<endl;
                        break;
                case 4:
                        cout<<"Element deleted from rear end is:"<<delete_rear();
                        cout<<endl;
                        break;
                case 5:
                        display();
                        break;
                case 6:
                        exit(1);
                default:
                        cout<<"Invalid Choice\n";
                }
                cout<<"front = "<<front<<" rear = "<<rear<<"\n";
                cout<<endl;
                display();
                cout<<endl;
        }
}
