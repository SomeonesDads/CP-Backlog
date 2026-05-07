// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define REP(i,n) for(int i = 0;i<n;i++)

// void solve() {
//     int n; cin >> n;
//     vector<int> a(n);
//     vector<int> opts(n);
//     REP(i, n) cin >> a[i];
//     REP(i, n){
//         if(a[i] == 0) opts[i] = 0;
//         else if(a[i] == 1){
//             if(i == 0) opts[i] = 1;
//             else if(opts[i-1] != 1) opts[i] = 1;
//             else opts[i] = 0;
//         }
//         else if(a[i] == 2){
//             if (i == 0) opts[i] = 2;
//             else if(opts[i-1] != 2)  opts[i] = 2;
//             else opts[i] = 0;
//         }
//         else if(a[i] == 3){
//             if(i != 0){
//                 if(opts[i-1] == 0){
//                     if(i != n-1){
//                         if(a[i+1] == 1) opts[i] = 2;
//                         else if(a[i+1] == 2) opts[i] = 1;
//                         else{
//                             while(a[i] == 3 && i < n){
//                                 i++;
//                                 opts[i] = 1;
//                             }
//                             i-=2;
//                         }
//                     }
//                 }
//                 else if(opts[i-1] == 1) opts[i] = 2;
//                 else if(opts[i-1] == 2) opts[i] = 1;
//             }
//             else if(n == 1) opts[0] = 1;
//             else{
//                 if(a[i+1] == 1) opts[i] = 2;
//                 else if(a[i+1] == 2) opts[i] = 1;
//                 else{
//                      while(a[i] == 3 && i < n){
//                                 i++;
//                                 opts[i] = 1;
//                             }
//                         i-=2;
//                 }
//             }
//         }
//     }
//     int sum = 0;
//     REP(i, n){
//         if(!opts[i]) sum++;
//     }
//     cout << sum;
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int test = 1;
//     // cin >> test;
//     while(test--){
//        solve();
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i = 0;i<n;i++)

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> opts(n, 0);
    REP(i, n) cin >> a[i];
    vector<vector<int>> dp(n, vector<int>(3, 101));
    dp[0][0] = 1;
    if (a[0] == 1 || a[0] == 3) dp[0][1] = 0;
    if (a[0] == 2 || a[0] == 3) dp[0][2] = 0;
    for (int i = 1; i < n; i++) {
        dp[i][0] = 1 + min(dp[i-1][0], min(dp[i-1][1], dp[i-1][2]));
        if (a[i] == 1 || a[i] == 3)
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
        if (a[i] == 2 || a[i] == 3)
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]);
    }
    cout << min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
