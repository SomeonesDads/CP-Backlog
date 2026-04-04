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
    vector<ll> a(2*n);
    REP(i, 2*n) cin >> a[i];

    ll sum = 0; 
    vector<ll> ans(n+1);
    for(int i = 0; i<2*n; i+=2){
        ans[1] += a[i+1] - a[i];
    }
    if(n > 1){
        for(int i =1; i<2*n-1;i+=2){
            ans[2] += a[i+1] - a[i];
        }
        ans[2] += a[2*n-1] - a[0];
    }
    for(int i = 3; i<=n; i++){
        // debug((a[2*n-i+2] - a[i-3]), (a[2*n-i+1] - a[i-2]));
        // debug((a[i-2] - a[i-3]), (a[2*n-i+2] - a[2*n-i+1]));
        ll firstloop = (a[2*n-i+2] - a[i-3]) - (a[i-2] - a[i-3]) - (a[2*n-i+2] - a[2*n-i+1]);
        ll secondloop = (a[2*n-i+1] - a[i-2]);
        // debug(firstloop, secondloop);
        ans[i] = ans[i-2] + firstloop + secondloop;
        // debug(ans[i-2]);
    }
    REP(i, n) cout << ans[i+1] << " ";
    cout << endl;
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
