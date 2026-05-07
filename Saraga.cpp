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
    string s1, s2; cin >> s1 >> s2;
    if(s1.length() == 1 || s2.length() == 1) cout << -1;
    else{
        vector<int> lastindex(26, -1);
        REP(i, s2.length()-1) lastindex[s2[i] - 'a'] = i;
        vector<bool> checked(26, false);
        pair<int, int> ans = {-1, mod};
        int a=1, b=s2.length();
        for(int i = 1; i<s1.length(); i++){
            if(checked[s1[i]-'a'] || lastindex[s1[i] - 'a'] == -1) continue;
            checked[s1[i]-'a'] = true;
            int temp = i + (s2.length() - lastindex[s1[i]-'a']);
            if(ans.second > temp) ans = {i, temp};
        }
        if(ans.first == -1) cout << -1;
        else{
            REP(i, ans.first+1) cout << s1[i];
            for(int i = lastindex[s1[ans.first] - 'a']+1; i<s2.length(); i++) cout << s2[i]; 
        }
    }
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