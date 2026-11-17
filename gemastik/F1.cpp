#include <bits/stdc++.h>
using namespace std;
#define long long ll;



string convert(int n, int mxSz){
    string s;
    while(n > 0){
        if(n % 2 == 1){
            s += '1';
        }
        else s += '0';
        n = n/2;
    }
    while(s.size() < mxSz){
        s += '0';
    }
    return s;
}

int main()
{
    int n ; cin >> n;
    vector<pair<int,int>> f(n);
    for(int i = 0 ; i < n ; i++){
        cin >> f[i].first >> f[i].second;
    }
    int ans = 0;
    for(int i = 0 ; i < (1 << n); i++){
        int cur = i;
        vector<int> chec(n);
        string curS = convert(cur,n);
        // cout << curS << endl;
        for(int i = 0 ; i < curS.size() ; i++){
            if(curS[i] == '0'){
                chec[i] = f[i].first;
            }
            else chec[i] = f[i].second;
        }
        sort(chec.begin(),chec.end());
        int curMin = 1e9+1;
        for(int i = 0 ; i < n-1 ; i++){
            curMin = min(curMin, chec[i+1] - chec[i]);
        }
        ans = max(ans,curMin);
    }
    cout << ans;

}