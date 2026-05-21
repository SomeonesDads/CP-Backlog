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

// Harusnya bisa lebih kencang, cuma malas kali kutambah2i edge case gajelas
// void solve() {
//     int n, q; cin >> n >> q;
//     vector<vector<int>> c(51, vector<int>{-1,-1});
//     for(int i = 1; i <= n; i++){
//         int color; cin >> color;
//         if(c[color][0] == -1) c[color][0] = i;
//     }
//     REP(i, 51) debug(i, c[i][0], c[i][1]);
//     REP(i, q){
//         int query; cin >> query;
//         if(c[query][1] == -1) cout << c[query][0] + i << "\n";
//         else cout << i - c[query][1] << "\n";
//         c[query][1] = i;
//     }
// }

void solve() {
    int n, q; cin >> n >> q;
    vector<int> pos(51, -1);
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        if(pos[x] == -1) pos[x] = i;
    }

    while(q--){
        int t; cin >> t;
        cout << pos[t] << " ";
        int old = pos[t];
        for(int c = 1; c <= 50; c++) if(pos[c] < old) pos[c]++;
        pos[t] = 1;
    }
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