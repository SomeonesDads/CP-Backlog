#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i = 0;i<n;i++)

void solve() {
    int n, a, b, c; cin >> n >> a >> b >> c;
    const int NEG = -1e9;
    vector<int> dp(n+1, NEG);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        if(i-a>=0 && dp[i-a]!=NEG) dp[i]=max(dp[i], dp[i-a]+1);
        if(i-b>=0 && dp[i-b]!=NEG) dp[i]=max(dp[i], dp[i-b]+1);
        if(i-c>=0 && dp[i-c]!=NEG) dp[i]=max(dp[i], dp[i-c]+1);
    }
    cout<<dp[n]<<"\n";
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