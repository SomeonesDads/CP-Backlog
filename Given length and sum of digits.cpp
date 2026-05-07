#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i = 0;i<n;i++)

void solve() {
    int m, s; cin >> m >> s;
    if ((s == 0 && m > 1) || s > 9 * m){ cout << "-1 -1"; return;}
    if (s == 0 && m == 1){ cout << "0 0"; return;}

    int sum = s;
    string maxl = "";
    REP(i, m){
        int dig = min(9, sum);
        maxl += ('0' + dig);
        sum -= dig;
    }

    sum = s;
    string minl (m, '0');
    for(int i = m-1; i>=1 ;i--){
        int dig = min(9,(sum-1));
        minl[i] = ('0' + dig);
        sum -= dig;
    }
    minl[0] = ('0' + sum);

    cout << minl << " " << maxl;
    
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