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
    vector<int> a(n+1); REP(i, n) cin >> a[i+1];
    vector<int> dp(n+1, 1);
    for(int i = 1; i <= n; i++){
        for(int j = i*2; j <= n; j+=i){
            if(a[j] > a[i]) dp[j] = max(dp[j], dp[i]+1);
        }
    }
    int ans = dp[0];
    for(int i = 1; i <= n; i++){
        if(dp[i] > ans) debug(i, dp[i]);
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';

}
// 2D, got MLE
// void solve() {
//     int n; cin >> n;
//     vector<int> a(n+1); REP(i, n) cin >> a[i+1];
//     vector<vector<int>> dp(n+1, vector<int>(n+1, 1));
//     int ans = 0;
//     for(int i = 1; i <= n; i++){
//         int check = 1; 
//         for(int j = 0; j <= n; j++) if(dp[i][check] < dp[i][j]) check = j;
//         for(int j = i*2; j <= n; j+=i){
//             if(a[j] > a[i]) dp[j][i] += dp[i][check];
//         }
//         ans = max(ans, dp[i][check]);
//     }
//     // for(int i = 1; i<= n; i++){
//     //     for(int )
//     // }
//     cout << ans << '\n';

// }
int main() {
    // ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll test = 1;
    cin >> test;
    while(test--) {
        solve();
    }
    return 0;
}