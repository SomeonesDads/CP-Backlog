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
#define INF 1e18

void solve() {
    int n, m; cin >> n >> m;
    vector<pair<int,int>> adj[n];
    REP(i, m){
        int a, b, c; cin >> a >> b >> c;
        adj[a-1].push_back({b-1, c});
        adj[b-1].push_back({a-1, c});
    }
    

    vector<ll> distance(n, INF);
    vector<bool> processed(n, false);
    priority_queue<pair<ll,int>> q;
    vector<int> parent(n, -1);
    distance[0] = 0;
    q.push({0,0});
    while (!q.empty()) {
        int a = q.top().second; q.pop();
        if (processed[a]) continue;
        processed[a] = true;
        for (auto u : adj[a]) {
            int b = u.first, w = u.second;
            if (distance[a]+w < distance[b]) {
                distance[b] = distance[a]+w;
                q.push({-distance[b],b});
                parent[b] = a;
            }
        }
    }

    parent[0] = 0;
    int cur = n-1;
    vector<int> path;
    path.push_back(cur+1);
    while(parent[cur] != 0 && parent[cur] != -1){
        cur = parent[cur];
        path.push_back(cur+1);
    }
    if(parent[cur] == -1){
        cout << "-1";
        return;
    }
    path.push_back(1);
    REP(i, path.size()){
        cout << path[path.size()-i-1] << " ";
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