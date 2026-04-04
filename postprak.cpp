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

void subset(int cur_idx, int len, vector<int> sets, vector<int> built){
    if(len == 0){
        cout << "[";
        REP(i, built.size()){
            if(i != built.size()-1) cout << built[i] << " ";
            else cout << built[i];
        }
        cout << "]\n";
    }
    else{
        built.push_back(sets[cur_idx]);
        for(int i = cur_idx+1; i < sets.size(); i++){
            if(sets.size()-i >= len){
                subset(i, len-1, sets, built);
            }
        }
    }
}
void solve()
{
    int n; cin >> n;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    subset(0, 1, a, {});
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll test=1;
    //cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
