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
    int n, k; cin >> n >> k;
    vector<int> freq(n+1, 0);
    REP(i, n){
        int temp; cin >> temp;
        freq[temp]++;
    }
    vector<int> pref(n+1); 
    pref[0] = freq[0];
    for(int i = 1; i < n+1; i++) pref[i] = pref[i-1] + freq[i];
    int ans = 1;
    REP(i, n+1){
        if(!i) continue;
        int divisable = freq[i];
        if(i*4 <= n) divisable += pref[n] - pref[i*4] + freq[i*4];
        if(i*3 <= n) divisable += freq[i*3];
        if(i*2 <= n) divisable += freq[i*2];
        // debug(i, divisable);
        if(divisable >= n-k) ans = i;
    }
    cout << ans << endl;
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
