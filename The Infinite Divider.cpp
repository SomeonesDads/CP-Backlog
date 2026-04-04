#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i=0; i<n; i++)
#define RREP(i,n) for(int i=n-1; i>= 0;i++)
#define mod 1000000007
void solve()
{
    int n; cin >> n;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    double one_iter = 0;
    one_iter+= 1/a[n-1];
    int i = 0;
    double old = -1;
    int counter = 100*n;
    while(counter--){
        one_iter = 1/(one_iter + a[n-i-1]);
        // cout << n-i-1 << " " << one_iter << endl;
        if(n-i-1 == 1){
            if(old == -1) old = one_iter;
            else if (abs(one_iter - old) < 0.000001) break;
            else old = one_iter;
        }
        i= (i+1)%(n);
    }
    cout << fixed << setprecision(6) << a[0]*1.0 + one_iter << endl;
    
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll test=1;
    cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
