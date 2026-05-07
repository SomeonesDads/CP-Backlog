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
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    vector<int> dp(1e5+1);
    dp[0] = 0;
    sort(a.begin(), a.end());
    int curidx = 0;
    for(int i = 1; i <= 1e5;i++){
        while (curidx < n && a[curidx] <= i) curidx++;
        dp[i] = curidx;
    }

    int q;cin >> q;
    REP(i, q){
        ll temp; cin >> temp;
        if (temp > 1e5) cout << n << endl;
        else cout << dp[temp] << endl;
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