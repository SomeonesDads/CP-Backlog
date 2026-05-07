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
    int n, m; cin >> n >> m;
    vector<int> adj[n];
    vector<bool> visited(n, false);
    vector<int> cur_cats(n);
    vector<int> cats(n);
    queue<int> q;
    q.push(0); 
    REP(i, n) cin >> cats[i];
    REP(i, n-1){
        int a, b; cin >> a >> b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cur_cats[0] = cats[0];
    visited[0] = true;
    int ans = 0;
    while (!q.empty()) {
        int s = q.front(); q.pop();
        if(adj[s].size() == 1 && s!=0){
            debug(s, cur_cats[s]);
            if(cur_cats[s] <= m) ans++;
        }
        for (auto u : adj[s]) {
            if (visited[u]) continue;
            visited[u] = true;
            if(cats[s]) cur_cats[u] = cur_cats[s] + cats[u];
            else cur_cats[u] = cats[u];
            if(cur_cats[u] <= m) q.push(u);
        }
    }
    cout << ans;
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