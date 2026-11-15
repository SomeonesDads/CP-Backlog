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
    int n, q; cin >> n >> q;
    vector<int> a(n); REP(i,n) cin >> a[i];
    vector<vector<int>> pref(n+1, vector<int>(4));
    pref[0][1] = 0;
    pref[0][2] = 0;
    pref[0][3] = 0;
    for(int i = 1; i <= n; i++){
        pref[i][1] = pref[i-1][1];
        pref[i][2] = pref[i-1][2];
        pref[i][3] = pref[i-1][3];
        pref[i][a[i-1]]++;
    }

    while(q--){
        int a, b; cin >> a >> b;
        cout << pref[b][1] - pref[a-1][1] << ' ' << pref[b][2] - pref[a-1][2] << ' ' << pref[b][3] - pref[a-1][3] << '\n';
    }

}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    ll test = 1;
    // cin >> test;
    while(test--) {
        solve();
    }
    return 0;
}