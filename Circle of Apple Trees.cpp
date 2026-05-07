#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i = 0;i<n;i++)

int lis_length(const vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1);
    REP(i, n) {
        REP(j, i) {
            if(arr[i] > arr[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    return *max_element(dp.begin(), dp.end());
}

void solve() {
    int n;
    cin >> n;
    vector<int> b(n);
    REP(i, n) cin >> b[i];
    vector<int> b2(2 * n);
    REP(i, n) b2[i] = b2[i + n] = b[i]; 
    int ans = 0;
    REP(start, n) {
        vector<int> sub(b2.begin() + start, b2.begin() + start + n);
        ans = max(ans, lis_length(sub));
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    cin >> test;
    while(test--){
       solve();
    }
    return 0;
}
