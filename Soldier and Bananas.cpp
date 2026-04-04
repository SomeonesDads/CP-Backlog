#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i=0; i<n; i++)
#define mod 1000000007
void solve()
{
    int k,n,w; cin >> k >> n >> w;
    int totalcost = 0;
    REP(i, w+1){
        totalcost += k*i;
    }
    cout << ((totalcost > n) ? totalcost-n : 0); 
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
