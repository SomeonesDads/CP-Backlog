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
    int n, k;
    cin >> n >> k;
    if(k<n || k>(n+ceil((double)n/2))){
        cout << "NO\n";
        // debug(n+ceil((double)n/2));
    }
    else{
        cout << "YES\n";
        int shift = k-n;
        int end = 1;
        if(shift >= 1) end++;
        if(shift >= 2){
            end++;
            end += (shift-2)*2;
        }
        // debug(end, n);
        for(int i = 1; i <= end; i++) cout << i << " ";
        for(int i = 1; i <= end; i++) cout << i << " ";
        for(int i = end+1; i <= n; i++) cout << i << " " << i << " ";
        cout << "\n";
    }
}

int main() {
    // ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll test = 1;
    cin >> test;
    while(test--) {
        solve();
    }
    return 0;
}