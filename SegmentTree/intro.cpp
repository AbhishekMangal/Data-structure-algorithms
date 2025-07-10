#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for(int i =a ;i<n ; i++)
#define ll long long 
const int N = 1e5+2, mod = 1e9+7;
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
int32_t main(){
ios_base::sync_with_stdio(false);
   cin.tie(NULL);
ll t;
cin>>t;
while(t--){
    int n ;
    cin>>n;
    for(int i = 0 ;i<n; i++)
    {
        cin>>a[i];
    }
    build(1,0,n-1);
    rep(i,1,15){
        cout<<tree[i]<<endl;
    }
}
}