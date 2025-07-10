#include<bits/stdc++.h>
using namespace std;
const int N  =  1e5+8;
#define rep(i,a,n) for(int i =a ;i<n ; i++)
#define ll long long 
const int mod = 1e9+7;
// time complexity = s+t;

// p^i*hash[i...j] = has[0...j]-hash[0...i-1]
int32_t main(){
ios_base::sync_with_stdio(false);
   cin.tie(NULL);
ll t;
cin>>t;
vector<long long> power(N);
while(t--){
int p = 31;
   string s;
   cin>>s;
   string a;
   cin>>a;
   power[0] = 1;
   for(int i = 1; i<N; i++)
   {
      power[i] = (power[i-1]*p)%mod;
   }
   vector<long long> h(a.size()+1, 0);
   for(int i =0; i<a.size(); i++)
   {
      h[i+1] = (h[i]+(a[i]-'a'+1)*power[i])%mod;
   }
   long long h_s  = 0; // hashing
   for(int i = 0; i<s.length(); i++)
   {
      h_s = (h_s + (s[i]-'a'+1)*power[i])%mod;
   }
   for(int i = 0; i+s.length()-1<a.size(); i++)
   {
      long long cur_h = (h[i+s.length()]-h[i]+mod)%mod; // yha h[i+s.length()] chota bhi ho skta h bcz mod liya h so m add kr diya
      if(cur_h ==(h_s*(power[i]))%mod)
      {
         cout<<i<<endl;
         break;
      }
   }


}
}