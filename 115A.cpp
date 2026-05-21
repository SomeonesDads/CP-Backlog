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



int calcdepth(vector<vector<int>> &emp, int root, int depth){
    if(emp[root].size() == 0){
        return depth + 1;
    }
    int maxdepth = depth;
    for(int i = 0; i < emp[root].size(); i++){
        maxdepth = max(maxdepth, calcdepth(emp, emp[root][i], depth+1));
    }
    return maxdepth;
}
void solve() {
    int n; cin >> n;
    vector<vector<int>> emp(n+1);
    REP(i, n){
        int p; cin >> p;
        p = max(0, p);
        emp[p].push_back(i+1);
    }
    // REP(i, n) REP(j, emp[i].size()) debug(i, j, emp[i][j]);
    int ans = calcdepth(emp, 0, 0) - 1;
    cout << ans;

    
}

int main() {
    // ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll test = 1;
    // cin >> test;
    while(test--) {
        solve();
    }
    return 0;
}