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
    vector<int> depth(n+1); 
    depth[1] = 0;
    int min_d = 1e6;
    int temp;   
    for(int i = 2; i <= n; i++){ cin >> temp; depth[i] = depth[temp]+1;}
    int m; cin >> m;
    vector<int> dam(m); REP(i, m){ cin >> dam[i]; min_d = min(min_d, depth[dam[i]]);}
    
    bool has_skipped = false;
    cout << m - 1 << " ";
    REP(i, m){
        // debug(has_skipped, i, depth[dam[i]]);
        if (!has_skipped && depth[dam[i]] == min_d) has_skipped = true;
        else cout << dam[i] << " ";
    }
    cout << '\n';
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