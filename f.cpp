#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i=0;i<n;i++)

ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a % b);
}

void solve() {
    string s; cin >> s;
    int l, r; cin >> l >> r;
    ll p = 0, q = 1;
    bool dec = false;
    int dec_len = 0;
    for (char c : s) {
        if (c == '.') dec = true;
        else {
            p = p * 10 + (c - '0');
            if (dec) dec_len++;
        }
    }
    REP(i, dec_len) q *= 10;
    ll g = gcd(p, q);
    p /= g; q /= g;
    ll k = q;
    ll S = p; 
    if (S < 1LL*l*k || S > 1LL*r*k) {
        cout << -1 << "\n"; return;
    }
    vector<ll> ans(k, l);
    ll need = S - 1LL*l*k;
    REP(i, k) {
        ll add = min(1LL*r - l, need);
        ans[i] += add;
        need -= add;
        if (need == 0) break;
    }
    cout << k << "\n";
    REP(i, k) cout << ans[i] << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
