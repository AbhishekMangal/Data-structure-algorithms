#include<bits/stdc++.h>
using namespace std;
const int N  =  1e5+8;
#define rep(i,a,n) for(int i =a ;i<n ; i++)
int main(){
int t =1;
// cin>>t;
while(t--){
    int n ;
    cin>>n;
int arr[n];

rep(i,0, n)
{
    cin>>arr[i];
}
sort(arr, arr+n);
int key ;
cin>>key;
int start = 0;
 int end = n;
 while(start<=end)
 {
    int mid = (start+end)/2;
    if(arr[mid]>key)
    {
        end = mid-1;

    }
    else if(arr[mid]<key)
    {
        start = mid+1;
    }
    else
    {
        cout<<mid+1<<endl;
        return 0;
    }
 }
 cout<<"element is not present"<<endl;
}
}