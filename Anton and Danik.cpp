#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i=0; i<n; i++)
#define mod 1000000007
void solve()
{
    int n, a, d; cin >> n;
    a = 0; d = 0;
    string s; cin >> s;
    REP(i, n){
        if(s[i] == 'A') a++;
        else d++;
    }
    cout << (a > d ? "Anton" : a == d ? "Friendship" : "Danik");
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
