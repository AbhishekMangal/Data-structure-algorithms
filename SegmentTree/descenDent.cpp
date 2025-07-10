#include<bits/stdc++.h>
using namespace std;
const int N  =  1e5+8;
#define rep(i,a,n) for(int i =a ;i<n ; i++)
#define ll long long 
int a[N], tree[4*N];
void build(int node, int st, int en)
{
    if(st == en)
    {
        tree[node] = a[st];
        return ;
    }
    int mid = (st+en)/2;
    build(2*node, st,mid);
    build(2*node+1, mid+1 ,en );
    tree[node] = tree[2*node]+tree[2*node+1];


}
int query(int node, int st , int en , int k )
{
    // cout<<node<<" "<<st<<" "<<k<<endl;
    if(st == en)
    {
        return st;
    }
    
    int mid = (st+en)/2;
    if(k<tree[2*node]){
    return query(2*node, st, mid, k);
    }
    else{
    return query(2*node+1,  mid+1,en, k-tree[2*node]);
    }
    
}
void update(int node, int st , int en , int pos)
{
    // cout<<st<<" "<<en<<" "<<pos<<endl;

    if(st==en)
    {
      if(a[st] == 1){
        a[st] = 0;
      }
      else
      {
         a[st] = 1;
      }
        tree[node] = a[st];
        return;
    }
    int mid = (st+en)/2;
    if(pos<= mid)
    {
        update(2*node, st, mid, pos);
    }
    else
    {
        update(2*node+1, mid+1,en,  pos);
    }
    tree[node] = tree[2*node]+ tree[2*node+1];
    return;
}
int32_t main(){
ios_base::sync_with_stdio(false);
   cin.tie(NULL);
ll t= 1;
// cin>>t;
while(t--){
int n, m;
cin>>n>>m;
rep(i,0,n) cin>>a[i];
build(1,0,n-1);
while(m--)
{
    int a,b;
    cin>>a>>b;
    if(a == 1)
    {
        update(1,0,n-1,b);
    }
    else
    {
        cout<<query(1,0,n-1,b) <<endl;
    }
}
}
}