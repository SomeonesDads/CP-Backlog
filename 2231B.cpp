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
    REP(i, n) cin >> a[i];
    ll plus = 0;
    REP(i, n - 1) {
        if (a[i] > a[i + 1]) {
            plus = max(plus, a[i] - a[i + 1]);
        }
    }
    if (plus == 0) {
        cout << "YES\n";
        return;
    }
   
    ll base = a[0]; 
    bool can = true;
    for(int i = 1; i < n; i++) {
        if (a[i] >= base) {
            base = a[i];
        } 
        else if (a[i] + plus >= base) {
            base = a[i] + plus;
        } 
        else {
            can = false;
            break;
        }
    }
    
    cout << (can ? "YES" : "NO") << "\n";
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
