#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i = 0;i<n;i++)

void solve() {
    map<string,int> m;
    int n; cin >> n;
    REP(i,n){
        string s;
        cin >> s;
        m[s]++;
        if (m[s] == 1) cout << "OK\n";
        else cout << s << (m[s]-1) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    // cin >> test;
    while(test--){
       solve();
    }
    return 0;
}