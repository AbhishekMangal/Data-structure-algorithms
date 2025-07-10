#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

/*int height(node* root)
{

    if(root==NULL)
    {
        return  0;
    }
    int t =  max(height(root->left) , height(root->right));
    return  t+1;
}
bool ans = true;
/*bool balancedheight(node* root)
{
    if(root==NULL)
    {
        return true;
    }

   if(balancedheight(root->left)==false)
   {
    return false;
   }
   if(balancedheight(root->right)==false)
   {
    return false;
   }

if(abs(height(root->left)-height(root->right))<=1)
{

    return true;
}
else{
    return false;
}




}*/

bool balanceDheight(node *root, int *height)
{
  
    if (root = NULL)
    { 

        return true;
    }
   
    int lh = 0, rh = 0;

    if (balanceDheight(root->left, &lh) == false)
    {
        
        return false;
    }
    if (balanceDheight(root->right, &rh) == false)
    {
        return false;
    }
   
    *height = max(lh, rh) + 1;
    
    if (abs(lh - rh) > 1)
    {
        
        return false;
    }
   
    
        
        return true;
    
}

int main()
{

    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->right->right = new node(5);
    root->right->right->left = new node(8);
    root->right->right->right = new node(9);
    root->right->left = new node(6);
    root->left->left->left = new node(7);
    root->left->left->left->left = new node(10);

    node *root2 = new node(1);
    root2->left = new node(2);
    root2->right = new node(2);

    int height = 0;

    cout << balanceDheight(root, &height);
}