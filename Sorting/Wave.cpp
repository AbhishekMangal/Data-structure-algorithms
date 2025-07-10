#include<bits/stdc++.h>
using namespace std;

void WaveSort(int arr[] , int n)
{
    for(int i = 1; i<n ;i=i+2)
    {
        if(arr[i]>arr[i-1])
        {
            swap(arr[i],arr[i-1]);
        }
        if(arr[i]>arr[i+1] && i<n-1)
        {
            swap(arr[i],arr[i+1]);
        }

    }
}
int main ()
{
    int arr[] = {1,3,4,7,5,6,2};
    int n  = 7;
    WaveSort(arr, n);
    for(int i =0; i<n ; i++)
    {
        cout<<arr[i]<<" ";
    }
}