#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i = 0;i<n;i++)

void solve() {
    int n, m; cin >> n >> m;
    int steps1 = 4; int steps2 = 4;
    REP(i, 4){
        int temp; cin >> temp;
        if(temp == 1 || temp == n && i < 2) steps1--;
        else if (temp == 1 || temp == n) steps2--;
    }
    cout << min(steps1, steps2) << endl;
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