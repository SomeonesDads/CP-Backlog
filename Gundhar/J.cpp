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

void solve()
{
    int n, m; cin >> n >> m;
    vector<ll> r(n); REP(i, n) cin >> r[i];
    vector<pair<ll,ll>> s(m); REP(i, m) cin >> s[i].first >> s[i].second;
    sort(r.begin(), r.end()); sort(s.begin(), s.end());
    vector<vector<ll>> dp(n+1, vector<ll>(m+1, 0));

    // i = robot pertama, j = kios pertama
    // DPnya nyoba nyari optimum per i, j.
    // Jadi O(N*M) bisa harusny
    for (int i = 1; i <= n; i++) { 
        for (int j = 1; j <= m; j++) {
            ll profit = s[j-1].second - abs(r[i-1] - s[j-1].first);
            profit = max((ll)0, profit); // mana tau rugi
            dp[i][j] = max({dp[i-1][j], dp[i][j-1], dp[i-1][j-1] + profit}); // 1. Robot sekarang diskip, 2. Kios j skip, 3. i sama j matching.
        }
    }

    cout << dp[n][m] << "\n";
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
