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
vector<vector<int>> dir = {{-1, 0}, {1,0}, {0,-1}, {0,1}};
// Check that row and col is in the boundary
bool isValid(int row, int col, int n, int m)
{
    if(row<0 || row>=n || col<0 || col>=m) return false;
    return true;
}
 
// Apply bfs to find all the no of rooms present in the matrix
int bfs(string mat[],int n,int m)
{
 
    int rooms = 0;
    vector<vector<int>> vis(n, vector<int>(m,0));
    rep(i,0,n)
    {
        rep(j,0,m)
        {
            if(mat[i][j] == '.' && !vis[i][j])
            {
                rooms++;
                queue<pair<int, int>> q;
                q.push({i, j});
                vis[i][j]++;    
               
                while(!q.empty())
                {
                    auto it = q.front();
                    q.pop();
 
                    int row = it.first;
                    int col = it.second;
 
                    for(auto steps: dir)
                    {
                        int nextRow = row+steps[0];
                        int nextCol = col+steps[1];
                        if(isValid(nextRow,nextCol,n,m) && !vis[nextRow][nextCol] && mat[nextRow][nextCol] == '.')
                        {
                            
                            q.push({nextRow, nextCol});
                            vis[nextRow][nextCol]++;
                        }
                    }
 
                }
            }
        }
    }
    return rooms;
}
int32_t main() {
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 ll t = 1;
//  cin >> t;
 while(t--) {
   int n, m;
   cin >>n>> m;
   string mat[n];
   rep(i,0,n)
   {
    cin>>mat[i];
   }
 
   int rooms = bfs(mat, n,m);
   cout<<rooms<<endl;
}
}