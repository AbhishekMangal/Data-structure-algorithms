#include<bits/stdc++.h>
using namespace std;


const int N = 1e5+2;

bool vis[N];

vector<int> adj[N];

void dfs(int node)
{
     int a  = node;
    //preorder

    vis[node] = 1;
    cout<<node<<" ";

    //Inorder

    for(int x : adj[node]  )
    {
        if(!vis[x]){
     dfs(x);
        }

        
    }
   

    // postorder
    
    //  cout<<node<<" "<<a<<endl;
     
     return ;

    

    
}

int main ()
{
    int n, m;
    cin>>n>>m;
    for(int i = 0;i<N; i++)
    {
        vis[i] = 0;
    }
    for(int i =0;  i< m ; i++)
    {
        int x, y;
        cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);

    }

    dfs(1);

}
