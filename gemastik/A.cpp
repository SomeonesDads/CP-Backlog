#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, x; 
    if (!(cin >> n >> m >> x)) return 0;

    vector<int> a(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];

    vector<char> o(n-1);
    for(int i = 0; i < n-1 ; i++) cin >> o[i];

    vector<vector<int>> dp(n, vector<int>(m, -1));
    dp[0][a[0] % m] = 1;

    vector<vector<pair<int, char>>> before(n, vector<pair<int, char>>(m));

    for(int i = 0 ; i < n-1 ; i++){
        for(int j = 0 ; j < m ; j++){
            if(dp[i][j] == 1) {
                if(o[i] == '+'){
                    int nxt = (j + a[i+1]) % m;
                    dp[i+1][nxt] = 1;
                    before[i+1][nxt] = {j, '+'};
                }
                else if(o[i] == '*'){
                    int nxt = (j * a[i+1]) % m;
                    dp[i+1][nxt] = 1; 
                    before[i+1][nxt] = {j, '*'};
                }
                else {
                    int nxt_plus = (j + a[i+1]) % m;
                    dp[i+1][nxt_plus] = 1;
                    before[i+1][nxt_plus] = {j, '+'};

                    int nxt_mul = (j * a[i+1]) % m;
                    dp[i+1][nxt_mul] = 1;
                    before[i+1][nxt_mul] = {j, '*'};
                }
            }
        }
    }

    if(dp[n-1][x] == 1) cout << "YA" << endl;
    else {
        cout << "TIDAK"; 
        return 0;
    }

    int curi = n - 1;
    int curj = x;
    vector<char> ans;

    while(curi > 0){
        char symbol = before[curi][curj].second;
        int prev_j = before[curi][curj].first;
        
        ans.push_back(symbol);
        curj = prev_j;
        curi--;
    }
    reverse(ans.begin(), ans.end());
    for(auto ch : ans) cout << ch;
    cout << "\n";

    return 0;
}