#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i = 0;i<n;i++)

void solve() {
    int n, k; cin >> n >> k;
    int ans = n;
    for(int m = 1; m <= (int)n; ++m){
        int req = m * (n - m);
        if(req <= k){
            cout << m << '\n';
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    cin >> test;
    while(test--){
       solve();
    }
    return 0;
}