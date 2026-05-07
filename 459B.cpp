#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i = 0;i<n;i++)

void solve() {
    int n; cin >> n;
    int minl, maxl;
    int temp; cin >> temp;
    maxl = temp;
    minl = temp;
    map<int,int> freq;
    freq[temp]++;
    REP(i, n-1){
        cin >> temp;
        minl = min(temp, minl);
        maxl = max(temp, maxl);
        freq[temp]++;
    }   
    ll mults;
    if(maxl == minl) mults = 1LL*freq[maxl]*(freq[maxl]-1)/2;
    else mults = 1LL*freq[maxl]*freq[minl];
    cout << maxl - minl << " " << mults;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    // cin >> test;
    while(test--){
       solve();
    }
    return 0;
}