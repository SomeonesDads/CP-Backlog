#include <bits/stdc++.h>
using namespace std;
template<typename T>
void _debug(const char* name, T&& value) {
    cerr << name << " = " << value << endl;
}
template<typename T, typename... Args>
 void _debug(const char* names, T&& value, Args&&... args) {
    const char* comma = strchr(names, ',');
    cerr.write(names, comma - names) << " = " << value << " | ";
    _debug(comma + 1, args...);
}
#define debug(...) _debug(#__VA_ARGS__, __VA_ARGS__)
#define ll long long
#define REP(i,n) for(int i=0; i<n; i++)
#define RREP(i,n) for(int i=n-1; i>= 0; i--)
#define mod 1000000007

const int MAX_NODES = 400005; // Maksimal 2*N titik waktu unik
ll tree_max[4 * MAX_NODES];
ll lazy_tree[4 * MAX_NODES];

void push(int v) {
    if (lazy_tree[v] != 0) {
        tree_max[v*2] += lazy_tree[v];
        lazy_tree[v*2] += lazy_tree[v];
        tree_max[v*2+1] += lazy_tree[v];
        lazy_tree[v*2+1] += lazy_tree[v];
        lazy_tree[v] = 0;
    }
}

void update(int v, int tl, int tr, int l, int r, ll add_val) {
    if (l > r) return;
    if (l == tl && r == tr) {
        tree_max[v] += add_val;
        lazy_tree[v] += add_val;
    } 
    else{
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), add_val);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, add_val);
        tree_max[v] = max(tree_max[v*2], tree_max[v*2+1]);
    }
}

struct moment {ll l, r, k;};
void solve() {
    int n; cin >> n;
    vector<moment> moments(n);
    vector<ll> times;
    times.reserve(2*n);
        REP(i, n){
        cin >> moments[i].l >> moments[i].r >> moments[i].k;
        times.push_back(moments[i].l);
        times.push_back(moments[i].r);
    }
    sort(times.begin(), times.end());
    times.erase(unique(times.begin(), times.end()), times.end());
    sort(moments.begin(), moments.end(), [](const moment& a, const moment& b){return a.k > b.k;});
    int m = times.size();
    fill(tree_max, tree_max + 4 * (m+1), 0);
    fill(lazy_tree, lazy_tree + 4 * (m+1), 0);
    ll ans = 0;
    REP(i, n){
        int tl = lower_bound(times.begin(), times.end(), moments[i].l) - times.begin();
        int tr = lower_bound(times.begin(), times.end(), moments[i].r) - times.begin() - 1; //oala
        update(1, 0, m - 1, tl, tr, 1);
        if (i == n - 1 || moments[i+1].k != moments[i].k) {
            ll cur = tree_max[1]; 
            ans = max(ans, cur * moments[i].k);
        }
    }
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll test=1;
    //cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
