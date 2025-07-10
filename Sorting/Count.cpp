#include<bits/stdc++.h>
using namespace std;

#define rep(i , a , n) for(int i = a  ; i< n ; i++) 
const int N = 1e5+2;
int brr[N];
void countSort(int arr[], int n )
{
    int crr[n];
    
    memset(brr, 0 , sizeof(brr));
    for(int i =0 ;i<n; i++)
    {
        brr[arr[i]]++;
    }
    for(int i =1 ;i<N; i++)
    {
        brr[i] = brr[i-1]+brr[i] ;
    }
    for(int i = n-1 ; i>=0 ; i--)
    {
        crr[brr[arr[i]]-1] = arr[i];
        brr[arr[i]]--;

    }
    rep(i,0,n)
    {
        arr[i] = crr[i];
    }
}
int main (){
    
    int arr[] = {1,3,2,3,4,1,6,4,3};
    countSort(arr, 9);
    rep(i,0,9)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}