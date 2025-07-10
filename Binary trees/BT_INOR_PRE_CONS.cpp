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
int search(int inorder[] , int start , int end , int curr)
{
    for(int i =start; i<=end ; i++)
    {
        if(curr == inorder[i])
        {
            return i;
           
        }
    }
    return -1;
}




/*Node* buildtree(int pre[] , int inor[] , int start  ,int end)
{
    static int idx = 0;
    if(start>end)
    {
        return NULL;
    }


int current  = pre[idx];
idx++;
Node* node = new Node(current);
if(start == end)
{
    return node;
}
int pos =search(inor , start ,end , current);
node->left  = buildtree(pre , inor ,start ,  pos-1  );
node->right  = buildtree(pre , inor ,pos+1 ,  end  );
//return node;

}*/

Node* buildtree(int inor[] , int post[]  ,int start  , int end)
{
    static int idx  = 4;
    if(start>end)
    {
        return NULL;
    }
  int  current = post[idx];
  idx--;

  Node* node = new Node(current);
  if(start==end)
  {
    return node;
  }
  int pos = search(inor , start ,end ,current);
  
  node->right=  buildtree(inor ,post ,pos+1 , end);
  node->left = buildtree(inor , post , start , pos-1);
return node;



}

void inorderprint(Node* root)
{

    if(root==NULL)
    {
        return;
    } 

    inorderprint(root->left);
 
    inorderprint(root->right);
    cout<<root->data<<" ";      
}

int main ()
{
 
   int pre[] = {1,2,4,3,5};
   int inor[]= {4,2,1,5,3};
   int post[] = {4 , 2 , 5 , 3 , 1};
   
   Node* root = buildtree(inor , post , 0 , 4);
   inorderprint(root);



  
    
} 