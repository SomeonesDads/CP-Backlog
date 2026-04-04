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
#define RREP(i,n) for(int i=n-1; i>= 0; i--)
#define mod 1000000007

ll gcd(ll a, ll b) {
    while (b) { a %= b; swap(a, b); }
    return a;
}
const int MAXV = 2000005;
bool is_divisible[MAXV + 7];
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    int max_val = 0;
    for (int &x : a) { cin >> x; max_val = max(max_val, x); }
    for (int &x : b) { cin >> x; max_val = max(max_val, x); }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    // TODO: LCM
    ll L = a[0];
    for (int i = 1; i < a.size(); ++i) {
        debug(i, L);
        L = (L / gcd(L, (ll)a[i])) * a[i];
        if (L > max_val) { L = max_val + 1; break; }
    }
    // TODO: Sieve
    vector<int> changed;
    for (int x : a) {
        for (int j = x; j <= max_val; j += x) {
            if (!is_divisible[j]) {
                is_divisible[j] = true;
                changed.push_back(j);
            }
        }
    }
    ll NA = 0, NB = 0, NBoth = 0;
    for (int y : b) {
        if (y % L == 0) NA++;
        else if (!is_divisible[y]) NB++;
        else NBoth++;
    }
    // buat next
    for (int j : changed) is_divisible[j] = false;
    bool alice = (NBoth % 2 == 0) ? (NA > NB) : (NA >= NB);
    cout << (alice ? "Alice" : "Bob") << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll test=1;
    cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
