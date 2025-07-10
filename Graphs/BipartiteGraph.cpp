#include<bits/stdc++.h>
using namespace std;
bool bipart = true;

void color(int  u ,vector<vector<int>> adj, int curr ,vector<int> colorNode ,vector<int> visited)
{
    if(colorNode[u]!= -1 && colorNode[u]!= curr)
    {
        bipart = false;
        return ;
    }
    colorNode[u] = curr;
    if(visited[u])
    {
        return ;
    }
    visited[u] =true;
    for(auto i:  adj[u])
    {
    color(i ,adj ,curr^1, colorNode , visited);
    }



    
}


int main ()
{
    int n , m ;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    vector<int> visited(n , 0);
    vector<int> colorNode(n,-1);

    for(int i= 0 ;i< m ;i ++)
    {
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        
    }

    for(int i = 0 ; i< n ; i++)
    {
        if(!visited[i])
        {
            color(i, adj, 0 , colorNode ,visited);
           
        }
       
    }
    if(bipart)
    {
        cout<<"Graph is Bipart";
    }
    else
    {
        cout<<"NO graph is Not Bipart";
    }


}