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

char findDirection(vector<int> steps)
{
    if(steps[0] == -1)
    {
        return 'U';
    }
    else if(steps[0] == 1)
    {
        return 'D';
    }
    else if(steps[1] == -1)
    {
        return 'L';
    }
    return 'R';
}
// Check that row and col is in the boundary
bool isValid(int row, int col, int n, int m)
{
    if(row<0 || row>=n || col<0 || col>=m) return false;
    return true;
}

vector<vector<int>> findStartAndEndCoord(string map[], int n,  int m)
{
    vector<int> startCoord;
    vector<int> endCoord;
    rep(i,0,n)
    {
        rep(j,0,m)
        {
            if(map[i][j] == 'A')
            {
                startCoord.push_back(i);
                startCoord.push_back(j);
            }
            if(map[i][j] == 'B')
            {
                endCoord.push_back(i);
                endCoord.push_back(j);
            }
        }
    }
    return {startCoord, endCoord};
}

// Apply bfs to find whether it is possible to reach the point B
void bfs(string map[],int n,int m)
{
 
    vector<vector<int>> startEndCoord = findStartAndEndCoord(map, n,m);

    vector<vector<char>> parent(n, vector<char>(m, '*'));
    vector<vector<int>> vis(n, vector<int>(m,0));

    queue<pair<int, int>> q;
    q.push({startEndCoord[0][0], startEndCoord[0][1]});
    vis[startEndCoord[0][0]][startEndCoord[0][1]];
                      
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
            if(isValid(nextRow,nextCol,n,m) && !vis[nextRow][nextCol] && (map[nextRow][nextCol] == '.'  || map[nextRow][nextCol] == 'B'))
            {
                char direction = findDirection(steps);
                parent[nextRow][nextCol] = direction;
                q.push({nextRow, nextCol});
                vis[nextRow][nextCol]++;
            }
        }

    }

    vector<int> endCoord = startEndCoord[1];

    int endRow = endCoord[0];
    int endCol = endCoord[1];

   

    if(parent[endRow][endCol] == '*')
    {
        cout<<"NO"<<endl;
        return;
    }
    else
    {
        cout<<"YES"<<endl;
        string path = "";
        while(parent[endRow][endCol] != '*')
        {
            path += parent[endRow][endCol];

            int direction = parent[endRow][endCol];
            if(direction == 'L')
            {
                endCol++;
            }
            else if(direction == 'R')
            {
                endCol--;
            }
            else if(direction == 'U')
            {
                endRow++;
            }
            else
            {
                endRow--;
            }
        }
        cout<<path.size()<<endl;
        reverse(path.begin(), path.end());
        cout<<path<<endl;
    }

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

   bfs(mat, n,m);
   
}
}