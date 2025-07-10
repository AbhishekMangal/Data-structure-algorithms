#include <bits/stdc++.h>
using namespace std;

bool isCycle(int src, vector<vector<int>> &adj, vector<int> &visi, vector<int> &stack)
{
    stack[src] = true;

    if (!visi[src])
    {

        visi[src] = true;
        for (auto i : adj[src])
        {

            if (!visi[i] && isCycle(i, adj, visi, stack))

            {
                return true;
            }
            if (stack[i])
            {
               
                return true;
            }
           
        }
    }



    stack[src] = false;
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+5);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    bool cycle = false;

    vector<int> stack(n+1, 0);
    vector<int> visi(n+2, 0);

    for (int i = 0; i < n; i++)
    {
        if (!visi[i] && isCycle(i, adj, visi, stack))
        {
            cycle = true;
        }
    }
    if (cycle)
    {
        cout << "Cycle is Present";
    }
    else
    {
        cout << "Cycle is Not present";
    }
}