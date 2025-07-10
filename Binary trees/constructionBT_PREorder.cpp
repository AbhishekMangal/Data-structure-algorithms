#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data  ;
    Node* left ;
    Node* right ;
    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    } 

};


// Node* ConstrucBST(Node* root , int arr[] , int min , int max)
// {
//     static int  i = 0;
//     Node* a = new Node(arr[i]);
//     i++;
//     if(root==NULL)
//     {
//         return new Node(arr[i]);
//     }

//     if(a->data < max){

//     root->left = ConstrucBST(root , arr , NULL , a->data);
//     }
//     else if(a->data > arr[i-2])
//     {
//         return;
      
//     }
//     else if(a->data< arr[i-2])
//     {
//         root->right = ConstrucBST(root , arr , arr[i-2] , a->data);
//     }

// }


Node* ConstructBST (int preorder[] ,int* preorderIDX , int key, int min  , int max , int n)
{
    if(*preorderIDX > n)
    {
        return NULL;
    }

    Node* root = NULL;
    if(key>min  && key<max)
    {
        root= new Node(key);
        *preorderIDX = *preorderIDX+1;
        if(*preorderIDX < n)
        {
root->left = ConstructBST(preorder , preorderIDX , preorder[*preorderIDX], min , key , n);
        }
        if(*preorderIDX< n)
        {
            root->right = ConstructBST(preorder ,preorderIDX , preorder[*preorderIDX], key ,max , n);
        }

    }
    return root;
}
void Print(Node* root)
{
    if(root ==NULL)
    {
        return;
    }
    (root->left);
    cout<<root->data<<" ";
    (root->right);

    }

int main () 
{
    int preorder[5] = {10 , 2 , 1,  13 , 11};
    int n  = 5;
    int preorderIDX = 0;
 Node* root  = ConstructBST(preorder, &preorderIDX , preorder[0] , INT_MIN ,INT_MAX , n);
 Print(root);

}
