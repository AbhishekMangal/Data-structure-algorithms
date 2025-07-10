struct Node
{
 int data;
 int height ;
Node* left;
Node* right;
Node(int value)
{
data = value;
left = nullptr;
right = nullptr;
}
};
#include<bits/stdc++.h>
using namespace std;
const int N  =  1e5+8;
#define rep(i,a,n) for(int i =a ;i<n ; i++)
int find(int inorder[], int idx , int start , int end)
{
    for(int i = start; i<=end ; i++)
    {
        if(inorder[i] == idx)
        {
            return i;
        }
    }
    return -1;
}
Node* BUildTree(int inorder[] , int preorder[] , int start , int end)
{
    static int idx = 0;
    if(start>end)
    {
        return nullptr;
    }

    int curr = preorder[idx];
        Node* node = new Node(curr);
     
    idx++;
    int a= find(inorder, curr ,start , end );
    if(start == end)
    {
        return node;
    }
   {
    
        node->left = BUildTree(inorder , preorder , start , a-1);
   }
   {
        node->right = BUildTree(inorder ,preorder , a+1, end); 
   }
    

}
int heigh(Node* &root)
{
    if(root == nullptr)
    {
        return 0;
    }
    root->height = max(heigh(root->left) , heigh(root->right))+1;
}
void print(Node* root)
{
    if(root == nullptr)
    {
        return ;
    }
    print(root->left);
    cout<<root->data<<" "<<root->height<<endl;
     print(root->right);

}

int main(){
int t = 1;
// cin>>t;
while(t--){
int inorder[] = {23 , 26 , 43 , 78 , 94 , 97};
int preorder[] = {78 , 26 , 23 , 43 , 94 , 97};
Node* root = BUildTree(inorder , preorder , 0 ,5);
heigh(root);
print(root);
}
}