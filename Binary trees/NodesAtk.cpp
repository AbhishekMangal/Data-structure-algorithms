#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left ;
    Node* right;
    Node(int value)
    {
data = value;
left = NULL;
right = NULL;
    }
};


void Node_Subtree( Node* a , int k )
{

if(a==NULL || k<0)
{
    return  ;
}
if(k==0 )
{
    cout<<a->data<<" ";
    return ;
}

Node_Subtree(a->left , k-1) ;
Node_Subtree(a->right , k-1) ;
}
bool check = false;



int ancestor(Node* root ,Node* a , int k )
{
 
 

    if(root==NULL || k<0)
    {
        return  -1;
    }


    if(root== a)
    {
        
     Node_Subtree(root , k);
        return  0;
    }
     

  
 int dl = ancestor(root->left , a, k );
 if(dl!=-1){
 if(dl+1 == k)
 {
    cout<<root->data<<" ";
 }
 else
  {
   Node_Subtree(root->right , k-dl-2 ); 
  }
 return dl+1;
 }
 int dr =  ancestor(root->right , a, k-1 );
  
  if(dr!=-1)
 if(dr+1 == k)
 {
    cout<<root->data<<" ";
 }
 else
  {
   Node_Subtree(root->left , k-dr-2 ); 
  }
     return dr+1;
    
 return -1;
 
 
 
  
}

int main ()
{
    Node* root = new Node(1);
    root->left = new Node(5);
    root->left->left = new Node(6);
    root->left->left->right = new Node(7);
    root->left->left->right->left = new Node(8);
    root->left->left->right->right = new Node(9);
    root->right = new Node(2);
    root->right->left = new Node(3);
    root->right->right = new Node(4);
    ancestor(root , root->left->left , 2 );
 
}
                  