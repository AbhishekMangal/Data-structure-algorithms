 #include<bits/stdc++.h>
 using namespace std;

 int get_comp(int idx, vector<int> &visited, vector<vector<int>> &adj)
 {
    if(visited[idx])
    {
        return 0;
    }
    visited[idx] = true;
    int ans = 1;
    for(auto i : adj[idx])
    {
        ans += get_comp(i,  visited , adj);
    }
    return ans;
 }

int main (){
 int n , m ;
 cin>>n>>m;

 vector<vector<int>> adj(n);
 vector<int> visited(n,0);

 vector<int> components;
 for(int i = 0 ; i< m ; i++)
 {
    int x ,y ;
    cin>>x>>y;
   
    adj[x].push_back(y);
    adj[y].push_back(x);
 }

 for(int i = 0 ; i< n ; i++)
 {
    if(!visited[i])
    {
        components.push_back(get_comp(i, visited ,adj));
    }
 }
int ways = 0;


 for(auto i : components)
 {
    ways = ways+(n-i)*i;
    cout<<i<<" ";
 }
 cout<<endl;
 cout<<ways/2<<" ";


}

