#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i = 0;i<n;i++)

void solve() {
    int ab = 0, ba = 0;
    bool aba = false, bab = false;
    string s; cin >> s;
    int n = s.size();
    REP(i, n){
        if(s[i] == 'A'){
            if(i < n-1){
                if(s[i+1] == 'B'){
                    ab++; i++;
                    if(s[i+1] == 'A'){
                        aba = true;
                        i++;
                    }
                }
            }
        }
        else if(s[i] == 'B'){
            if(i < n-1){
                if(s[i+1] == 'A'){
                    ba++; i++;
                    if(s[i+1] == 'B'){
                        bab = true;
                        i++;
                    }
                }
            }
        }
    }
    // cout << ab << " " << ba << " " << aba << " " << bab << endl;
    if(!ba){
        if(aba){
            ba++; ab--;
        }
    }
    if(!ab){
        if(bab){
            ab++; ba--;
        }
    }
    // cout << ab << " " << ba << endl;
    if(ab >= 1 && ba >= 1) cout << "YES\n";
    else cout << "NO\n";
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