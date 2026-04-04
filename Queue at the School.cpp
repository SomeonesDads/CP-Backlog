#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i=0; i<n; i++)
#define RREP(i, n) for(int i = n-1; i >= 0; i--)
#define mod 1000000007
void solve()
{
    int n, t; cin >> n >> t;
    string q; cin >> q;
    string temp = q;
    while(t--){
        temp = q;
        REP(i, n-1){
            if(q[i+1] == 'G' && q[i] == 'B'){
                swap(temp[i],temp[i+1]);
            }
        }
        q = temp;
    }
    cout << q;
    
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
