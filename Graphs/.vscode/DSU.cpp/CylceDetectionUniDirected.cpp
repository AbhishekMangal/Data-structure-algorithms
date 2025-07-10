#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+2;
   vector<int> parent(N);
   vector<int> size(N);

int find_set( int a)
{
    if(parent[a] == a)
    {
        return a;
    }
    return parent[a] = find_set(parent[a]);
}



void union_set(int a, int b)
{
        a = find_set(a);
        b= find_set(b);
        if(a!=b)
        {
            if(size[a]< size[b])
            {
                 swap(a, b);
            }
            parent[b] = a;
            size[a] += size[b];

           
        }


}

int main ()
{
    int n , m ;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    bool cycle = false;
    for(int i = 0 ; i<N; i++)
    {
parent[i] = i;
size[i] = 1;
    }
    for(int i = 0 ; i< m ; i++)
    {
        int x,  y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        x = find_set(x);
        y = find_set(y);
        // adj.push_back({x ,y});
         if(x!=y)
        {
            union_set(x ,y);
        }
        else
        {
            cycle = true;
        }
        
    }
    // for(auto i : adj)
    // {
    //     int x = i[0];
    //     int y= i[1];
    //      x = find_set(x);
    //     y = find_set(y);
    //     if(x!=y)
    //     {
    //         union_set(x ,y);
    //     }
    //     else
    //     {
    //         cycle = true;
    //     }
    // }
 

      if(cycle)
      {
        cout<<"Yes Cycle is Present"<<endl;
      }
      else
      {
        cout<<"No Cycle is Not Present"<<endl;
      }
}