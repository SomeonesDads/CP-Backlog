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

int n;
bool rec(int lim, int cur){
    if(cur>lim || cur>n) return false;

    if(cur!=0){
        if (n % cur == 0) return true;
    }
    return rec(lim, cur*10 + 4) || rec(lim, cur*10 + 7);
}
void solve() {
    cin >> n;
    bool ans = rec(1000, 0);
    if(ans) cout << "YES";
    else cout << "NO";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll test = 1;
    // cin >> test;
    while(test--) {
        solve();
    }
    return 0;
}