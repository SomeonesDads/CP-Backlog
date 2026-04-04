#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i=0; i<n; i++)
#define mod 1000000007
void solve()
{
    string s; cin >> s;
    int luckcount = 0;
    REP(i, s.length()){
        if(s[i] == '4' || s[i] == '7') luckcount++;
    }
    cout << ((luckcount == 7 || luckcount == 4) ? "YES" : "NO");
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
