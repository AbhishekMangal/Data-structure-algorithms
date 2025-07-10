#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 3e5+8;
#define rep(i,a,n) for(int i = a; i < n; i++)
#define ll long long
#define int long long
int findMaxIndex(vector<vector<int>> &mat, int n, int m , int col) // Find the Max Index in a particular Column
{
    int maxValue =  -1;
    int index = 0;
    for(int i = 0; i<n; i++)
    {
        if(mat[i][col]>maxValue)
        {
            maxValue = mat[i][col];
            index = i;
        }
    }
    return index;
}
vector<int> findPeakGrid(vector<vector<int>> &mat) // Find the index of  peak element in the grid
{
    int n = mat.size();
    int m = mat[0].size();
    int low = 0;
    int high = n-1;
    // Use A Binary search to find the col of peak element
    while(low<= high)
    {
        int mid = (low+high)/2;

        // Now in this column find the index of the max element in the grid

        int index = findMaxIndex(mat,n,m,mid);

        int left = mid>0 ? mat[index][mid-1] : INT_MIN;    
        int right = mid<m-1? mat[index][mid+1]: INT_MIN;

        if(( mat[index][mid]>left) && ( mat[index][mid]> right ))
        {
            return {index , mid};
        }
        else if( mat[index][mid]<  left )
        {
            high = mid-1;
        }
        else
        {
            low  = mid+1;
        }
    }
    return {-1, -1};

}
int32_t main() {
 ios_base::sync_with_stdio(false);
 cin.tie(NULL); 
   int row, col;
   cin >>row>>col;
   vector<vector<int>> arr(row, vector<int>(col));
   for(int i = 0; i<row; i++){
    for(int j= 0; j<col; j++)
    {
        cin>>arr[i][j];
    }
   }
   vector<int> peak = findPeakGrid(arr);
   cout<<peak[0]<<" "<<peak[1]<<endl;
}