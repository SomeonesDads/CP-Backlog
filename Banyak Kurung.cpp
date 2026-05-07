#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i = 0;i<n;i++)
#define MOD 1000000007


void solve() {
    int n; cin >> n;
    ll factorial = 1;
    for(int i = 1; i < n; i++){
        factorial*=n;
    }
    cout << ((n*factorial) % MOD);
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