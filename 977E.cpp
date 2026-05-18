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
    vector<vector<int>> adj(n+1);
    int ans = 0;
    REP(i, m){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    // cout << "a";
    vector<bool> visited(n+1, false);
    for(int i =1; i < n; i++){
        if(!visited[i]){
            visited[i] = true;
            bool cycle = (adj[i].size() == 2);
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int bla = q.front();
                q.pop();
                if(adj[bla].size() != 2) cycle = false;
                for(auto nword: adj[bla]){
                    if(visited[nword]) continue;
                    else{
                        q.push(nword);
                        visited[nword] = true;
                    }
                }
            }
            if(cycle) ans++;
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