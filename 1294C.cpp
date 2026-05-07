    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define REP(i,n) for(int i = 0;i<n;i++)
    
    void solve() {
        int n; cin >> n;
        set<int> a;
        for(int i = 2; i*i <= n; i++){
            if(n%i==0){
                a.insert(i);
                n/=i;
            }
            if(a.size() == 2){
                a.insert(n);
                break;
            }
        }
        if(a.count(1) || a.size() != 3){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
            for(auto it : a) cout << it << " ";
            cout << endl;
        }
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