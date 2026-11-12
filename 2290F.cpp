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
    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++) cin >> c[i];
    vector<int> prm(n + 1, 0);
    bool bs = true;
    for (int x = 1; x <= n && bs; x++) {
        long long pos = (long long)n + 1 - x + c[x];
        if (pos < 1 || pos > n || prm[pos] != 0) bs = false;
        else prm[pos] = x;
    }
    if (bs) {
        vector<int> bit(n + 1, 0);
        auto add = [&](int i) { for (; i <= n; i += i & -i) bit[i]++; };
        auto qry = [&](int i) { int s = 0; for (; i > 0; i -= i & -i) s += bit[i]; return s; };

        for (int pos = 1; pos <= n && bs; pos++) {
            int x = prm[pos];
            int Ls = qry(x - 1);
            int Lg = (pos - 1) - Ls;
            int Rg = (n - x) - Lg;
            if (Ls - Rg != c[x]) bs = false;
            add(x);
        }
    }
    if (!bs) cout << -1 << '\n';
    else {
        for (int i = 1; i <= n; i++) cout << prm[i] << ' ';
        cout << '\n';
    }
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