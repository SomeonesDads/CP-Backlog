#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i = 0;i<n;i++)

void solve() {
    int max = 1000000;
    vector<bool> isPrime(max+1, true);
    isPrime[0] = false; isPrime[1] = false;
    for(int i = 2; i*i <= max; i++){
        if(isPrime[i]){
            for(int j = i*i; j <= max; j+=i){
                isPrime[j] = false;
            }
        }
    }
    unordered_set<ll> tprimes;
    for(int i = 0; i<= max; i++){
        if(isPrime[i]) tprimes.insert(1LL * i * i);
    }

    int n; cin >> n;
    REP(i, n){
        ll temp;
        cin >> temp;
        cout << (tprimes.count(temp) ? "YES\n" : "NO\n");
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