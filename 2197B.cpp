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
    vector<int> p(n); REP(i, n) cin >> p[i];
    vector<int> a(n); REP(i, n) cin >> a[i];
    vector<int> pos(n+1);
    REP(i, n) pos[p[i]] = i;
    vector<int> press;
    vector<int> visited(n+1, false);
    int cur = -1;
    REP(i, n){
        if (cur!=a[i]){
            if(visited[a[i]]){
                cout << "NO\n"; return;
            }
            cur = a[i];
            press.push_back(a[i]);
            visited[a[i]] = true;
        }
    }
    REP(i, press.size()-1){
        if(pos[press[i]] > pos[press[i+1]]){
            cout << "NO\n"; return;
        }
    }
    cout << "YES\n";
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
