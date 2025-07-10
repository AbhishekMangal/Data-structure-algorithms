#include<bits/stdc++.h>
using namespace std;

#define rep(i , a , n) for(int i = a  ; i< n ; i++) 
const int N = 1e5+2; 
int merge(int arr[], int l ,int mid , int r)
{
    int n1 = mid-l+1;
    int n2 = r-mid;
    int a[n1];
    int b[n2];
    rep(i,0,n1)
    {
        a[i] = arr[l+i];
    }
    rep(i,0,n2)
    {
        b[i] = arr[mid+1+i];
    }
    int i = 0;
    int j = 0;
    int k = l;
    while(i<n1 && j<n2)
    {
        if(a[i]<b[j]){
            arr[k] = a[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = b[j];
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
    

}

void mergeSort(int arr[] , int l ,int r)
{
    if(l<r)
    {
        int mid = (l+r)/2;
        mergeSort(arr, l ,mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l , mid, r);
    }
    return;
}
int main (){
    int arr[] = {5,4, 3, 2 , 1 , 6, 7};
    mergeSort(arr,0, 6);
    rep(i,0, 7 )
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}