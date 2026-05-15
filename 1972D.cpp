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
    vector<int> a(n);
    REP(i,n) cin >> a[i];
    vector<int> p(n, -1);
    for(int i = 1; i < n; i++){
        p[i] = p[i-1];
        if(a[i] != a[i-1]) p[i] = i-1;
    }
    int q; cin >> q;
    REP(i, q){
        int l, r; cin >> l >> r;
        l--;r--;
        if(l <= p[r]) cout << p[r]+1 << " " << r+1 << "\n";
        else cout << "-1 -1\n";
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll test = 1;
    cin >> test;
    while(test--) {
        solve();
        cout << "\n";
    }
    return 0;
}