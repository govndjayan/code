#include<iostream>
using namespace std;

class node{
	node *left;
	int data;
	node *right;
	
	public:
		node(int n){
			data = n;
			left = right = NULL;
		}
		friend class bst;
};

class bst{
	public:
	    node *root;
		bst(){
			root = NULL;
	    }
	    void create();
	    void insert();
	    node* search(int value);
	    void remove(int n);
	    bool isEmpty();
	    void preorder(node *root);
	    void inorder(node *root);
	    void postorder(node *root);
};

void bst::create()
{
	node *newnode, *temp ; 
	int n;
    char ans ;
	do{
	    cout<<"\nEnter the element:";
		cin>>n;
        newnode=new node(n);
		if (root == NULL)
			root = newnode ;
		else
		{
		   temp = root; 
		   while (1)
			{ if (n<temp->data)
					if (temp->left==NULL)
						{temp->left=newnode; break;}
				    else
						temp=temp->left;
				else
						if(temp->right==NULL)
							{temp->right=newnode;break;}
						else
							temp=temp->right;
			}
		}
         cout<<"Any more numbers?(y/n)";
		 cin>>ans;	
		}
		while(ans=='y'||ans=='Y');
}

void bst::insert()
{
	node *newnode,*temp;
	int n;
	cout<<"Enter value to insert:";
	cin>>n;
	newnode=new node(n);
	
	if(root==NULL)
	   root=newnode;
	else{
		temp=root;
		while(1){
			if(n<temp->data){
				if(temp->left==NULL)
				   {temp->left=newnode;break;}
				else
				   temp=temp->left;  
			}
			else{
				if(temp->right==NULL)
				   {temp->right=newnode;break;}
				else
				   temp=temp->right; 
			}
		}
	}
}

node* bst::search(int value)
{
    node *temp = root;
    while(temp!=NULL)
    {
    	if(value==temp->data)
    	{
    		return temp;
		}
		else if(value<temp->data)
		{
			temp=temp->left;
		}
		else
		{
			temp = temp->right;
		}
	}
	return NULL;
}

void bst::remove(int n)
{
	node *temp,*parent=NULL,*father,*r,*son;
	temp=root;
	while((temp->data!=n)&&(temp!=NULL))
	{
		if(n<temp->data){
			parent=temp;
			temp=temp->left;
		}
		else{
			parent=temp;
			temp=temp->right;
		}
	}
	if(temp==NULL){
		cout<<"Number not found!";
		return;
	}
	if(temp->left==NULL)
	   r=temp->right;
	else
	   if(temp->right==NULL)
	      r=temp->left;
	else{
		father=temp;
		r=temp->right;
		son=r->left;
		while(son!=NULL){
			father=r; 
			r=son;
			son=r->left;
		}
		if(father!=temp){
			father->left=r->right;
			r->right=temp->right;
		}
		r->left=temp->left;
	}
	if(parent==NULL)
	   root=r;
	else
	   if(temp==parent->left)
	      parent->left=r;
	   else
	      parent->right=r;
    delete temp;
}

bool bst::isEmpty()
{
	if(root ==NULL)
	  return true;
	return false;
}

void bst::preorder(node *root)//data,left,right
{
    node *temp;
    temp=root;
    
    if(temp!=NULL){
    	cout<<temp->data<<" ";
    	preorder(temp->left);
    	preorder(temp->right);
	}
}
       
void bst::inorder(node *root)//left,data,right
{
    node *temp;
    temp=root;
    
    if(temp!=NULL){
    	inorder(temp->left);
    	cout<<temp->data<<" ";
    	inorder(temp->right);
	}
} 

void bst::postorder(node *root)//left,right,data
{
    node *temp;
    temp=root;
    
    if(temp!=NULL){
    	postorder(temp->left);
    	postorder(temp->right);
    	cout<<temp->data<<" ";
	}
}      
		
int main(){
	bst t;
	int ans=1,ch,s,d,ch2;
	node *p;
	cout<<"\n\nBINARY SEARCH TREE\n\n";
	cout<<"1.Create\n2.Insert\n3.Search\n4.Delete\n5.Display\n\n";
	while(ans==1){
		cout<<"\nEnter choice:";
		cin>>ch;
		switch(ch){
			case 1:
				t.create();
				break;
				
			case 2:
				t.insert();
				break;
				
			case 3:
				cout<<"\nEnter element to search:";
				cin>>s;
				p=t.search(s);
				if(p!=NULL){
					cout<<"Element found!";
				}
				else
				    cout<<"Element Not Found!";
				break;
				
			case 4:
				cout<<"\nEnter element to delete:";
				cin>>d;
				t.remove(d);
				cout<<"\nNumber deleted succcessfully";
				break;
				
			case 5:
				if(t.isEmpty()==true){
					cout<<"\n--Empty Tree--";
					break;
				}
				cout<<"\nTraversals:\n";
				cout<<"1.Preorder\n2.Inorder\n3.Postorder\n";
				cout<<"Enter choice:";
				cin>>ch2;
				if(ch2==1)
				   t.preorder(t.root);
				else if(ch2==2)
				   t.inorder(t.root);
				else if(ch2==3)
				   t.postorder(t.root);
				break;
				
			default:
				cout<<"Invalid Option";
				break;
		}
		cout<<"\n\nDo you want to continue(1/0): ";
		cin>>ans;
	}
}
			
				
		 


