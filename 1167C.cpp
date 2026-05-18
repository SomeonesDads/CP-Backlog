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

vector<int> parent(1e6, -1);
vector<int> sza(1e6, 0);

void make_set(int a){
    parent[a] = a;
    sza[a] = 1;
}

int find_set(int a){
    if(a != parent[a]) return parent[a] = find_set(parent[a]);
    else return a;
}

void merge(int a, int b){
    int a1 = find_set(a);
    int b1 = find_set(b);
    if(a1==b1) return;
    if(sza[a1]<sza[b1]) swap(a1,b1);
    parent[b1] = a1;
    sza[a1] += sza[b1];
}

void solve() {
    int n, m; cin >> n >> m;
    REP(i, n+1) make_set(i);
    REP(i, m){
        int k; cin >> k;
        vector<int> group(k);
        
        REP(j,k) cin >> group[j];
        REP(j, k){
            int x = group[j];
            // debug(j);
            if(j != 0) merge(group[j-1], x);
        }
    }
    for(int i = 1; i <= n; i++){
        cout << sza[find_set(i)] << " ";
    }
}

int main() {
    // ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll test = 1;
    // cin >> test;
    while(test--) {
        solve();
    }
    return 0;
}