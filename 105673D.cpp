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
    int n; cin >> n;
    vector<ll> a(n); REP(i, n) cin >> a[i];
    vector<vector<ll>> dp(n, vector<ll>(4));
    // 0 = rest, rest
    // 1 = work, rest
    // 2 = rest, work
    // 3 = work, work;
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 4*a[0];
    dp[0][3] = 4*a[0];
    for(int i = 1; i<n; i++){
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        dp[i][1] = max(dp[i-1][2], dp[i-1][3]);
        dp[i][2] = max(dp[i-1][0] + 4*a[i], dp[i-1][1] + 3*a[i]);
        dp[i][3] = max(dp[i-1][2] + 2*a[i], dp[i-1][3] + a[i]);
    }
    cout << max(max(dp[n-1][0], dp[n-1][1]), max(dp[n-1][2], dp[n-1][3])) << '\n';
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