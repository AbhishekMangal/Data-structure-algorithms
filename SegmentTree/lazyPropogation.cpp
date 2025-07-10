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
int a[N], T[4*N];
vector<int> lazy(4*N,0);
void build(int node, int st, int en) {
  if (st == en) {
    T[node] = a[st];
    lazy[node] = 0;
    return;
  }
  int mid = (st + en) / 2;
  build(2 * node, st, mid);
  build(2 * node + 1, mid + 1, en);
  T[node] = T[2 * node] + T[2 * node + 1];
  lazy[node] = lazy[2 * node] + lazy[2 * node + 1];
  
}
void range_update(int node, int st , int en, int l, int r, int value)
{
    
    if(lazy[node]!=0)
    {
        T[node] += (en-st+1)*lazy[node];
        if(st!= en)
        {
            lazy[2*node] += lazy[node];
            lazy[2*node+ 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(st>r|| en<l) return ;
    if(st>=l && en<=r)
    {
        T[node] += (en-st+1)*value;
        if(st!= en)
        {
            lazy[2*node]+= value;
            lazy[2*node +1] += value;
        } 
        return;
    }
    int mid = (st+en)/2;
    range_update(2*node, st, mid,l,r,value);
    range_update(2*node+1, mid+1, en,l,r,value);
    T[node] = T[2*node] + T[2*node+1];

}
int query_sum(int node, int st, int en , int l ,int r  )
{
    if(lazy[node]!=0)
    {
        T[node] += (en-st+1)*lazy[node];
        if(st!= en)
        {
            lazy[2*node] += lazy[node];
            lazy[2*node+ 1] += lazy[node];
        }
        lazy[node] = 0;
        
    }
    if(r<st || l>en) return 0;
    if(st>=l && en<= r)
    {
        return T[node];
    }
    int mid = (st+en)/2;
    int x = query_sum(2*node,st,mid, l,r);
    int y = query_sum(2*node+1, mid +1,en, l,r);
    return x+y;
}
int32_t main() {
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 ll t =1;
//  cin >> t;
 while(t--) {
   int n, m;
   cin >>n>>m;
   
   rep(i,0,n)
   {
    cin>>a[i];
   }
   build(1,0,n-1);
   
   while(m--)
   {
    int type;
    cin>>type;
    if(type == 1)
    {
        int a, b,c;
        cin>>a>>b>>c;
        range_update(1,0,n-1,a-1,b-1,c );
       cout<<T[1]<<endl;
    }
    else
    {
        int a ,b;
        cin>>a>>b;
        cout<<query_sum(1,0,n-1,a-1,b-1)<<endl;
    }
   }

}
}