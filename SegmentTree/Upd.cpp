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
    tree[node] = max(tree[2*node],tree[2*node+1]);


}
int query(int node, int st , int en , int l , int r)
{
    if(st>r || en<l)
    {
        return INT_MIN;
    }
    if(l<=st && r>= en)
    {
        return tree[node];
    }
    int mid = (st+en)/2;
    int a = query(2*node, st, mid, l, r);
    int b = query(2*node+1,  mid+1,en, l, r);
    return max(a,b);
}
void update(int node, int st , int en , int a[], int value, int pos)
{
    // cout<<st<<" "<<en<<" "<<pos<<endl;

    if(st==en)
    {
        a[st] = value;
        tree[node] = value;
        return;
    }
    int mid = (st+en)/2;
    if(pos<= mid)
    {
        update(2*node, st, mid,a, value, pos);
    }
    else
    {
        update(2*node+1, mid+1,en, a, value, pos);
    }
    tree[node] = max(tree[2*node], tree[2*node+1]);
    return;
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
    while(1)
    {
        int type;
        cin>>type;
        if(type == -1 )
        {
            break;
        }
        if(type == 1)
        {
            int a, b;
            cin>>a>>b;
            int ans = query(1,0,n-1, a ,b);
            cout<<ans<<endl;

        }
        if(type == 2)
        {
            int pos,val;
            cin>>pos>>val;
            update(1,0,n-1,a,val,pos);
            cout<<query(1,0,n-1,0,n-1)<<endl;
        }
    }
}
} 