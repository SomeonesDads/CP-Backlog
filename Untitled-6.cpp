#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i = 0;i<n;i++)

void solve() {
    ll sum = 0;
    int n; cin >> n;
    REP(i, n){
        ll temp;cin >> temp;
        sum += temp;
    }
    printf("[%lld]", sum);
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