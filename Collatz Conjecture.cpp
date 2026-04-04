#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i=0; i<n; i++)
#define RREP(i,n) for(int i=n-1; i>= 0;i++)
#define mod 1000000007
void solve()
{
    ll x, k; cin >> k >> x;
    while(k--){
        if(((x-1)/3)%2 == 0 || (x-1)%3 != 0){
            x*=2;
        }
        else x = (x-1)/3;
    }
    cout << x << endl;
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