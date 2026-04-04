#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i=0; i<n; i++)
#define RREP(i,n) for(int i=n-1; i>= 0; i--)
#define mod 1000000007

string decToBinary(int n) {
    string bin = ""; 
    while (n > 0) {
        int bit = n & 1;
        bin.push_back('0' + bit);
        n = n >> 1;
    } 	
    reverse(bin.begin(), bin.end());
    return bin;
}

bool isgood(string s){
    string revers = s;
    reverse(revers.begin(), revers.end());
    if(revers.size()%2 && revers[revers.size()/2] == '1') return false;
    if(revers == s) return true;
    return false;
}
void solve()
{
    unsigned int n; cin >> n;
    string bit = decToBinary(n);
    int endzero = 0;
    RREP(i, bit.size()){
        if(bit[i] == '0') endzero++;
        else break;
    }
    bool can = isgood(bit);
    if(!can){
        REP(i, endzero){
            bit = '0' + bit;
            can = isgood(bit);
            if(can) break;
        }
    }
    cout << (can ? "YES" : "NO") << endl;
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
