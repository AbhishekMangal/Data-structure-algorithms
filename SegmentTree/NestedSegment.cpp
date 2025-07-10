#include<bits/stdc++.h>
using namespace std;
const int N  =  1e5+8;
#define rep(i,a,n) for(int i =a ;i<n ; i++)
#define ll long long 
struct triplet{
    int l ,r , idx;
};
bool cmp(triplet t1 , triplet t2){
    return t1.r < t2.r;
}
int a[N], tree[4*N];

int query(int node, int st , int en , int l , int r)
{
    if(st>r || en<l)
    {
        return 0;
    }
    if(l<=st && r>= en)
    {
        return tree[node];

    }
    int mid = (st+en)/2;
    int a = query(2*node, st, mid, l, r);
    int b = query(2*node+1,  mid+1,en, l, r);
    return a+b;
}
void update(int node, int st , int en , int pos, int value)
{
    // cout<<st<<" "<<en<<" "<<pos<<endl;

    if(st==en)
    {
      
        tree[node] = value;
        return;
    }
    int mid = (st+en)/2;
    if(pos<= mid)
    {
        update(2*node, st, mid, pos, value);
    }
    else
    {
        update(2*node+1, mid+1,en,  pos, value);
    }
    tree[node] = (tree[2*node]+ tree[2*node+1]);
    return;
}
int32_t main(){
ios_base::sync_with_stdio(false);
   cin.tie(NULL);

ll t;
cin>>t;
while(t--){
int n ;cin>>n;
triplet t1;
t1.l =t1.r = -1;
vector<triplet> t(n, t1);

int x;
rep(i,0,2*n){
    cin>>x;
    if(t[x-1].l == -1)
    {
        t[x-1].l = i;
    }
    else
    {
        t[x-1].r = i;
    }
    t[x-1].idx = x;
}

sort(t.begin(), t.end(), cmp);
memset(tree, 0,N);
vector<int> ans(n);
rep(i,0,n)
{
    cout<<t[i].idx<<" "<<t[i].l<<" "<<t[i].r<<endl;
    ans[t[i].idx-1] = query(1,0,2*n-1, t[i].l , t[i].r);
    update(1,0,2*n-1, t[i].l , 1);
}
rep(i,0 ,n)
{
    cout<<ans[i]<<" ";
}
cout<<endl;
}
}