#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+9;
int main (){
    int n, m ;
    cin>>n>>m;
    int cnt = 0;
    vector<vector<int>> adj_lis(N);
    vector<int> indeg(N, 0);
    for(int i = 0 ;i< m ; i++)
    {
        int u , v;
        cin>>u>>v;
        adj_lis[u].push_back(v);
        indeg[v]++;
        

    }

    queue<int> pq;

    for(int i=0 ; i<n ; i++)
    {
    if(indeg[i] == 0)
    {
        pq.push(i);
    }

}

while(!pq.empty())
{
    cnt++;
    int x = pq.front();
    pq.pop();
    cout<<x<< " ";
    for(auto it: adj_lis[x])
    {
        indeg[it]--;
        if(indeg[it]==0)
        {
            pq.push(it);
        }
    }
}
}