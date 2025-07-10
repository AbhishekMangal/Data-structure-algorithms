#include<bits/stdc++.h>
using namespace std;

#define rep(i , a , n) for(int i = a  ; i< n ; i++) 
const int N = 1e5+2;
bool isFeasible(int arr[] , int n , int k , int dis)
{
  
    int j = 0 ;
    int count =  1;
    for(int i =0 ;i< n ; i++)
    {
        if(arr[i]-arr[j] >=dis)
        {
            j = i;
            count++;

        }
    }
   
    if(count >= k)
    {
        return true;
    }

    return false;
}
int result = -1;
int minDIstance(int arr[]  , int n , int left , int right ,int k)
{
    
    if(left >= right)
    {
        return 0 ;
    }
    int mid = (left+right)/2;
   
    
    if(isFeasible(arr, n , k , mid) )
    {
       
        result = max(result,mid);
       
        left = mid+1;
      
    }
    else
    {
         
       right  = mid;
    }
    minDIstance(arr , n , left,right, k );
    return result ;
}

int main (){
    int arr[] = {11,2,7,5,1,12};
    sort(arr ,arr+6);
   cout<< minDIstance(arr,6 , arr[0] , arr[5],3 );
    
    return 0;
}