#include <bits/stdc++.h>
using namespace std;
template<typename T>
void _debug(const char* name, T&& value) {
    cerr << name << " = " << value << endl;
}
template<typename T, typename... Args>
 void _debug(const char* names, T&& value, Args&&... args) {
    const char* comma = strchr(names, ',');
    cerr.write(names, comma - names) << " = " << value << " | ";
    _debug(comma + 1, args...);
}


#define debug(...) _debug(#__VA_ARGS__, __VA_ARGS__)
#define ll long long
#define REP(i,n) for(int i=0; i<n; i++)
#define RREP(i,n) for(int i=n-1; i>= 0; i--)
#define mod 1000000007

void solve()
{
    ll k; cin >> k;
    ll w1,v1,s1, w2,v2,s2; cin >> w1 >> v1 >> s1 >>  w2 >> v2 >> s2;
    // Ga guna nyoba dua duanya, greedy aj langsung;
    vector<ll> ans(4);

    //ans1
    ll k1 = k - s1;
    if(k1 <= 0){ans[0] = 0;}
    else{
        ans[0] = k1/w1;
        ans[0] *= v1;
    }

    //ans2
    ll k2 = k - s2;
    if(k2 <= 0){ans[1] = 0;}
    else{
        ans[1] = k2/w2;
        ans[1] *= v2;
    }

    //ans3 & 4
    ans[2] = 0; ans[3] = 0;
    ll k3 = k - s1 - s2;
    if (k3 >= w1 + w2) { 
        for (ll x = 1; x <= w2; ++x) {
            ll sisa_kuota = k3 - (x * w1);
            if (sisa_kuota >= w2) {
                ll y = sisa_kuota / w2;
                ans[2] = max(ans[2], x * v1 + y * v2);
            }
        }
        for (ll y = 1; y <= w1; ++y) {
            ll sisa_kuota = k3 - (y * w2);
            if (sisa_kuota >= w1) {
                ll x = sisa_kuota / w1;
                ans[3] = max(ans[3], x * v1 + y * v2);
            }
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans[3];
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
