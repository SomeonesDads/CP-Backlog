#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i = 0;i<n;i++)

void solve() {
    int n, t; cin >> n >> t;
    bool possible = false;
    vector<int> portals(n-1);
    REP(i, n-1){
        cin >> portals[i];
    }
    int index = 0;
    while(index < n-1){
        index += portals[index];
        if(index+1 == t) possible = true;
    }
    cout << ( possible ? "YES" : "NO") << endl; 
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