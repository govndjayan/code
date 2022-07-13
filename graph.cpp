#include<iostream>
#include<process.h>

using namespace std;

class ListGraph;
class Stack;

class GraphNode
{
   int vertex;
   GraphNode *next;

   public:
     GraphNode(int v=0,GraphNode *n=NULL)
      {
          vertex=v;
          next=n;
      }
    friend class ListGraph;
};

class ListGraph
{
    int n;          //No of vertices
    GraphNode **list;        //double pointer because 'array' of graphnode pointers
    
    public:
       ListGraph(int no=0)
         {
            n=no;
            list = new GraphNode*[n];
            for(int j=0;j<n;j++)
                 list[j]=NULL;
         }      
        void create();
        void display();
        void DFS(int);
};

class SNode
{
   GraphNode *data;    //holds address of graph node
   SNode *link;    //self reference
   public:
     SNode()
       {
           data=NULL;
           link=NULL;
       }
     SNode(GraphNode *d, SNode* l=NULL)
       {
           data=d;
           link=l;
       } 
     friend class Stack;
};


//linked stack instead of static stack
class Stack
{
    SNode *top;   
    public:
      Stack()
        {
            top=NULL;
        }
      bool isEmpty();
      void push(GraphNode*);
      GraphNode* pop();
      void display();
};

void ListGraph::create()
{
    char ans;
    GraphNode *temp=NULL;
    for(int i=0;i<n;i++)
      {
          for(int j=0;j<n;j++)
            {
                // if(i!=j)
                //   {
                    cout<<"Is there edge between "<<i<<" and "<<j<<"?(y or n)";
                    cin>>ans;
                    if(ans=='y')
                    {
                        GraphNode *newnode = new GraphNode(j);
                        if(list[i]==NULL)    //no outgoing vertex from i vertex
                            {
                                temp=newnode;
                                list[i]=newnode;   
                            }
                        else            //temp will point to the last node in the list[i]
                            {
                                temp->next=newnode;
                                temp=newnode;
                            }
                    }
                // }
            }
      }
}

void ListGraph::display()
{
    GraphNode *temp;
    for(int i=0;i<n;i++)
      {
          cout<<"\nVertex "<<i<<"->";
          temp=list[i];
          while(temp!=NULL)
            {
                cout<<"\tV"<<temp->vertex<<"->";
                temp=temp->next;
            }
           cout<<"\tNULL";
      }
}

void ListGraph::DFS(int startVertex)
{
    bool *visited = new bool[n];
    for(int i=0;i<n;i++)
        visited[i]=false;
    
    Stack S;

    visited[startVertex]=true;
    cout<<"V"<<startVertex<<"->";
    S.push(list[startVertex]);

    GraphNode *temp=list[startVertex];

    int v = startVertex;

    while(temp!=NULL)
     {
         v=(temp->vertex);
         if(!visited[v])
          {
              visited[v] = true;
              S.push(list[v]);
              cout<<"\tV"<<v<<"->";
              temp= list[v];
              //temp=temp->next;
          }
          else
           {
               temp=temp->next;
           }
     }

     while(!S.isEmpty())
      {
          temp = S.pop();
           while(temp!=NULL)
            {
                v=(temp->vertex);
                if(!visited[v])
                {
                    visited[v] = true;
                    S.push(list[v]);
                    cout<<"\tV"<<v<<"->";
                    temp=list[v];
                    //temp=list[v-1];
                }
                else
                {
                    temp=temp->next;
                }
            }

      }
}

bool Stack::isEmpty()    //returns true if stack is empty
{
    return top==NULL;
}

GraphNode* Stack::pop()
{
    if(isEmpty())
      {
          cout<<"\nStack Underflow!";
          exit(-1);
      }
    SNode *temp=top;
    GraphNode *d=temp->data;    //address of Graph node at top of stack
    top=top->link;   //move top one node ahead
    delete temp;
    return d;
}

//each new node is added before the current node, and top points to the new node
void Stack::push(GraphNode* G)    
{
   SNode *newSNode=new SNode(G,top); 
   top=newSNode;
}

int main()
{
    int n;
    cout<<"Enter no of vertex in the Graph: ";
    cin>>n;
    ListGraph LG(n);
    LG.create();
    cout<<"\nAdjacency list for entered graph : ";
    LG.display();
    cout<<"\n\nDFS Sequence : ";
    LG.DFS(0);
    cout<<"\b\b  ";
}
