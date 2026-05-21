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
#define REP(i,n) for(ll i=0; i<n; i++)
#define RREP(i,n) for(ll i=n-1; i>=0; i--)
#define mod 1000000007

vector<ll> seg;
ll n, m;

void build(ll node, ll l, ll r, bool is_or, vector<ll>& a){
    if(l == r){
        seg[node] = a[l];
        return;
    }
    ll mid = (l + r) / 2;
    build(2*node, l, mid, !is_or, a);
    build(2*node+1, mid+1, r, !is_or, a);
    if(is_or) seg[node] = seg[2*node] | seg[2*node+1];
    else seg[node] = seg[2*node] ^ seg[2*node+1];
}

void update(ll node, ll l, ll r, ll pos, ll val, bool is_or){
    if(l == r){
        seg[node] = val;
        return;
    }
    ll mid = (l + r) / 2;
    if(pos <= mid) update(2*node, l, mid, pos, val, !is_or);
    else update(2*node+1, mid+1, r, pos, val, !is_or);
    if(is_or) seg[node] = seg[2*node] | seg[2*node+1];
    else seg[node] = seg[2*node] ^ seg[2*node+1];
}

ll query(){return seg[1];}

void solve() {
    cin >> n >> m;
    ll size = (1 << n);
    vector<ll> a(size);
    REP(i, size) cin >> a[i];
    seg.resize(4 * size);
    bool is_or = (n % 2 == 1);

    build(1, 0, size-1, is_or, a);

    while(m--){
        ll p, b;
        cin >> p >> b;
        p--; 
        a[p] = b;
        update(1, 0, size-1, p, b, is_or);
        cout << query() << '\n'; 
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll test = 1;
    // cin >> test;
    while(test--) {
        solve();
    }
    return 0;
}