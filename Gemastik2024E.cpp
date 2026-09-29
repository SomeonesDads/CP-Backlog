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

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n); REP(i, n) cin >> a[i];
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(45, 0)));

    // pref[x][len] = dp[0][i][len] + dp[1][i][len] + ... + dp[x][i][len] (i < x)
    vector<vector<int>> pref(n,vector<int>(45, 0));

    ll ans = 0;
    REP(i, n) {
        // isi pref
        REP(x, i) {
            for (int len = 2; len < 45; len++) {
                pref[x][len] = dp[x][i][len];
                if (x > 0) pref[x][len] += pref[x - 1][len];
            }
        }

        for (int j = i + 1; j < n; j++) {
            dp[i][j][2] = 1;
            ll before = a[j] - a[i];

            // a[bin] <= before (bin is largest)
            int bin = int(upper_bound(a.begin(), a.begin() + i, before) - a.begin()) - 1;
            if (bin >= 0) for (int len = 3; len < 45; len++)  dp[i][j][len] = pref[bin][len - 1];

            for (int len = k; len < 45; len++) {
                ans += dp[i][j][len];
            }
        }
    }

    cout << ans << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll test = 1;
    // cin >> test;
    while (test--) {
        solve();
    }

    return 0;
}