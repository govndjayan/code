#include <stdio.h>
#define size 5
int items[size], front, rear;

// Insert an element at front of the deque
void insertfront(int key) 
{   
// If queue is initially empty,set front=rear=0; start of deque 
if (front == -1) 
 { 
   front = 0; 
   rear = 0; 
 } 
else if (front == 0) 		      // front is first position of queue 
front = size - 1 ; 
else // decrement front 1 position 
front = front-1; 
  
items[front] = key ; 			// insert current element into Deque
} 
// insert element at the rear end of deque 
void insertrear(int key) 
{
    //  If queue is initially empty,set front=rear=0; start of deque 
if (front == -1)
 { 
front = 0; 
rear = 0; 
    } 
else if (rear == size-1) 			   // rear is at last position of queue
rear = 0; 
else						    // increment rear by 1 position 
rear = rear+1; 
  
items[rear] = key ; 		// insert current element into Deque
} 
  
// Delete element at front of Deque 
void deletefront() 
{ 
    // Deque has only one element 
 if (front == rear) 
    { 
front = -1; 
rear = -1; 
    } 
else
   {
   if (front == size -1) 
   front = 0; 
  
   else // remove current front value from Deque;increment front by 1
   front = front+1; 
   } 
} 
  
// Delete element at rear end of Deque 
void deleterear() 
{ 
  // Deque has only one element 
if (front == rear) 
    { 
front = -1; 
rear = -1; 
    } 
else if (rear == 0) 
rear = size-1; 
else
rear = rear-1; 
} 

void display() {
  if (rear == -1)
    printf("\nQueue is Empty!!!");
  else {
    int i;
    printf("\nQueue elements are:\n");
    for (i = front; i <= rear; i++)
      printf("%d  ", items[i]);
  }
  printf("\n");
}
int main() 
{
  //enQueue 5 elements
  insertfront(1);
  insertfront(2);
  insertfront(3);
  insertfront(4);
  insertfront(5);

  display();

  //deQueue removes element entered first i.e. 1
  deletefront();

  //Now we have just 4 elements
  display();
  //Inserting from rear
  insertrear(7);
  display();
  //Deleting from rear
  deleterear();
  display();

  return 0;
}
