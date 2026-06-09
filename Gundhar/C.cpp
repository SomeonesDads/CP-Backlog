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

ll cost(ll x, ll k, ll mid) {
    ll r_end = x + k - 1;
    if (r_end <= mid) {     // left wing liberals
        ll first_val = mid - x;
        ll last_val = mid - r_end;
        return k * (first_val + last_val) / 2;
        
    } else if (x >= mid) { // right wing republican
        ll first_val = x - mid;
        ll last_val = r_end - mid;
        return k * (first_val + last_val) / 2;
        
    } else {    // centrist
        ll len_left = mid - x + 1;
        ll sum_left = len_left * (mid - x + 0) / 2;
        ll len_right = r_end - mid;
        ll sum_right = len_right * (1 + r_end - mid) / 2;
        return sum_left + sum_right;
    }
}

void solve() {
    ll n, m, k;
    if (!(cin >> n >> m >> k)) return;
    vector<ll> seats(m);
    REP(i, m) cin >> seats[i]; 
    seats.push_back(0);
    seats.push_back(n + 1);
    sort(seats.begin(), seats.end());
    ll mid = (n + 1) / 2;
    ll ans = -1;
    ll optstart = mid - k / 2;
    for (ll i = 1; i < seats.size(); i++) {
        ll l = seats[i-1] + 1;
        ll r = seats[i] - 1;
        if (r - l + 1 >= k) {
            ll maxstart = r - k + 1;
            ll beststart = max(l, min(maxstart, optstart));
            ll cur = cost(beststart, k, mid);
            if (ans == -1 || cur < ans) ans = cur;
        }
    }
    
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll test=1;
    //cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
