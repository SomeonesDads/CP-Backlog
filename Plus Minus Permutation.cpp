#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i=0; i<n; i++)
#define mod 1000000007
void solve()
{
    int n,x,y;
    cin >> n >> x >> y;
    int pluss = n/x;
    int minuss = n/y;
    int same = 0;
    for(int i = 1; i < n; i++){
        if(i%x == 0&& i%y == 0){
            same++;
        }
    }    
    pluss -= same;
    minuss -= same;
    int res = (n*pluss - pluss/2*(1 + pluss)) - (minuss/2*(1 + minuss));
    cout << res << endl;

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
