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

bool cek(ll n, ll s, ll m) {
    ll low = 0, high = 0; 
    REP(i, 65) {
        int si = (s >> i) & 1;
        int mi = (m >> i) & 1;
        ll min_val = low;
        ll max_val = high + (mi ? n : 0);
        if (min_val % 2 != si) min_val++;
        if (max_val % 2 != si) max_val--;
        if (min_val > max_val) return false;
        low = (min_val - si) / 2;
        high = (max_val - si) / 2;
    }
    return (low == 0);
}

void solve() {
    ll s, m; cin >> s >> m;
    ll lsb_m = m & -m;
    if (s % lsb_m != 0) {
        cout << -1 << "\n";
        return;
    }
    ll left = 1, right = s, ans = s;
    while (left <= right) { 
        ll mid = left + (right - left) / 2;
        if (cek(mid, s, m)) {
            ans = mid;
            right = mid - 1;
        } 
        else left = mid + 1;
    }
    cout << ans << "\n";
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
