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

void solve()
{
    int n; cin >> n;
    vector<ll> a(n);    
    vector<ll> c(n);
    REP(i, n) cin >> a[i];
    REP(i, n) cin >> c[i];
    vector<ll> acopy = a;
    sort(acopy.begin(), acopy.end());
    acopy.erase(unique(acopy.begin(), acopy.end()), acopy.end());
    vector<ll> prev(acopy.size(), 0), cur(acopy.size());
    REP(i, acopy.size()) prev[i] = (a[0] != acopy[i] ? c[0] : 0);
    int len = acopy.size();

    for(int i = 1; i < n; i++){
        vector<ll> pref(len);
        pref[0] = prev[0];
        for (int j = 1; j < len; j++)
            pref[j] = min(pref[j-1], prev[j]);
        REP(j, len){
            ll cost = (a[i] != acopy[j] ? c[i] : 0);
            cur[j] = pref[j] + cost;
        }
        swap(cur, prev);
        // debug(cur, prev);
    }
    cout << *min_element(prev.begin(), prev.end()) << "\n";
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
