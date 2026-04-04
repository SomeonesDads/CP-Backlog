#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i=0; i<n; i++)
#define RREP(i,n) for(int i=n-1; i>= 0;i++)
#define mod 1000000007
void solve()
{
    ll a, b, res; cin >> a >> b;
    if(a*b%2 != 0){
        cout << a*b+1 << endl;
    }
    else{
        if(b%2 != 0) cout << -1 << endl;
        else{ 
            ll firstopt = a*(b/2) + 2;
            ll secondopt = a*2 + b/2;
            if(firstopt%2 != 0){
                // printf("first op: %d    second: %d", firstopt, secondopt);
                if(secondopt%2 != 0){
                    res = -1;
                }
                else{
                    res = secondopt;
                }
                
            }
            else{
                if(secondopt%2 != 0){
                    res = firstopt;
                }
                else{
                    res = max(firstopt, secondopt);
                }
            }
            cout << res << endl;
        }
    }
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
