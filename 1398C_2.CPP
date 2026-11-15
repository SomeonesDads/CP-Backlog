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
    int n; cin >> n; string s; cin >> s;
    vector<int> a(n);
    REP(i, n) a[i] = s[i] - '0';
    vector<ll> pref(n+1);
    pref[0] = 0;
    for(int i = 1; i <= n; i ++) pref[i] = pref[i-1] + a[i-1];
    vector<ll> dots(n);

    // pref[r] - pref[l] = r - l;
    // pref[r] - r = pref[l] - l;
    map<ll, ll> freq;
    for(int i = 0; i <= n; i++){
        freq[pref[i] - i]++;
    }
    ll ans = 0;
    for(auto&[k, v] : freq){
        ans += v*(v-1)/2;
        debug(k, v);
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