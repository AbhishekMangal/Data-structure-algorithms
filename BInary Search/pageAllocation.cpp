#include <bits/stdc++.h>
using namespace std;

bool isFeasible(int arr[], int mid, int m, int n)

{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]>mid)
        {
            return false;
        }
        if(sum+arr[i]>mid)
        {
            m--;
            sum = arr[i];
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

int MinPageAllocation(int arr[], int n, int m)
{
    int end = 0;
    for (int i = 0; i < n; i++)
    {
        end = arr[i] + end;
    }
    int start = 0;

    
    int result = INT16_MAX;

    while (start < end){
int mid = (start + end) / 2;
        if (isFeasible(arr, mid, m, n))
        {
            
            result = min(result, mid);
            end = mid-1;
        }
        else
        {
           start = mid+1;
        }
    }
    return result;
}

int main()
{
int arr[] = {2,9,10};
int n = 3;
// sort(arr, arr+n);

int m = 2;
cout<<MinPageAllocation(arr, n , m);

}