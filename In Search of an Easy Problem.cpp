#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i=0; i<n; i++)
#define mod 1000000007
void solve()
{
    int n; cin >> n;
    int a;
    REP(i, n){
        cin >> a;
        if(a == 1){
            cout << "HARD";
            return;
        }
    }
    cout << "EASY";
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
