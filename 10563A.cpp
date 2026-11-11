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
    vector<ll> a(n);
    REP(i, n) cin >> a[i];
    sort(a.rbegin(), a.rend());
    ll ans1 = -1;
    int count = 1; ll cur = a[0];
    for(int i = 1; i < n; i++){
        if(a[i] == cur) count++;
        else{
            cur = a[i];
            count = 1;
        }
        if(count == 4){
            ans1 = cur*cur;
            break;
        }
    }
    count = 1; cur = a[0]; ll cur2 = -1;
    for(int i = 1; i < n; i++){
        if(a[i] == cur){
            for(int j = i+1; j < n-1; j++){
                if(a[j+1] == a[j] && a[j] != cur){
                    cur2 = a[j];
                    break;
                }
            }
            break;
        }
        cur = a[i];
    }
    // debug(cur, cur2);
    ll ans2 = -1;
    if(cur2 != -1) ans2 = cur*cur2;
    cout << ans1 << ' ' << ans2 << '\n';
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