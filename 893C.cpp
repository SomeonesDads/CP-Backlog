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
    int n, m; cin >> n >> m;
    vector<int> cost(n+1);
    REP(i,n) cin >> cost[i+1];

    vector<int> adj[n+1];
    REP(i, m){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ll res = 0;
    // for(int i = 1; i <= n; i++) res += cost[i];  
    
    vector<int> visited(n+1,false);
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            queue<int> q;
            visited[i] = true;
            q.push(i);
            int minl = cost[i];

            while(!q.empty()){
                int u = q.front(); q.pop();
                minl = min(cost[u], minl);
                for(auto v: adj[u]){
                    if(!visited[v]) q.push(v);
                    visited[v] = true;
                }
            }
            res += minl;
        }
    }
    
    cout << res;
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
