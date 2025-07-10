#include<bits/stdc++.h>
using namespace std;

struct Node
{

int data ;
Node* left;
Node* right;

Node(int value)
{
    data = value;
    left = NULL;
    right = NULL;
}
};

void printlevelorder(Node* root , int n)
{
    if(root==NULL)
    {
        return;
    }
    queue<Node*> q;
    int level = 1;
    int sum =0;
    int noofnodes = 0;
    int noofnodesatk = 0;

    
    q.push(root);
  q.push(NULL);
  noofnodes++;
  while(!q.empty()){

    if(q.front()!=NULL){

    cout<<q.front()->data<<" ";
    
    if(level == n)
    
    {
sum = sum +q.front()->data;
noofnodesatk++;

    }
    

    if(q.front()->left!=NULL){
    
    q.push(q.front()->left);
    noofnodes++;
    }
    if(q.front()->right!=NULL){
    q.push(q.front()->right);
    noofnodes++;
    }
    q.pop();

    }
else{

    q.pop();
    if(!q.empty())
    {
        level++;
        q.push(NULL);
    }
}


  }
  
   
     cout<<sum<<endl;
     cout<<noofnodes<<endl;
     cout<<noofnodesatk<<endl;
}


int main()
{
    int k;
    cin>>k;
    
    Node *root  =  new Node(1);
    root->left  = new Node(2);
    root->right  = new Node(3);
    root->left->left  = new Node(4);
    root->left->right  = new Node(5);
    root->right->left  = new Node(6);
    root->right->right  = new Node(7);
    printlevelorder(root , k);
}
