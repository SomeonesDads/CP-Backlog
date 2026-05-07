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
#define RREP(i,n) for(int i=n-1; i>=0; i--)
#define mod 1000000007

void solve() {
    int n, q; cin >> n >> q;
    vector<ll> a(n+1); REP(i,n) cin >> a[i+1];
    vector<int> freq(n+2, 0);
    REP(i, q){
        int l, r;
        cin >> l >> r; freq[l]++;
        if (r + 1 <= n) freq[r + 1]--;
    }
    for(int i=1; i<=n; i++) freq[i] += freq[i-1];
    
    ll res = 0;
    // for(int i=0; i<=n; i++) debug(freq[i]);
    sort(a.begin()+1, a.end());
    sort(freq.begin()+1, freq.begin()+n+1);
    // for(int i=0; i<=n; i++) debug(freq[i]);
    int i = 0;
    while(i<=n){
        res+=freq[i]*a[i];
        i++;
    }
    cout << res;
}

int main() {
    // ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll test = 1;
    // cin >> test;
    while(test--) {
        solve();
    }
    return 0;
}