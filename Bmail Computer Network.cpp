#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i=0; i<n; i++)
#define mod 1000000007
void solve()
{
    int n;
    cin >> n;
    vector<int> routers(n-1);
    REP(i, n-1) cin >> routers[i];
    vector<int> path;
    int cur = n;
    while(cur != 0){
        path.push_back(cur);
        if (cur == 1) break;
        cur = routers[cur-2];
    }
    reverse(path.begin(), path.end());
    REP(i, path.size()){
        cout << path[i] << " ";
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
