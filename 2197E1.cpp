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

vector<int> ask(ll k) {
    cout << "? " << k << endl;
    cout.flush();
    int len;
    cin >> len;
    if (len == -1) exit(0); 
    if (len == 0) return {};
    vector<int> path(len);
    REP(i, len) cin >> path[i];
    return path;
}


void solve(){
    int n;
    if (!(cin >> n)) return;
    ll current_idx = 1;
    vector<ll> count(n + 1, 0);
    vector<pair<int,int>> edges;
    for(int u = 1; u <= n; u++)
    {
        vector<int> p = ask(current_idx);
        if(p.empty()) break;
        ll start_u = current_idx;
        current_idx++; 
        while(true)
        {
            vector<int> path = ask(current_idx);
            if(path.empty() || path[0] != u){
                count[u] = current_idx - start_u;
                break;
            }
            int v = path[1];
            edges.push_back({u, v});
            if(v < u) {
                current_idx += count[v];
            }
            else{
                ll L = current_idx + 1;
                ll R = current_idx + (1LL << 30); 
                ll boundary = current_idx;

                while(L <= R){
                    ll mid = L + (R - L) / 2;
                    vector<int> check_p = ask(mid);
                    bool match = false;
                    if(check_p.size() >= 2 && check_p[0] == u && check_p[1] == v){
                        match = true;
                    }

                    if(match){
                        boundary = mid; 
                        L = mid + 1;    
                    }
                    else{
                        R = mid - 1;
                    }
                }
                current_idx = boundary + 1;
            }
        }
    }
    cout << "! " << edges.size() << endl;
    for(auto &e : edges)
    {
        cout << e.first << " " << e.second << endl;
    }
    cout.flush();
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