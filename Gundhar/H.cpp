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

const ll MINLL = -1e17;

void solve() 
{
    int n; ll m, w, l; cin >> n >> m >> w >> l;
    vector<ll> o(n+1); for (int i = 1; i <= n; i++) cin >> o[i];
    vector<vector<ll>> dp(n+1, vector<ll>(n+1, MINLL));
    dp[0][0] = m;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if (dp[i-1][j] != MINLL) dp[i][j] = max(dp[i][j], dp[i-1][j] + l); // Eco
            if (j > 0 && dp[i-1][j-1] >= o[i]) dp[i][j] = max(dp[i][j], dp[i-1][j-1] - o[i] + w); // Full buy
        }
    }
    int ans = 0;
    REP(i, n+1) if (dp[n][i] >= 0) ans = i;
    cout << ans;
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
