#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void Level_trigger_Right(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        if (q.front() != NULL)
        {
            int x = q.front()->data;

            if (q.front()->left != NULL)
            {
                q.push(q.front()->left);
            }
            if (q.front()->right != NULL)
            {
                q.push(q.front()->right);
            }

            q.pop();
            if (q.front() == NULL)
            {
                cout << x << " ";
            }
        }
        else
        {
            q.pop();
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
    }
}

void Level_trigger_left(Node *root)
{
    if(root== NULL)
    {
        return ;
    }
   
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int x = q.size();
        cout << q.front()->data << " ";
        for (int i = 0; i < x; i++)
        {
            if (q.front()->left != NULL)
            {
                q.push(q.front()->left);
            }
            if (q.front()->right != NULL)
            {
                q.push(q.front()->right);
            }
            q.pop();
        }
    }
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    Level_trigger_left(root);
    cout<<endl;


    Node* root2 = new Node(5);
    root2->left = new Node(3);
    root2->right = new Node(6);
    root2->left->left = new Node(2);
    root2->left->right = new Node(4);

    Level_trigger_left(root2);
}
 