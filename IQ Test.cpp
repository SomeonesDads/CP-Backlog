#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i = 0;i<n;i++)

void solve() {
    int n; cin >> n;
    int isEven = 0;
    int lastEven, lastOdd;
    int copyn = n;
    while(n--){
        int temp; cin >> temp;
        if(temp%2 == 0) lastEven = copyn - n;
        else lastOdd = copyn - n;
        isEven += temp%2;
    }
    if(isEven-1) cout << lastEven;
    else cout << lastOdd;
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