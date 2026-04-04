#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i=0; i<n; i++)
#define mod 1000000007
void solve()
{
    int n;
    cin >> n;
    vector<int>a(n);
    REP(i, n) cin >> a[i];
    bool possible = true;
    if(n > 2){
        int outsidemin, insidemax;
        if(n%2 == 0){
            outsidemin = min(a[n-1], a[n-2]);
            for(int i = n-3; i>=1; i-=2){
                insidemax = max(a[i], a[i-1]);
                if(insidemax > outsidemin){
                    possible = false;
                    break;
                }
                outsidemin = min(a[i], a[i-1]);
            }
        }
        else{
            outsidemin = min(a[n-1], a[n-2]);
            for(int i = n-3; i>0; i-=2){
                insidemax = max(a[i], a[i-1]);
                if(insidemax > outsidemin){
                    possible = false;
                    break;
                }
                outsidemin = min(a[i], a[i-1]);
            }
            if(a[0] > outsidemin) possible = false;
        }
    }
    if(possible) cout << "YES" << endl;
    else cout << "NO" << endl;

    
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
