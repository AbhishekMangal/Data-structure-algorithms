#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 3e5 + 8;
#define rep(i, a, n) for (int i = a; i < n; i++)
#define ll long long
#define int long long

int a[N], T[4 * N];
vector<int> lazy(4 * N, 0);
vector<int> no(4 * N, -1);

void build(int node, int st, int en) {
    if (st == en) {
        T[node] = a[st];
        lazy[node] = 0;
        return;
    }
    int mid = (st + en) / 2;
    build(2 * node, st, mid);
    build(2 * node + 1, mid + 1, en);
    T[node] = T[2 * node] + T[2 * node + 1];
}

void propagate(int node, int st, int en) {
    if (no[node] != -1) {
        T[node] = (no[node] + lazy[node]) * (en - st + 1);
        if (st != en) {
            lazy[2 * node] = lazy[node];
            lazy[2 * node + 1] = lazy[node];
            no[2 * node] = no[node];
            no[2 * node + 1] = no[node];
        }
        no[node] = -1;
        lazy[node] = 0;
    } else {
        T[node] += (en - st + 1) * lazy[node];
        if (st != en) {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void range_update_inc(int node, int st, int en, int l, int r, int value) {
    propagate(node, st, en);
    if (st > r || en < l) return;
    if (st >= l && en <= r) {
        lazy[node] += value;
        propagate(node, st, en);
        return;
    }
    int mid = (st + en) / 2;
    range_update_inc(2 * node, st, mid, l, r, value);
    range_update_inc(2 * node + 1, mid + 1, en, l, r, value);
    T[node] = T[2 * node] + T[2 * node + 1];
}

void range_update_set(int node, int st, int en, int l, int r, int value) {
    propagate(node, st, en);
    if (st > r || en < l) return;
    if (st >= l && en <= r) {
        no[node] = value;
        lazy[node] = 0;
        propagate(node, st, en);
        return;
    }
    int mid = (st + en) / 2;
    range_update_set(2 * node, st, mid, l, r, value);
    range_update_set(2 * node + 1, mid + 1, en, l, r, value);
    T[node] = T[2 * node] + T[2 * node + 1];
}

int query_sum(int node, int st, int en, int l, int r) {
    propagate(node, st, en);
    if (r < st || l > en) return 0;
    if (st >= l && en <= r) {
        return T[node];
    }
    int mid = (st + en) / 2;
    int x = query_sum(2 * node, st, mid, l, r);
    int y = query_sum(2 * node + 1, mid + 1, en, l, r);
    return x + y;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    // cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        rep(i, 0, n) {
            cin >> a[i];
        }
        build(1, 0, n - 1);

        while (m--) {
            int type, a, b;
            cin >> type >> a >> b;
            if (type == 1) {
                int c;
                cin >> c;
                range_update_inc(1, 0, n - 1, a - 1, b - 1, c);
            } else if (type == 2) {
                int c;
                cin >> c;
                range_update_set(1, 0, n - 1, a - 1, b - 1, c);
            } else {
                cout << query_sum(1, 0, n - 1, a - 1, b - 1) << endl;
            }
        }
    }
}