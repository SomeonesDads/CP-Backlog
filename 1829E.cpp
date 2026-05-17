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
    vector<vector<int>> lake(n, vector<int>(m));
    REP(i, n){
        REP(j, m){
            cin >> lake[i][j];
        }
    }
    ll ans = 0;
    vector<vector<int>> visited(n, vector<int>(m, 0));
    REP(i, n){
        REP(j, m){
            // debug(i, j);
            ll sum = 0;
            if(lake[i][j] && !visited[i][j]){
                queue<pair<int, int>> q;
                visited[i][j] = 1;
                
                q.push({i, j});
                while(!q.empty()){
                    
                    auto [a, b] = q.front();
                    // debug(a,b);
                    q.pop();
                    sum += lake[a][b];    
                    vector<pair<int, int>> child(4);
                    child[0] = {a, b+1};
                    child[1] = {a, b-1};
                    child[2] = {a-1, b};
                    child[3] = {a+1, b};
                    REP(k, 4){
                        auto [x, y] = child[k];
                        // debug(x,y);
                        if(x >= 0 && x < n && y >= 0 && y < m && !visited[x][y] && lake[x][y]){
                            // debug(x,y);
                            visited[x][y] = 1;
                            q.push({x,y});
                        }
                    }
                }
            }
            ans = max(sum, ans);
        }
    }
    cout << ans << "\n";
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