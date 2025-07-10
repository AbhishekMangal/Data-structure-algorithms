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
vector<int> Fenwick(N,0);
void update(int idx, int value, int n)
{
    while(idx<=n)
    {
        Fenwick[idx] += value;
        idx += ((idx)&(-idx));
    }
}
int query(int idx)
{
    int sum = 0;
    while(idx>0)
    {
        sum += Fenwick[idx];
        idx -= ((idx)&(-idx));
    }
    return sum;
}
int32_t main() {
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 ll t = 1;
//  cin >> t;
 while(t--) {
   int n,m;
   cin >>n>>m;
   int arr[n+1];
   map<int, vector<int>> x;
   rep(i,1,n+1)
   {
    cin>>arr[i];
    x[arr[i]].push_back(i);
    if (x[arr[i]].size() == 1) {
        update(i, 1, n);
    }
    
   }
   for(auto &it: x)
   {
    reverse(it.second.begin(), it.second.end());
   }
 

   vector<vector<int>> q;
   rep(i,0,m)
   {
    int a,b;
    cin>>a>>b;
    q.push_back({a,b,i});
   }
   sort(q.begin(), q.end());
   vector<int> ans(m);
   int start = 1;
   rep(i,0,m)
   {
    int a = q[i][0];
    int b = q[i][1];
    while(start<a)
    {
        
        int no =arr[start];
        x[no].pop_back();
        update(start,0,n);;
        if(!x[no].empty())
        {
            int pos = x[no].back();
            update(pos,1,n);
        }
        start++;
    }
    int fans = query(b)-query(a-1);
    ans[q[i][2]] = fans;
   }
   for(auto it: ans)
   {
    cout<<it<<endl;
   }
   cout<<endl;
}
}