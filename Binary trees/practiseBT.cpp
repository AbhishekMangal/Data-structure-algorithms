struct Node
{
   int data;
   Node* left;
   Node* right;
   Node(int value)
   {
    data = value;
    left = nullptr;
    right = nullptr;
   }
};
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
#include<bits/stdc++.h>
using namespace std;
const int N  =  1e5+8;
#define rep(i,a,n) for(int i =a ;i<n ; i++)
int count(Node* root)
{
    if(root == nullptr)
    {
        return 0;
    }
    return count(root->left)+count(root->right)+1;
}
int sum(Node* root)
{
    if(root== nullptr)
    {
        return 0;
    }
    return sum(root->left)+sum(root->right)+root->data;
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
    return node;

}
bool findNOde(Node* root , int target , vector<int> &path1)
{
    if(root == nullptr)
    {
        return false;
    }
    
    if(root->data == target)
    {
        return true;
    }
    path1.push_back(root->data);
    if(findNOde(root->left , target , path1) || findNOde(root->right ,target , path1))
    {
        return true;
    }
    else
    {
        path1.pop_back();
       
    }
    return false;
}
Node* buildteePI(int postorder[] , int inorder[] , int start , int end)
{
    static int idx = end;
    if(start>end)
    {
        return nullptr;
    }
    int curr = postorder[idx];
    Node * node = new Node(curr);
    idx--;
    if(start == end)
    {
        return node;
    }
    int pos = find(inorder, curr, start ,end);
    node->right = buildteePI(postorder , inorder , pos+1 ,end);
    node->left = buildteePI(postorder , inorder ,start , pos-1);
}
void print(Node* root)
{
    if(root == nullptr)
    {
        return ;
    }
    print(root->left);
     print(root->right);
    cout<<root->data<<" ";

}
int sumReplacement(Node* root)
{
    if(root == nullptr)
    {
        return 0;
    }
  root->data = sumReplacement(root->left)+sumReplacement(root->right)+root->data;
  return root->data;

}

int main(){
int t = 1;
// cin>>t;
while(t--){
int inorder[] = {9,3,15,20,7};
int preorder[] = {78 , 26 , 23 , 43 , 94 , 97};
int postorder[] = {9,15,7,20,3};
int inorder2[] = {4, 2, 5 , 1 , 3};
int preorder2[] = {1 , 2 , 4 , 5 , 3};
// Node* root = BUildTree(inorder , preorder ,0, 5);
Node* root2 = buildteePI(postorder , inorder ,0, 4);
// Node* root3 = BUildTree(inorder2 , preorder2 ,0, 4);
// vector<int> path1;
// vector<int> path2;
// findNOde(root , 26 , path1);
// findNOde(root , 94 , path2);
// int i = 0;
// while(i<path1.size() && i<path2.size()){
//     if(path1[i]!= path2[i])
//     {
//         break;
//     }
//     i++;
// }

// int distance1 = path1.size()-i;
// int distance2 = path2.size()-i;
// cout<<distance1+distance2+2<<endl;
print(root2);

// cout<<endl;
// print(root3);
// cout<<endl;
// sumReplacement(root3);
// print(root3);
// cout<<count(root2)<<endl;
// cout<<sum(root2)<<endl;
// print(root2);

}
}

