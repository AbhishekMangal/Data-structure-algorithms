#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+8;

bool isCycle(int src , vector<int> adj[] , vector<bool> &visi , int parent)
{
    visi[src] = 1;

    for(auto X: adj[src])
    {
        if(X!=parent){
        if(visi[X])
        {
        return true;
        }
        
        
            if(!visi[X] && isCycle(X , adj , visi ,src))
            {
                return true;
            }
        
        }
    }
    return false;
}


int main()
{
    int n , m ;
    cin>>n>>m;
    vector<int> adj[N];
   vector<bool> visi(n, 0);
   bool ans = false;
    for(int i = 0 ; i< m ; i++ )
    {
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        // if(visi[y] != 0 )
        // {
           
        //     ans = true;
        //     cout<<"Yes Cycle Is Present In  this Grap"<<endl;
        //     break;
        //     return 0;
        // }
        
        // visi[y] = 1;
        
        // visi[x] = 1;

    }
bool cycle = false;
cout<<1<<endl;
    for(int i  = 0 ; i< n ; i++)
    {
        if(!visi[i] && isCycle(i , adj , visi , -1))
        {
cycle = true;
        }
    }

  cout<<cycle<<endl;
   
   
    

  
}