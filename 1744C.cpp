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
    int n; char c; cin >> n >> c;
    string s; cin >> s;
    vector<int> marks;
    vector<int> greens;
    if(c == 'g'){
        cout << 0 << '\n'; return;
    }
    int ans = 0;
    REP(i, n){
        if(s[i] == c){
            marks.push_back(i);
        }
        if(s[i] == 'g'){
            greens.push_back(i);
        }
    }
    REP(i, marks.size()){
        // kanan index pertama setelahnya
        int target = marks[i];

        int l = -1;
        int r = greens.size();
        while(r - l > 1){
            int m = l + (r-l)/2;

            if(greens[m] > target){
                r = m;
            }
            else l = m;
        }
        if(r == greens.size()){
            ans = max(ans, n - target + greens[0]);
        }
        else ans = max(ans, abs(greens[r] - target));
    }

    cout << ans << '\n';

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