#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i=0; i<n; i++)
#define mod 1000000007

int loop(int i, int k, string s){
    int end;
    for(int j = i+1; j<=i+k-1; j++){
        if(s[j] == '1') return loop(j, k, s);
        end = j;
    }
    return end;
}

void solve()
{
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int res = 0;
    // cout << "(";
    REP(i, n){
        // cout << i;
        if(s[i] == '1'){
            i = loop(i, k, s);
            res++;
        }
    }
    // cout << ")" << endl;
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
