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

bool getpath(Node* root  , int n1 , vector<int>&path)
{
   
   if(root==NULL)
   {
    return false;
   }
    path.push_back(root->data);
if(root->data == n1)
{
    return true;
}

    if(getpath(root->left , n1 , path) ||getpath(root->right , n1 , path))
    {
return true;
    }

       path.pop_back();
       return false;
    
    

}

int LCA(Node* root  , int n1 , int n2)
{
    vector<int> path1  ,path2;
    if(!getpath(root , n1 , path1) || !getpath(root , n2 ,path2))
    {
        return -1;
    }

    int pc= 0;
    for( pc = 0 ; pc<path1.size() && path2.size() ; pc++)
    {
        if(path1[pc]!=path2[pc])
        {
            
            break;
        }
    }
    return path1[pc-1];
}
// another ways
int height(Node* root , int n1);
Node* LCA2(Node* root , int n1 , int n2)
{   
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data  == n1 || root->data == n2)
    {
    
        return root;
        
    }
     
   
    Node* lefttree = LCA2(root->left  , n1 , n2);

    Node* righttree = LCA2(root->right  , n1 , n2);
 
    if(lefttree && righttree)

    {
        
      
       return root;
    }
    if(lefttree!=NULL)
    {
       
        return lefttree;
    }
    return righttree;
}

int height(Node* root, int n1 ){
    if(root==NULL)
    {
        return  0;
    }
    if(root->data == n1)
    {
        return 1;
    }

  int leftHeight=   height(root->left , n1 );

  if(leftHeight)
  {
    return leftHeight+1;
  }

  
   int rightHeight=  height(root->right , n1 );
   if( rightHeight ){
   return rightHeight+1;
   }
   
}



int main ()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    
    root->right->left->left = new Node(7);
    root->right->left->left->left = new Node(8);
    root->right->right->right = new Node(9);
    //cout<<LCA(root , 6 , 7 );
    

   cout<<height(LCA2(root , 5 , 7 ), 5) + height(LCA2(root , 5 , 7 ), 7)-1;
}