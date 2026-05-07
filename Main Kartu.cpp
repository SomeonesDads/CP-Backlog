#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i = 0;i<n;i++)

void solve() {
    map<char, int> facecards;
    facecards['6'] = 6;
    facecards['7'] = 7;
    facecards['8'] = 8;
    facecards['9'] = 9;
    facecards['T'] = 10;
    facecards['J'] = 11;
    facecards['Q'] = 12;
    facecards['K'] = 13;
    facecards['A'] = 14;
    int n, m; cin >> n >> m;
    char truf; cin >> truf;
    vector<string> aku(n);
    vector<string> lawan(m);
    REP(i,n) cin >> aku[i];
    REP(i, m) cin >> lawan[i];
    int unmatched = 0;
    for(int i = 0; i<m; i++){
        int temp = 15;
        int indextodelete = -1;
        for(int j = 0; j< n; j++){
            if (lawan[i][1] == aku[j][1] && facecards[lawan[i][0]] < facecards[aku[j][0]]){
                if(facecards[aku[j][0]] < temp){
                    indextodelete = j;
                }
            }
        }
        if(indextodelete == -1){
            unmatched++;
        }
        else{
            lawan[i] = "NN";
            aku[indextodelete] = "NN";
        }
    }
    int jumlahtrufku = 0;
    REP(i,n){
        if(aku[i][1] == truf) jumlahtrufku++;
    }
    int jumlahtrufsibujang = 0;
    REP(i,m){
        if(lawan[i][1] == truf) jumlahtrufsibujang++; 
    }
    if(jumlahtrufsibujang != 0 || (jumlahtrufku < unmatched)){
        cout << "TIDAK" << endl;
    }
    else cout << "YA" << endl;


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    cin >> test;
    while(test--){
       solve();
    }
    return 0;
}