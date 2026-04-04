#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

void solve() {
    int n; cin >> n;
    vector<ll> a(n), c(n);
    for (auto &x : a) cin >> x;
    for (auto &x : c) cin >> x;

    vector<ll> b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    int m = b.size();

    vector<ll> prev(m, 0), cur(m);
    for (int j = 0; j < m; j++)
        prev[j] = (a[0] != b[j] ? c[0] : 0);

    for (int i = 1; i < n; i++) {
        vector<ll> pref(m);
        pref[0] = prev[0];
        for (int j = 1; j < m; j++)
            pref[j] = min(pref[j-1], prev[j]);

        for (int j = 0; j < m; j++) {
            ll cost = (a[i] != b[j] ? c[i] : 0);
            cur[j] = pref[j] + cost;
        }
        swap(cur, prev);
    }

    cout << *min_element(prev.begin(), prev.end()) << "\n";
}

int main() {
// ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}
