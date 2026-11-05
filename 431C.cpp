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

ll find(int n, int K) {
    vector<ll> f(n + 1, 0);
    f[0] = 1;
    for (int m = 1; m <= n; m++) {
        for (int j = 1; j <= min(K, m); j++) {
            f[m] = (f[m] + f[m - j]) % mod;
        }
    }
    return f[n];
}

void solve() {
    int n, k, d; cin >> n >> k >> d;
    cout << (((find(n, k) - find(n, d-1)) % mod + mod) % mod);
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