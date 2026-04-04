#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i=0; i<n; i++)
#define mod 1000000007
bool is_beautiful(string year){
    return (year[0] != year[1] && year[0] != year[2] &&year[0] != year[3] &&year[1] != year[2] &&year[1] != year[3] &&year[2] != year[3]);
}
void solve()
{
    int n; cin >> n;
    n++;
    string s = to_string(n);
    while(!is_beautiful(s)){
        n++;
        s = to_string(n);
    }
    cout << s;
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
