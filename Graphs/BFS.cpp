#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+2;

bool vis[N];

vector<int> adj[N];

int main ()
{
    for(int i =0 ; i<N ; i++)
    {
        vis[i] = 0;
    }

        int n, m;
        cin>>n>>m;
      
        
        for(int i = 0 ;i< m ; i++ )
        {
              int x, y;
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
    

    queue<int> q;
    q.push(1);
    vis[1] = 1;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        cout<<node<< endl;

        for(int x: adj[node])
        {
            if(!vis[x])
            {
                vis[x] = 1;
                q.push(x);
            }
        }
    }

}