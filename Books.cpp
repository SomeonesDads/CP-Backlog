#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i=0; i<n; i++)
#define RREP(i,n) for(int i=n-1; i>= 0;i++)
#define mod 1000000007
void solve()
{
    int n, t; cin >> n >> t;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    ll sum = 0;
    int l = 0, ans = 0;
    for (int r = 0; r < n; r++) {
        sum += a[r];
        while (sum > t) {
            sum -= a[l];
            l++;
        }
        ans = max(ans, r - l + 1);
    }

    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll test=1;
    //cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
