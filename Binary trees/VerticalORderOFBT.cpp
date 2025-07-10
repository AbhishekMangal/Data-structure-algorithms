#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    Node* left ;
    Node* right ;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;

    }
};


void horizontal(Node* root , int key , map<int ,vector<int>> &q)
{
    if(root == NULL)
    {
        return ;
    }

  
    q[key].push_back(root->data);


    horizontal(root->left , key-1 ,q);
    horizontal(root->right , key+1 ,q );
}


int main ()
{
    Node* root = new Node(10); 
    root->left = new Node(7);
    root->right = new Node(4);
    root->left->left = new Node(3);
    root->left->right = new Node(11);
    root->right->left = new Node(14);
    root->right->right = new Node(6);

   map<int ,vector<int> > m;
   int hdis = 0;
horizontal(root , hdis , m);
   map<int , vector<int>> :: iterator it;
   for(it = m.begin() ; it!= m.end() ; it++ )
   {
    int j = it->second.size();

 for(int i = 0 ; i<(it->second).size() ; i++)
 {
cout<< (it->second)[i]<<" ";
 }
cout<<endl;
   

   }


}


// Time complexity = Nlogn reduces by unordered_map;