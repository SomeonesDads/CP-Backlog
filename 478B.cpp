    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define REP(i,n) for(int i = 0;i<n;i++)
    
   
    void solve() {
        ll n, m; cin >> n >> m;
        ll minpair = 0, maxpair;
        ll nclass = n/m;
        ll plusones = n%m;
 
        ll maxclass = n - m + 1;

        minpair = (plusones*(nclass+1)*(nclass) + (m-plusones)*(nclass)*(nclass-1))/2;
        maxpair = maxclass*(maxclass-1)/2;
        cout << minpair << " " << maxpair;

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