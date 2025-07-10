//  wrong

#include<bits/stdc++.h>
 using namespace std;
 
 #define rep(i , a , n) for(int i = a  ; i< n ; i++) 
 const int N = 1e5+2;
 long long int merge(int arr[] , int l ,int mid, int r)
 {
    long long int inv = 0;
    int n1 = mid-l+1;
    int n2= r-mid;
    int a[n1];
    int b[n1];
    rep(i,0,n1)
    {
        a[i] = arr[l+i];
    }
    rep(i,0,n2)
    {
        b[i] = arr[mid+i+1];
    }
    int i = 0, j=0, k=l;
    while(i<n1 && j<n2)
    {
        if(a[i]<=b[j])
        {
            arr[k] = a[i];
            k++; i++;

        }
        else
        {
            a[k] = b[j];
            inv += n1-i;
            k++;
            j++;

        }
    }
    while(i<n1)
    {
        arr[k] = a[i];
            k++; i++;
    }
     while(j<n2)
    {
        arr[k] = b[j];
            k++; j++;
    }
    return inv;

 }

 long long int mergeSort(int arr[] , int l ,int r)
 {
    long long int inv = 0;
    if(l<r)
    {
        int mid = (l+r)/2;
      inv +=  mergeSort(arr, l , mid);
      inv +=  mergeSort(arr, mid+1 , r);
      inv += merge(arr, l , mid, r);

    }
    return inv;
 }
 int main (){
    int n;
    cin>>n;
    int arr[n];
    rep(i,0,n)
    {
        cin>>arr[i];
    }
    cout<<mergeSort(arr, 0 , n-1);

    
    return 0;
 }