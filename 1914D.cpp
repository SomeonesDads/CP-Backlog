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

void insert(vector<pair<ll, int>> &a, pair<ll, int> input){
    if(input.first > a[2].first){
        a[2] = input;
        if(input.first > a[1].first){
            a[2] = a[1];
            a[1] = input;
            if(input.first > a[0].first){
                a[1] = a[0];
                a[0] = input;
            }
        }
    }
}

void solve() {
    int n; cin >> n;
    // vector<vector<ll>> a(n, vector<ll>(3));
    // 0 = go skiing;
    // 1 = watch a movie in a cinema;
    // 2 = play board games. 
    // REP(i, n) cin >> a[i][0];
    // REP(i, n) cin >> a[i][1];
    // REP(i, n) cin >> a[i][2];

    vector<pair<ll, int>> a(3, {0,0});
    vector<pair<ll, int>> b(3, {0,0});
    vector<pair<ll, int>> c(3, {0,0});
    ll tempa, tempb, tempc;
    REP(i, n){
        cin >> tempa;
        insert(a, {tempa, i+1});
    }
    REP(i, n){
        cin >> tempb;
        insert(b, {tempb, i+1});
    }
    REP(i, n){
        cin >> tempc;
        insert(c, {tempc, i+1});
    }
    ll ans = 0;
    REP(i, 3){
        REP(j, 3){
            REP(k, 3){
                if (a[i].second != b[j].second){
                    if(a[i].second != c[k].second){
                        if(b[j].second != c[k].second){
                            ans = max(ans, a[i].first + b[j].first + c[k].first);
                        }
                    }
                }
            }
        }
    }

    cout << ans << '\n';


    // 1 2 3
    // 1 3 2
    // 2 3 1
    // 2 1 3
    // 3 1 2
    // 3 2 1
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