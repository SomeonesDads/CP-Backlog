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
    
    vector<ll> a(n+1); REP(i, n) cin >> a[i+1];
    vector<bool> explored(n+1, false);
    ll maxl = 0;
    REP(i, n){
        ll temp = 0;
        int index = i+1;
        if(!explored[i+1]){
            while(index <= n && !explored[index]){
                temp += a[index];
                explored[index] = true;
                index += a[index];
            }
        }
        maxl = max(maxl, temp);
    }
    cout << maxl << endl;
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
