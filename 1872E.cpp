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
    ll xor0 = 0;
    ll xor1 = 0;
    vector<ll> a(n); REP(i, n)
    {
        cin >> a[i];
    }
    string s; cin >> s;
    REP(i, n){
        if(s[i] == '1') xor1 ^= a[i];
        else xor0 ^= a[i];
    }
    vector<ll> pref(n);
    pref[0] = a[0];
    for(int i = 1; i < n; i++) pref[i] = a[i] ^ pref[i-1];
    int q; cin >> q;
    while(q--){
        int op; cin >> op;
        if(op == 2){
            int num; cin >> num;
            if(num) cout << xor1 << ' ';
            else cout << xor0 << ' ';
        }
        else{
            int l, r; cin >> l >> r; l--; r--;
            if(l == 0){
                xor1 ^= pref[r];
                xor0 ^= pref[r];
            }
            else{
                xor1 ^= (pref[r] ^ pref[l-1]);
                xor0 ^= (pref[r] ^ pref[l-1]);
            }

        }
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