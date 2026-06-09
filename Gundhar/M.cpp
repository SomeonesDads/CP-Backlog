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

const ll MAXLL = 1e18;

struct edge {
    int to;
    int stability;
    ll cost;
};

int n, m;
vector<vector<edge>> adj;

pair<bool, ll> dijkstra(int min_stab) {     //standarla dijkstra
    vector<ll> dist(n + 1, MAXLL);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
    dist[1] = 0;
    pq.push({0, 1});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto &e : adj[u]) {
            if (e.stability < min_stab) continue;
            if (dist[e.to] > d + e.cost) {
                dist[e.to] = d + e.cost;
                pq.push({dist[e.to], e.to});
            }
        }
    }
    if (dist[n] == MAXLL) return {false, MAXLL};
    return {true, dist[n]};
}

void solve() // ini ga sengaja atau sengaja bocor
{
    cin >> n >> m; adj.resize(n + 1);
    int u, v, s; ll t;
    int maxsec = 0;
    REP(i, m) {
        cin >> u >> v >> s >> t;
        adj[u].push_back({v, s, t});
        adj[v].push_back({u, s, t});
        maxsec = max(maxsec, s);
    }
    int l = 1, r = maxsec; int anssec = -1;
    ll anscost = MAXLL;
    while (l <= r) {
        int mid = (l + r) / 2;
        auto [ok, cost] = dijkstra(mid);
        if (ok) {
            anssec = mid;
            anscost = cost;
            l = mid + 1;
        } 
        else r = mid - 1;
    }
    if (anssec == -1) cout << -1 << "\n";
    else cout << anssec << " " << anscost << "\n";
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
