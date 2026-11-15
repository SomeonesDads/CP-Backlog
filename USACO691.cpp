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
    int N;
    cin >> N;
    char S;
    vector<int> input(N, 0);
    for (int i = 0; i<N; i++){
        cin >> S;
        if (S == 'S') { input[i] = 0; }
        else if (S == 'P') { input[i] = 1; }
        else if (S == 'H') { input[i] = 2;}
    }
    vector<vector<int>> pref(N, vector<int>(3));
    int count = 0;
    REP(i, N){
        if (input[i] == 1) { count++; }
        pref[i][0] = count;
    }
    count = 0;
    REP(i, N){
        if (input[i] == 2) { count++; }
        pref[i][1] = count;
    }
    count = 0;
    REP(i, N){
        if (input[i] == 0) { count++; }
        pref[i][2] = count;
        // debug(pref)
    }
    int mmax = 0;
    REP(i, N){
        vector<int> start(3);
        vector<int> oppos(3);
        REP(j, 3) start[j] = pref[i][j];
        REP(j, 3) oppos[j] = pref[N-1][j] - pref[i][j]; 
        // if(i == 0) debug(oppos[0] + start[2]);
        REP(j, 3){
            REP(k, 3){
                if(j!=k){
                    int before = mmax;
                    mmax = max(max(start[j] + oppos[k], start[k] + oppos[j]), mmax);
                    // if(mmax > before) debug(i, j, k);
                }
            }
        }
    } 
    cout << mmax << '\n';
}

int main() {
    // ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll test = 1;
    // cin >> test;
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    while(test--) {
        solve();
    }
    return 0;
}