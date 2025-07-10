#include<bits/stdc++.h>
using namespace std;



// Adjacency of list
const int N = 1e5+2, MOD = 1e9+7;

vector<int> adj[N];
int main ()
{
    int n,m ;
    // cin>>n>>m;

    // vector<vector<int>> adjm(n+1 , vector<int>(n+1 , 0));

    // for(int i = 0 ; i< m ; i++)
    // {
    //     int x, y;
    //     cin>>x>>y;
    //     adjm[x][y] = 1;
    //     adjm[y][x] = 1;
    // }

    // for(int i = 1 ; i< n+1 ; i++)
    // {
    //     for(int j = 1 ; j< n +1 ; j++)
    //     {
    //         cout<<adjm[i][j]<<" ";
    //     }cout<<endl;
    // }

    // if(adjm[7][3] == 1)
    // {
    //     cout<< "there  is a edge between 3 and 7"<<endl;
    // }
    // else
    // {
    //     cout<< " No edge "<<endl;
    // }



    cin>>n>>m;
    for(int i = 0 ; i< m ; i++)
    {
int x, y;
cin>>x>>y;

adj[x].push_back(y);
adj[y].push_back(x);
    }

    cout<<"Adjacency list Of the above graph is given:-"<<endl;

    for(int  i = 1 ; i< n+1 ; i++)
    {
        cout<<i<<"-->";
        for(int x : adj[i])
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
}



