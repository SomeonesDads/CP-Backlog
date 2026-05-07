#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i = 0;i<n;i++)

void solve() {
    ll n, a, b, k; cin >> n >> a >> b >> k;
    vector<ll> pohon(n);
    REP(i, n) cin >> pohon[i];
    ll diff = (abs(a-b))%a%b;
    if(!diff) diff = min(a,b);
    ll original = 0;
    for(int i = 1; i< n; i++){
        original += abs(pohon[i] - pohon[i-1]);
    }
    ll poisoned = 0;
     for(int i = 1; i< n; i++){
        ll crement = (abs(pohon[i] - pohon[i-1])/diff)*diff;
        if(pohon[i] < pohon[i-1]) pohon[i]+=crement;
        else pohon[i] -= crement;
    }

    // cout << "\nPoisoned = {";
    // REP(i, n) cout << pohon[i] << " ";
    // cout << "}";
    for(int i = 1; i< n; i++){
        poisoned += abs(pohon[i] - pohon[i-1]);
    }
    poisoned += k;
    // printf("\np: %lld o: %lld", poisoned, original);

    cout << ((poisoned < original) ? poisoned : original) << endl;

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