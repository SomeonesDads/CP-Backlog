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
    // turns no matter, no one wants to move until its the last
    int n; ll k; 
    cin >> n >> k;
    string s; 
    cin >> s;
    n*=2;
    vector<char> end(n);
    REP(i, n){
        if(s[i] == '1' && s[(i+1)%n] == '0'){
            end[i] = '0';
            end[(i+1)%n] = '1';
            i++;
        }
        else{
            end[i] = s[i];
        }
        // cout <<"I: " << end[i+1] << " | " << s[i] << '\n';
    }
    int a = 0; 
    int b = 0;
    REP(i, n) if (end[i] == '1') if ((i+1)%2) b++; else a++;
    cout << a << " " << b << '\n';
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