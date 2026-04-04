#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i=0; i<n; i++)
#define mod 1000000007
void solve()
{
    pair<int, int> coordinates;
    int temp;
    REP(i,5){
        REP(j, 5){
            cin >> temp;
            if(temp){
                coordinates.first = i+1;
                coordinates.second = j+1;
            }
        }
    }
    cout << abs(3 - coordinates.first) + abs(3 - coordinates.second);

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
