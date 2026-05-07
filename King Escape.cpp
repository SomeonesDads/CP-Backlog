#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i = 0;i<n;i++)

void solve() {
    int n; cin >> n;
    vector<int> a(2); vector<int> b(2); vector<int> c(2);
    cin >> a[0] >> a[1] >> b[0] >> b[1] >> c[0] >> c[1];
    bool xcheck = (b[0] < a[0] && c[0] < a[0]) || (b[0] > a[0] && c[0] > a[0]);
    bool ycheck = (b[1] < a[1] && c[1] < a[1]) || (b[1] > a[1] && c[1] > a[1]);
    if (xcheck && ycheck) cout << "YES";
    else cout <<"NO";
    
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