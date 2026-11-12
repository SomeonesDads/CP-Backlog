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
    vector<int> a(n); REP(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    int ans = 0;
    map<int, int> freq;
    for(int i = 0; i < n; i++){
        freq[a[i]]++;
        if(freq[a[i]] <= 2) ans++;
    }

    cout << ans << '\n';
    map<int, int> printed;
    for(int i = 0; i < n; i++){
        if(!printed[a[i]]){
            printed[a[i]]++;
            cout << a[i] << ' ';
        }
    }
    map<int, int> skipped;
    for(int i = n-1; i >= 0; i--){
        if(skipped[a[i]]){
            cout << a[i] << ' ';
        }
        else{
            skipped[a[i]]++;
        }
    }
    cout << '\n';
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