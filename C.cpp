#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i = 0;i<n;i++)

void solve() {
    int N;
    cin >> N;
    vector<ll> y(N);
    REP(i, N) cin >> y[i];
    if (N == 0) {
        cout << 0 << "\n";
        return;
    } 
    vector<ll> y_prime;
    if (N > 0) {
        y_prime.push_back(y[0]);
        for (int i = 1; i < N; ++i) {
            if (y[i] != y_prime.back()) y_prime.push_back(y[i]);
        }
    }
    int m = y_prime.size();
    if (m <= 1) {
        cout << 0 << "\n";
        return;
    }
    if (m == 2) { 
        cout << 1 << "\n";
        return;
    }
    
    bool alternates = true;
    if (m >= 3) {
        if (y_prime[0] == y_prime[1]) {
             alternates = false;
        } else {
            for (int i = 0; i < m - 2; ++i) {
                if (y_prime[i] != y_prime[i+2]) {
                    alternates = false;
                    break;
                }
            }
        }
        if (alternates && N > m) {
            cout << N - 1 << "\n";
            return;
        }
    }
    vector<ll> differences;
    for (int i = 0; i < m - 1; ++i) differences.push_back(y_prime[i+1] - y_prime[i]);
    int sign_changes = 0;
    int last_sign = 0;  
    for (ll diff : differences) {
        if (diff > 0) { last_sign = 1; break; }
        else if (diff < 0) { last_sign = -1; break; }
    }
    for (ll diff : differences) {
        int current_sign = 0;
        if (diff > 0) current_sign = 1;
        if (current_sign != 0) {
            if (last_sign != 0 && current_sign != last_sign) sign_changes++;
            last_sign = current_sign;
        }
    }
    cout << sign_changes + 1;
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