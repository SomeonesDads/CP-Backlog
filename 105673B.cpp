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
    int n, k; cin >> n >> k;
    vector<ll> a(n); REP(i, n) cin >> a[i];
    ll ans = k;
    for(int i = 0; i < n; i++){
        int curidx = i;
        int count = 1;
        ll cursum = k;
        ll curans = cursum;
        while(curidx < n){
            cursum += a[curidx];
            if(cursum < 0) break;
            curans = max(cursum, curans);
            curidx += count;
            count++;
        }
        ans = max(curans, ans);
    }
    cout << ans << '\n';
}

int main() {
    // ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll test = 1;
    cin >> test;
    while(test--) {
        solve();
    }
    return 0;
}