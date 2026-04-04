#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i=0; i<n; i++)
#define RREP(i,n) for(int i=n-1; i>= 0;i++)
#define mod 1000000007

struct cake{int c; ll p, l, t;};

void solve()
{
    int n;
    cin >> n;
    vector<cake> cakes;
    REP(i, n) {
        int c; ll p, l, t;
        cin >> c >> p >> l >> t;
        if (c == 1) { 
            ll a[3] = {p, l, t};
            sort(a, a+3);
            cakes.push_back({1, a[0], a[1], a[2]});  // p <= l buat sorting
            cakes.push_back({1, a[0], a[2], a[1]});
            cakes.push_back({1, a[1], a[2], a[0]});
        } else { 
            (p>l) ? cakes.push_back({0, l, p, t}) : cakes.push_back({0, p, l, t});
        }
    }
    int m = cakes.size();
    // REP(i, m) cout << "|" << cakes[i].c << " " << cakes[i].p << " " << cakes[i].l << " " << cakes[i].t << "|\n";  
    sort(cakes.begin(), cakes.end(), [](cake &a, cake &b) {return a.p * a.l > b.p * b.l;});
    // REP(i, m) cout << "|" << cakes[i].c << " " << cakes[i].p << " " << cakes[i].l << " " << cakes[i].t << "|\n";  
    
    vector<ll> dp(m);
    ll ans = 0;
    REP(i, m) {
        dp[i] = cakes[i].t; 
        REP(j, i){
            if (cakes[i].p < cakes[j].p && cakes[i].l < cakes[j].l && cakes[j].c) dp[i] = max(dp[i], dp[j] + cakes[i].t); // janginam gk bisa piramid ditengah y, typo lagi
        }
        // cout << "|" << cakes[i].p << " " << cakes[i].l << " " << cakes[i].t << "| dp = " << dp[i] << "\n";  
        ans = max(ans, dp[i]);
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
