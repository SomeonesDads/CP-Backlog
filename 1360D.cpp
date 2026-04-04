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
    long long n, k;
    cin >> n >> k;
    if (k >= n) {
        cout << 1 << '\n';
        return;
    }
    long long ans = n; 
    for (long long d = 1; d * d <= n; ++d) {
        if (n % d == 0) {
            long long d2 = n / d; 
            if (d <= k) ans = min(ans, n / d);
            if (d2 <= k) ans = min(ans, n / d2);
        }
    }
    cout << ans << '\n';
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
