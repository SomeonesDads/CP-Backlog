#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i=0; i<n; i++)
#define mod 1000000007
void solve()
{
    int n; cin >> n;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    int maxl = max(a[0], a[1]);
    ll res = 0;
    REP(i, n){
        if((i+1)%2){
            if(a[i] >= maxl){
                res+=(a[i]-maxl+1);
            }
        }
        maxl = max(maxl, a[i]);
    }
    cout << res << endl;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll test=1;
    cin>>test;
    while(test--)
    {
        solve();
    }
    // cout << "Hello world";
    return 0;
}
