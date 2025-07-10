#include<bits/stdc++.h>
using namespace std;
// 192.168.1.38
struct Node 
{
    int data ;
    Node* left = NULL;
    Node* right = NULL;
    Node(int value)
    {
        data = value;
        left  = NULL;
        right  = NULL;

    }
}
;
/*void level_trigger(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int height = 1;
    while(!q.empty())
    {
        if(q.front()!=NULL){
        cout<<q.front()->data<<" ";
        if(q.front()->left!=NULL)
        {
            q.push(q.front()->left);
        }
        if(q.front()->right!=NULL)
        {
            q.push(q.front()->right);
        }
        q.pop();
        }
        else
        {
            q.pop();
            if(!q.empty())
            {
                height++;
                
                q.push(NULL);
            }
        }
    }
    
    cout<<endl<<height<<endl;
}*/

int height(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
   int lheight = height(root->left);
   int rhight = height(root->right);

    
    return max(lheight , rhight) +1 ; 
    
}

int leftheight(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return height(root->left)+1;
}
int rightheight(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return height(root->right)+1;
}
int diameter(Node * root)
{
     
if(root==NULL)
{
    return 0;
}
   

int m = height(root->left);                              // Time complexity = o(n^2);
int n  = height(root->right);
int current = m+n+1;
// cout<<current<<endl;
int leftdiameter = diameter(root->left);
int righttdiameter = diameter(root->right);
  
return max(current , max(leftdiameter ,righttdiameter));

}
//  an optimised way

int calcdiameter(Node * root , int *height)
{
    if(root ==NULL)
    {
        *height  = 0;
        return  0;                                             // Time complecity = o(n);
    }
    int lh = 0 , rh = 0;

    int ldiameter = calcdiameter(root->left  , &lh);
    int rdiameter = calcdiameter(root->right  , &rh);

    int current = lh+rh+1;
    *height  = max(lh , rh)+1;
    return max(current , max(ldiameter , rdiameter));
}



int main()
{
 Node* root = new Node( 1);
 root->left = new Node( 2);
 root->left->left = new Node( 3);
 root->left->right = new Node( 4);
 root->left->right->right = new Node( 7);
 root->left->left->left = new Node(5);
 root->left->left->right = new Node(6);
  root->left->left->left->left = new Node(8);
cout<<height( root->left->left->right)<<endl;
  root->right = new Node(9);
  int height  = 0;
cout<<diameter(root)<<endl;
  cout<<calcdiameter(root , &height);




    
}