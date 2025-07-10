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
int32_t main() {
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 ll t;
 cin >> t;
 rep(xyz,0,t) {
   int n;
   cin >>n;
   int a = n;
  vector<int> x;
   while(a--)
   {
    int arr[n];
    rep(i,0,n)
    {
        cin>>arr[i];
    }
    
    int i = n-1;
    int no  =0;
    while(i>=0 && arr[i] == 1)
    {
        no++;
        i--;
    }
    
    x.push_back(no);
    
   }
   sort(x.begin(), x.end());
    int no = 0;
    for(int i=0; i<x.size();i++)
    {
        if(x[i]>=no)
        {
            no++;
            
        }
       
        
    }
    
    cout<<no<<endl;
 
   
}
}