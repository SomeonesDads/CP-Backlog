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
    int n; cin >> n;
    // vector<int> a(n);
    vector<ll> freq(1e5+1, 0);
    vector<ll> dp(1e5+1, 0);
    REP(i, n){
        int x; cin >> x;
        freq[x]++;
    }
    dp[1] = 1*freq[1];
    for(ll i = 2; i<=1e5; i++){
        dp[i] = max(dp[i-1], freq[i]*i + dp[i-2]);
    }
    cout << dp[1e5];

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
