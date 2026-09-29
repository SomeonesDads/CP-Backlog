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
    int score = 0;
    bool cur = false; // 0 = friend, 1 = me
    int streak = 1;
    if(a[0] == 1) score++;
    for(int i = 1; i < n; i++){
        if(streak == 2){
            streak = 1;
            cur = !cur;
            if(!cur) score += a[i];
            // debug(cur, streak, a[i]);
            continue;
        }

        if(a[i] == 0){
            if(!cur) streak++;
            else if(cur) cur = !cur;
        }

        if(a[i] == 1){
            if(!cur) cur = !cur;
            else if(cur) streak++;
        }    // debug(cur, streak);
    }
    cout << score << '\n';
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