#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if(!(cin>>n))return 0;
    vector<long long> a(n);
    long long S=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        S+=a[i];
    }
    long long k,d;
    cin>>k>>d;

    // Precompute candidate L's = all a[i] and a[i]-(d-1)
    vector<long long> cand;
    cand.reserve(2*n+2);
    for(int i=0;i<n;i++){
        cand.push_back(a[i]);
        cand.push_back(a[i] - (d-1));
    }
    // Also it's only meaningful L where n*L <= S <= n*(L+d-1).
    // We'll check that later.
    sort(cand.begin(), cand.end());
    cand.erase(unique(cand.begin(), cand.end()), cand.end());

    long long ans = LLONG_MAX;
    for(long long L : cand){
        // Check feasibility: total sum S must lie in [n*L, n*(L+d-1)]
        // i.e. n*L <= S <= n*(L+d-1)
        if(L > LLONG_MAX/d) continue; // avoid overflow
        if(n*L > S) continue;
        if(n*(L + d - 1) < S) continue;

        // Compute posSum = sum_{a[i]<L}(L - a[i])
        //         negSum = sum_{a[i]>L+d-1}(a[i] - (L+d-1))
        long long posSum = 0, negSum = 0;
        for(int i=0;i<n;i++){
            if(a[i] < L) posSum += (L - a[i]);
            else if(a[i] > L + d - 1) negSum += (a[i] - (L + d - 1));
        }
        // The actual amount that must move is the smaller of the two
        long long M = min(posSum, negSum);
        // ceil(M/k):
        long long ops = (M + k - 1) / k;
        ans = min(ans, ops);
    }

    // If already within d, cand will include some L that makes M=0 => ans=0
    cout << ans << "\n";
    return 0;
} 
// convert this code in this function 