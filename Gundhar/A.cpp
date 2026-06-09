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
#define MAXLL 2e18

void solve()
{
    int n; ll k; cin >> n >> k;
    vector<pair<ll, ll>> asrama(n);
    ll tot = 0;
    REP(i,n){
        cin >> asrama[i].first >> asrama[i].second;
        tot += asrama[i].second;
    }
    if (tot < k) { cout << -1 << "\n"; return;}
    sort(asrama.begin(), asrama.end());
    ll ans = MAXLL; 
    ll cur = 0;
    int l = 0;
    REP(r,n) {
        cur += asrama[r].second;
        while (cur >= k) {
            ll dist = asrama[r].first - asrama[l].first;
            ll r_needed = (dist + 1) / 2; 
            if (r_needed < ans) ans = r_needed;
            cur -= asrama[l].second;
            l++;
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
