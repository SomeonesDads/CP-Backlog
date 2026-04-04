#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i=0; i<n; i++)
#define mod 1000000007
void solve()
{
    int n, k; cin >> n >> k;
    int res = 0;
    k--;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    REP(i,n){
        if(a[i] >= a[k] && a[i] != 0) res++;
    }
    cout << res;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
#endif

    ll test=1;
    // cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
