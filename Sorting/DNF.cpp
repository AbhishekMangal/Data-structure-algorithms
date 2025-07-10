#include<bits/stdc++.h>
using namespace std;

#define rep(i , a , n) for(int i = a  ; i< n ; i++) 
const int N = 1e5+2;
int main (){
    int arr[]= {1,1,2,0,0,1,2,2,1,0};
    int low = 0;
    int mid = 0;
    int high = 9;
   while(mid<=high)
    {
        if(arr[mid]== 0)
        {
            swap(arr[low] ,arr[mid]);
            low++, mid++;
        }
        else if(arr[mid] == 2)
        {
            swap(arr[mid], arr[high]);
            high--;
        }
        else
        {
            mid++;
        }
       
    }  rep(i,0,10)
    {
        cout<<(long long)ceil(arr[i])<<" ";
    }
 
   
    return 0;
}