#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2 ;
vector<int> parent(N);
vector<int> size(N);
void make_set(int v)
{
    parent[v] =v;
    size[v] = 1;
}

int find_set(int v)
{
  if(v == parent[v])
  {
    return v;
  }
  return parent[v] = find_set(parent[v]);
}


void union_set (int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if(a!=b)
    {
        if(size[a] <size[b])
        {
            swap(a ,b);
        }
        parent[b] = a;
        size[a] += size[b];
    }
}
int main ()
{
    int n , m ;
    cin>>n>>m;
    vector<vector<int>> adj;
    for(int i = 0 ;i<N; i++)
    {
        make_set(i);
    }
    for(int i = 0 ; i< m ; i++)
    {
        int w, u ,v ;
        cin>>u>>v>>w;
        adj.push_back({w , u ,v});
    }
    sort(adj.begin() ,adj.end());
   int cost = 0;
    for(auto i : adj)
    {
        int w = i[0]; 
        int u = i[1]; 
        int v = i[2]; 
      int  x = find_set(u);
    int  y = find_set(v);
        if(x != y)
        {
            cout<<u << " "<<v<<"\n";
            union_set(u ,v);
            cost += w;
        }


    }
    cout<<cost<<endl;
}