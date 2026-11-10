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
    vector<ll> a(n);
    ll comp = 0;
    REP(i, n){
        cin >> a[i];
        comp += a[i];
    }
    ll comp2 = a[0];
    vector<pair<ll, int>> dp(n);
    dp[0].first = a[0];
    dp[0].second = 0;
    for(int i = 1; i < n; i++){
        if((dp[i-1].first + a[i]) > a[i]){
            dp[i].first = dp[i-1].first + a[i];
            dp[i].second = dp[i-1].second;
        }
        else{
            dp[i].first = a[i];
            dp[i].second = i;
        }
        if(dp[i].first > comp2){
            if(i == n-1 && dp[i].second == 0){
                comp2 = max(max((dp[n-1].first - a[n-1]), (dp[n-1].first - a[0])), comp2);
            }
            else{
                comp2 = dp[i].first;
            }
        }
    }
    debug(comp, comp2);
    cout << (comp > comp2 ? "YES\n" : "NO\n");
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll test = 1;
    cin >> test;
    while(test--) {
        solve();
    }
    return 0;
}