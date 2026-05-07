#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i = 0;i<n;i++)

void solve() {
    int n;
    cin >> n;
    int m= 100001;
    vector<ll> sum(m, 0);

    REP(i,n){
        int temp;
        cin >> temp;
        sum[temp] += temp;
    }

    vector<ll> dp(m, 0);
    dp[1] = sum[1];
    for (int i = 2; i < m; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + sum[i]);
    }

    cout << dp[m - 1] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    // cin >> test;
    while(test--){
       solve();
    }
    return 0;
}