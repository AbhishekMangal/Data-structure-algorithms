#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 3e5+8;
#define rep(i,a,n) for(int i = a; i < n; i++)
#define ll long long
#define int long long
// utilty: Marked all the cities as visited that are reachable from the ith city

void dfs(int node, vector<int> &vis, vector<vector<int>> &roads)
{
    if(!vis[node])
    {
        vis[node] = 1;
        for(auto child: roads[node])
        {
            dfs(child, vis, roads);
        }
    }
    return ;
}
int32_t main() {
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 ll t = 1;
//  cin >> t;
 while(t--) {
   int n ,m;
   cin >>n>>m;

   vector<vector<int>> roads(n+1);
   rep(i,0,m)
   {
    int a , b;
    cin>>a>>b;
    roads[a].push_back(b);
    roads[b].push_back(a);
   }

   vector<int> vis(n+1, 0);
   vector<int> cmp;
   rep(i,1,n+1)
   {
    if(!vis[i])
    {
        cmp.push_back(i);
        dfs(i, vis, roads);
    }
   }

   int roadsBuild = cmp.size()-1;
   cout<<roadsBuild<<endl;
   rep(i,0, cmp.size()-1)
   {
    cout<<cmp[i]<<" "<<cmp[i+1]<<endl;;
   }
   cout<<endl;
}
}