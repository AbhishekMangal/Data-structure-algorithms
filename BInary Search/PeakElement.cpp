#include<bits/stdc++.h>
using namespace std;

int peak(int arr[] ,int start ,int end , int n)
{
    if(start>end)
    {
        return -1;
    }
    int mid = (start+end)/2;
    // cout<<mid<<endl;
    if((mid==0 || arr[mid-1]<= arr[mid])&& (mid == n-1 || arr[mid+1]<=arr[mid]))
    {
return mid;
    }
  
 else if(mid!= 0 && arr[mid-1]>arr[mid])
    {
peak(arr ,start ,mid-1 , n);
    }
 else   
    {
        peak(arr ,mid+1 ,end,n);
    }




}

int main () 
{
    int arr[] = {0 , 6 };
   cout<<"The peak element is at index : "<< peak(arr , 0 , 2, 2);
    return 0;
}