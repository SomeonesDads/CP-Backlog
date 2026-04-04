#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i=0; i<n; i++)
#define RREP(i,n) for(int i=n-1; i>= 0;i++)
#define mod 1000000007
void solve()
{
    int n; cin >> n;
    ll maxl;
    string ans;
    REP(i,n){
        string s; cin >> s;
        int m; cin >> m;
        ll maxsum,cursum,temp;
        cursum = 0;
        maxsum = 0;
        REP(j, m){
            cin >> temp;
            cursum = max(0LL, cursum + temp);
            maxsum = max(cursum, maxsum);
        }
        if(i == 0){
            maxl = maxsum; ans = s;
        }
        else if (maxsum > maxl){
            maxl = maxsum; ans = s;
        }
    }
    cout << ans;
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
