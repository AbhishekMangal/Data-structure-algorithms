#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+8;
#define rep(i,a,n) for(int i = a; i < n; i++)
#define ll long long
#define int long long
const int mod = 1e9+7;
int partition(int a[], int start, int end)
{
    
    int j = start-1;
    for(int k = start;k<end; k++ )
    {
        if(a[k]<a[end])
        {
            j++;
            swap(a[k], a[j]);
        }
    }
    
    swap(a[end], a[j+1]);
    return j+1;
}
void quick(int a[], int start, int end)
{
    if(start<end){
    int pi = partition(a, start, end);
    cout<<pi<<endl;
    quick(a, start, pi-1);
    quick(a, pi+1, end);
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
   int  n;
   cin>>n;
   int a[n];
   rep(i,0,n) cin>>a[i];
   quick(a, 0, n-1);
   rep(i,0,n) cout<<a[i]<<" ";
   cout<<endl;
}
