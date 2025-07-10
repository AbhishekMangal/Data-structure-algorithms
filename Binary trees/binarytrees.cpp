#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;

    }
}
;
void preorder(struct Node* ptr)
{
    if(ptr==NULL)
    { 
        
        return;
    }
   /*else if(ptr->right!=NULL)
    {
        
    }*/
    cout<<ptr->data<<" ";
    preorder(ptr->left);
  
    preorder(ptr->right);
    ptr->right =ptr;
 
}
void inorder(Node* ptr)
{
    if(ptr==NULL)
    {
        return;
    }
    (ptr->left);
    cout<<ptr->data<<" ";
    (ptr->right);

}
void postorder(Node* ptr)
{
    if(ptr==NULL)
    {
        return;
    }
    postorder(ptr->left);
    postorder(ptr->right);
    cout<<ptr->data<<" ";
}


int main()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
     root->left->left = new Node(4);
     root->left->right = new Node(5);  
     root->right->left = new Node(6);
     root->right->right = new Node(7);
    
     //preorder(root);
    
    // (root);
    postorder(root);
}