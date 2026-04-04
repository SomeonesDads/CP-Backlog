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

void solve() {
    int n, k;
    int x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for (auto &v : a) cin >> v;
    sort(a.begin(), a.end());
    int l = 0, r = x;
    if(n == 1 && k == 1 && a[0] == 0){
        cout << x << endl; return; // I hope the future me can laugh on this
    }
    while(l+1< r){
        int count = 0;
        int m = (l+r)/2;
        count += max(0, a[0] - 0 - m + 1); 
        REP(i, n-1) count += max(0, a[i+1] - a[i] - 2*m+1); 
        count += max(0, x - a[n-1] - m + 1); 
        if(count >= k) l = m;
        else r = m;
    }
    // cout << "-> ";
    int j = 0; //cool trick to remember
    for(int i = 0; i <= a[0] - l && k;i++){
        cout << i << " ";
        k--;j++;
    }
    REP(i, n-1){
        for(j = max(j, a[i] + l); j <= min(a[i+1] - l, x) && k;j++ ){
            cout << j << " ";
            k--;
        }
    }
    for(int i = a[n-1] + l; i <= x && k;i++){
        cout << i << " ";
        k--;
    }
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
