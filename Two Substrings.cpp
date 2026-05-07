#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i = 0;i<n;i++)

void solve() {
    string s; cin >> s;
    int len = s.size();
    int aba = 0, ab = 0, ba = 0;
    bool check = false;
    REP(i, (len-1)){
        if(s[i] == 'A'){
            if(s[i+1] == 'B'){
                ab++;
            }
        }
        else if(s[i] == 'B'){
            if(s[i+1] == 'A'){
                ba++;
                if(i!=0){
                    if(s[i-1] == 'A'){
                        ab--; aba++; ba--; check 
                    }
                }
            }
        }
    }
    // cout << ab << " " << ba << " " << aba << endl;
    if(ab<ba) ab += aba;
    else if(ba<ab) ba += aba;
    else if(ab==ba && ab==0){
        ab += aba/2; ba += aba/2;
    }
    
    cout << ((ab > 0 && ba > 0) ? "YES" : "NO") << endl;
    
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