#include<bits/stdc++.h>
using namespace std;
const int N  =  1e5+8;
#define rep(i,a,n) for(int i =a ;i<n ; i++)
#define ll long long 
// time complexity = s*t;
vector<int> prefix_function(string s)
{
    vector<int> a (s.length(), 0);
    for(int i = 1 ; i<s.length(); i++)
    {
        int j = a[i-1];
        while(j>0 && s[i]!= s[j])
        {
            j = a[j-1];
        }
        if(s[i] == s[j])
        {
            j++;
        }
            a[i] = j;;
    }
    return a;
} 
int32_t main(){
ios_base::sync_with_stdio(false);
   cin.tie(NULL);
ll t;
cin>>t;
while(t--){
    string s;
    cin>>s;
    vector<int> res = prefix_function(s);
 
    int pos = -1;
    string a;
    cin>>a;
    int i(0), j(0);
    while(i<a.length())
    {
        if(a[i] == s[j])
        {
            i++;
            j++;
        }
        else
        {
            if(j!= 0)
            {
                j = res[j-1]; 
            }
            else
            {
                i++;
            }
        }
            if(j == s.length())
            {
                pos = i-s.length();
                break;
            }
    }
cout<<pos<<endl;
}
}