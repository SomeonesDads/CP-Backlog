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

void solve()
{
    int n; cin >> n;
    string s; cin >> s;
    // map<char, int> freq;
    if(n == 1){
        cout << 1 << '\n';
        return;
    }
    // REP(i, n) freq[s[i]]++;
    if(n%2){
        int m1, m2;
        REP(i, n){

        }
    }
    else{
        int m1, m2;
        map<char, int> freq1;
        map<char, int> freq2;
        for(int i = 0; i < n; i+=2) freq1[s[i]++];
        for(int i = 1; i < n; i+=2) freq2[s[i]++];
        for(auto [u, v]: freq1) m1 = max(m1, v);
        for(auto [u, v]: freq2) m2 = max(m2, v);
        cout << n - m1 - m2;
    }
    
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
