#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i=0; i<n; i++)
#define mod 1000000007
void solve()
{
    int n, h; cin >> n >> h;
    vector<int> heights(n);
    REP(i, n){
        cin >> heights[i];
    }
    REP(i,heights.size()) if(heights[i] > h) n++;
    cout << n;
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
