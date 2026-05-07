#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i = 0;i<n;i++)

void solve() {
    int n; int k; cin >> n >> k;
    vector<ll> magic(n);
    vector<ll> mana(n);
    vector<pair<ll,int, vector<int>>> dp(n);
    REP(i, n) cin >> magic[i];
    REP(i, n) cin >> mana[i];
    ll ans = -1;
    REP(i, n){
        k++
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