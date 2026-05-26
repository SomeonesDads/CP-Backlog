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
    vector<int> steps; int count = 0;
    RREP(i, n){
        if(a[i]*(pow((-1), (count))) > 0){
            steps.push_back(i);
            count++;
        }
    }
    cout << count << "\n";
    if(steps.size()!=0){
    REP(i, steps.size()-1){
        cout << steps[i]+1 << " ";
    }
    cout << steps[steps.size()-1]+1;
    }
    cout << "\n";

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