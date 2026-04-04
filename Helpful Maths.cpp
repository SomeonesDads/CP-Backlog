#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i=0; i<n; i++)
#define mod 1000000007
void solve()
{
    string a;
    cin >> a;
    vector<int> calcs((a.length()+1)/2);
    for(int i = 0; i < a.length(); i+=2){
        calcs[i/2] = a[i] - '0';
    }
    sort(calcs.begin(), calcs.end());
    REP(i, calcs.size()){
        if(i != calcs.size()-1){
            cout << calcs[i] << "+";
        }
        else cout << calcs[i];
    }
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
