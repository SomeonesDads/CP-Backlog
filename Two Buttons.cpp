#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i = 0;i<n;i++)

int findans(int n, int m){
    if(n >= m) return n-m;
    else{
        int steps = 0;
        while(m!=n){
            if(m>n){
                if(m%2) steps++; m++;
                m/=2; steps++;
            }
            else{
                steps += n - m; break;
            }
        }
        return steps;
    }
}
void solve() {
    int n, m; cin >> n >> m;
    cout << findans(n, m) << endl;
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