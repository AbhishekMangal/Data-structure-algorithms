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

void bfs(vector<vector<int>> &connection, int n, int m)
{
    int src = 1;
    int dest = n;
    vector<int> countComputer(n+1, INT_MAX);
    queue<pair<int, int>> q;
    vector<int> parent(n+1, -1);
    q.push({1,1});
    countComputer[1] = 1;
    while(!q.empty())
    {
        auto it = q.front();
        q.pop();
        int currentCost = it.first;
        int currCmp = it.second;

        for(auto cmp: connection[currCmp])
        {
            if(countComputer[cmp] > countComputer[currCmp]+1)
            {
                parent[cmp] = currCmp;
                countComputer[cmp] = countComputer[currCmp]+1;
                q.push({countComputer[cmp], cmp});
            }
        }
    }
    if(parent[n] == -1)
    {
        cout<<"IMPOSSIBLE"<<endl;
        return ;
    }
    cout<<countComputer[n]<<endl;
    vector<int> cmpInRoute;
    while(parent[n] != -1)
    {
        cmpInRoute.push_back(n);
        n = parent[n];
    }
    cmpInRoute.push_back(1);
    for(int i = cmpInRoute.size()-1; i>= 0; i--)
    {
        cout<<cmpInRoute[i]<<" ";
    }
    cout<<endl;
}
int32_t main() {
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 ll t= 1;
//  cin >> t;
 while(t--) {
   int n, m;
   cin >>n>>m;

   vector<vector<int>> connection(n+1);
   rep(i,0,m)
   {
    int a, b;
    cin>>a>>b;
    connection[a].push_back(b);
    connection[b].push_back(a);
   }

   bfs(connection, n, m);


}
}