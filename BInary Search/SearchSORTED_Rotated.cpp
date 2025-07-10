#include<bits/stdc++.h>
using namespace std;



int SearchKey(int arr[] , int n  , int left ,int right, int key )
{
   
if(left>right)
{
    return -1;
}
    int mid = (left+right)/2;
    if(arr[mid]== key)
    {
        return mid;
    }

  if(arr[left]<= arr[mid])
  {
    if(key>=arr[left] && key<=arr[mid])
    {
        return SearchKey(arr, n , left , mid-1 ,key);
    }
    else
    {
        return SearchKey(arr, n , mid+1 , right , key);

    }
  }
  
  
    if(key>=arr[mid] && key<=arr[right])
    {
        return SearchKey(arr , n  ,mid+1 ,right ,key);
    }
    else
    {
        return SearchKey(arr, n , left , mid-1 ,key);
    }
  
}


int main ()
{
    int arr[] = {6 , 7 , 8 , 9 , 10 , 1 , 2 , 5};
   int x=  SearchKey(arr , 5 , 0 , 7 ,8);
   if(x == -1)
   {
    cout<<"KEY Doesn't Exist"<<endl;
   }
   else
   {
    cout<<"KEY is Present at index = "<<x<<endl;
   }
}