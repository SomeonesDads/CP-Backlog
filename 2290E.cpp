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
    int n, k; cin >> n >> k;
    vector<ll> a(n+1); REP(i, n) cin >> a[i+1];
    vector<int> c(n + 2, 0);   
    int window = 0;            
    int total = 0;
    for (int i = n; i >= 1; i--) {
        c[i] = (a[i] + window) & 1;
        total ^= c[i];
        window ^= c[i]; 
        if (i + k <= n) window ^= c[i + k];  
    }
    cout << (total ? "Alice" : "Bob") << '\n';
}

int main() {
    // ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll test = 1;
    cin >> test;
    while(test--) {
        solve();
    }
    return 0;
}