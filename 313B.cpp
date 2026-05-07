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
        vector<int> dp(s.size()+1);
        dp[1] = 0;
        for(int i = 2; i < s.size()+1; i++){
            dp[i] = dp[i-1];
            if(s[i-1] == s[i-2]) dp[i]++;
        }
        int m; cin >> m;
        REP(i, m){
            int a, b; cin >> a >> b;
            // debug(b, dp[b], a, dp[a]);
            cout << dp[b]-dp[a] << "\n";
        }
    }
    
    int main() {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        ll test = 1;
        // cin >> test;
        while(test--) {
            solve();
        }
        return 0;
    }