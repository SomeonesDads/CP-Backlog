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
    string s; cin >> s;
    int n = 0, g = 0, ng = 0, y = 0, vow = 0, cons = 0;
    REP(i, s.length()){
        if(s[i] == 'A' || s[i] == 'I' || s[i] == 'U' || s[i] == 'E' || s[i] == 'O') vow++;
        else if(s[i] == 'Y'){
            vow++; y++;
        }
        else if(s[i] == 'N'){
            cons++; n++;
        }
        else if(s[i] == 'G'){
            cons++; g++;
        }
        else cons++;
    }
    ng = min(n,g);
    cons -= ng;
    int cy = y, cng = ng, cvow = vow, ccons = cons;
    if(2*vow > cons){
        while(y>0 && 2*vow>cons){
            y--;
            cons++;
            vow--;
        }
        if(2*vow > cons){
            int leftover = min(ng, 2*vow - cons);
            cons += leftover;
            ng -= leftover;
        }
        // NG dlu baru Y
        int leftover = min(cng, 2*cvow - ccons);
        ccons += leftover;
        cng -= leftover;
        while(cy > 0 && 2*cvow > ccons){
            cy--;
            ccons++;
            cvow--;
        }

    }
    ng = min(ng, 2*vow);
    cng = min(cng, 2*vow);
    int ans = max(min(vow*3+ng, cons/2*3+ng), min(cvow*3+cng, ccons/2*3+cng));
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