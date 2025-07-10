#include<bits/stdc++.h>
using namespace std;


bool isFeasible(int arr[], int mid , int m ,int n )
{
    int sum = 0;
    for(int i = 0 ; i< n ; i++){
        if(arr[i]>mid)
        {
            return false;
        }
    if(sum+arr[i]>mid)
    {
        sum = arr[i];
        m-- ;
        if(m<1)
        {
            return false;
        }

    }
    else
    {
        sum = sum +arr[i];
    }

    }
    return true;
}

int minTimerequired(int arr[],  int n  , int m )
{
    int end = 0;
    int start =0;
    for(int i = 0;i< n ; i++)
    {
  
        end = end+arr[i];
    }
    int ans = INT_MAX;

    while(start<end)
    {
        int mid = (start+end)/2;
        if(isFeasible(arr, mid , m , n))
        {
end= mid-1;
ans = min(ans , mid); 
        }
        else{
            start = mid;
        }
    }
    return ans;
}

int main ()
{
    int arr[] ={10,20,30,40};
    int n = 4;
    int m = 2;
   cout<<"Min Time to print the boards : "<< minTimerequired(arr, 4 ,2);
}   