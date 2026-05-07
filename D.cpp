#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i=0; i<n; i++)
#define INF 1e18
vector<vector<pair<int,ll>>> adj;

void dijkstra(int s, vector<ll> &d, vector<int> &p) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    using pll = pair<ll, int>; 
    priority_queue<pll, vector<pll>, greater<pll>> q;
    q.push({0, s});
    while (!q.empty()) {
        int v = q.top().second;
        ll d_v = q.top().first;
        q.pop();
        if (d_v != d[v]) 
            continue;

        for (auto edge : adj[v]) {
            int to = edge.first;
            ll len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    adj.assign(n + 1, {});
    vector<tuple<int,int,ll>> edges;
    REP(i,m) {
        int u, v; ll w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        edges.push_back({u, v, w});
    }
    vector<ll> d1, d2, d3;
    vector<int> p;
    dijkstra(1, d1, p);
    dijkstra(2, d2, p);
    dijkstra(3, d3, p);
    ll ans = d1[2] + d3[2];
    for (auto [u, v, w] : edges) {
        ll c1 = d1[u] + d3[u] + w + (w + 1) / 2 + 2 * d2[v];
        ll c2 = d1[v] + d3[v] + w + (w + 1) / 2 + 2 * d2[u];
        ans = min(ans, min(c1, c2));
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int test = 1;
    // cin >> test;
    while (test--){
        solve();
    }
    return 0;
}