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

void solve() {
    string s;
    getline(cin, s);
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(8, false));
    vector<vector<int>> prevIndex(n, vector<int>(8, -1));
    vector<vector<int>> prevRem(n, vector<int>(8, -1));
    dp[0][(s[0]-'0') % 8] = true;
    for (int i = 1; i < n; i++) {
        dp[i][(s[i]-'0') % 8] = true;
        REP(j, 8){
            if(dp[i-1][j]){
                dp[i][j] = true;
                prevIndex[i][j] = i-1;
                prevRem[i][j] = j;
                int newRem = (j*10 + (s[i]-'0')) % 8;
                dp[i][newRem] = true;
                prevIndex[i][newRem] = i-1;
                prevRem[i][newRem] = j;
            }
        }
    }
    REP(i,n) {
        if (dp[i][0]) {
            string ans = "";
            int curI = i, curR = 0;
            while (curI >= 0) {
                int pi = prevIndex[curI][curR];
                int pr = prevRem[curI][curR];
                if (pi == -1 && pr == -1) {
                    ans.push_back(s[curI]);
                    break;
                }
                if (pr != curR) ans.push_back(s[curI]);
                curI = pi;
                curR = pr;
            }
            reverse(ans.begin(), ans.end());
            cout << "YES\n" << ans << "\n";
            return;
        }
    }

    cout << "NO\n";
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
